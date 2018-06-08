
/*The MIT License (MIT)
 *
 * Copyright (c) 2018, Actemium
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <cstdio>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ros/ros.h"
#include "nav_msgs/GetMap.h"
#include "std_msgs/Bool.h"
#include "tf/transform_datatypes.h"
#include "tf/transform_broadcaster.h"
#include "tf2/LinearMath/Matrix3x3.h"

#define RATE        100
#define QUEUE_SIZE  1
#define IMAGE       ".pgm"
#define METADATA    ".yaml"

int height = 4;
std::string mapName;

/*
*   Write the occupancy grid to a file
*/
bool writeMap(const nav_msgs::OccupancyGridConstPtr& map, std::string fileName)
{
    FILE* out = fopen((fileName + IMAGE).c_str(), "w");
    if(!out)
    {
        ROS_ERROR("Mapper Couldn't save map file to %s", (fileName + IMAGE).c_str());
        return false;
    }

    fprintf(out, "P5\n# CREATOR: mapper_node %.3f m/pix\n%d %d\n255\n",
            map->info.resolution, map->info.width, map->info.height);

    for(unsigned int y = 0; y < map->info.height; y++)
    {
        for(unsigned int x = 0; x < map->info.width; x++)
        {
            unsigned int i = x + (map->info.height - y - 1) * map->info.width;
            if(map->data[i] == 0)
            {
                fputc(254, out);
            }
            else if(map->data[i] == +100)
            {
                fputc(000, out);
            }
            else
            {
                fputc(205, out);
            }
        }
    }

    fclose(out);
    return true;
}

/*
*   Write metadata to the corrisponding file
*/
bool writeMetaData(const nav_msgs::OccupancyGridConstPtr& map, std::string fileName)
{
    // Make a file for the meta data
    FILE* yaml = fopen((fileName + METADATA).c_str(), "w");

    if(!yaml)
    {
        ROS_ERROR("Mapper Couldn't save meta data file to %s", (fileName + METADATA).c_str());
        return false;
    }

    geometry_msgs::Quaternion orientation = map->info.origin.orientation;
    tf2::Matrix3x3 mat(tf2::Quaternion(orientation.x, 
                                    orientation.y, 
                                    orientation.z, 
                                    orientation.w));
    double yaw, pitch, roll;
    mat.getEulerYPR(yaw, pitch, roll);

    fprintf(yaml, "image: %s\nresolution: %f\norigin: [%f, %f, %f]\nnegate: 0\noccupied_thresh: 0.65\nfree_thresh: 0.196\n\n", 
            (std::to_string(height) + IMAGE).c_str(), map->info.resolution, map->info.origin.position.x, map->info.origin.position.y, yaw);

    fclose(yaml);
    return true;
}

void mapCallback(const nav_msgs::OccupancyGridConstPtr& map)
{   
    // Use the provided map name to create a directory
    std::string dirName = mapName;

    // Number the files inside the directory by scan height
    std::string fileName = dirName + "/" + std::to_string(height);

    struct stat st;
    if(stat(dirName.c_str(), &st) == -1)
    {
        mkdir(dirName.c_str(), S_IRWXU);
        ROS_INFO("Mapper Created Directory: %s", dirName.c_str());
    }

    // Write map data to file
    if(!writeMap(map, fileName))
        return;

    // Write meta data file
    if(!writeMetaData(map, fileName))
        return;
}

void setScanner(ros::Publisher* pub, bool scanning)
{
    std_msgs::Bool scan;
    scan.data = scanning;
    pub->publish(scan);
}

void setTransform(geometry_msgs::TransformStamped* ts, std::string parent, std::string child)
{
    // Generate a pseudo-random positive height between 0 and 1
    float h = fabsf(sin(ros::Time::now().toNSec()));

    ts->header.stamp = ros::Time::now();
    ts->header.frame_id = parent;
    ts->child_frame_id = child;
    ts->transform.translation.x = 0;
    ts->transform.translation.y = 0;
    ts->transform.translation.z = h;
    ts->transform.rotation.x = 0;
    ts->transform.rotation.y = 0;
    ts->transform.rotation.z = 0;
    ts->transform.rotation.w = 1;
}

int main(int argc, char *argv[])
{
    // Initialize Node and handles
    ros::init(argc, argv, "mapper_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    // Get toggle scanner topic
    std::string toggle_scanner;
    nh_private.param<std::string>("toggle_scanner", toggle_scanner, "toggle_scanner");

    // Get base_link frame
    std::string base_link;
    nh_private.param<std::string>("base_link", base_link, "base_link");

    // Get base_footprint frame
    std::string base_footprint;
    nh_private.param<std::string>("base_footprint", base_footprint, "base_footprint");

    // Get map topic
    std::string map_topic;
    nh_private.param<std::string>("map_topic", map_topic, "map");

    // Get map name
    nh_private.param<std::string>("map_file_name", mapName, std::to_string((int)ros::Time::now().toSec()));

    // toggle scanner publisher
    ros::Publisher toggle_pub = nh.advertise<std_msgs::Bool>(toggle_scanner, QUEUE_SIZE);

    // map subscriber, used to save the map to a file when available
    ros::Subscriber map = nh.subscribe(map_topic, 1, mapCallback);

    // Loop rate
    ros::Rate loop_rate(RATE);

    // Sleep until subscribers are available
    ROS_INFO("Mapper Waiting for subscribers...");
    while(toggle_pub.getNumSubscribers() == 0 && ros::ok())
    {
        loop_rate.sleep();
    }     

    // Start scanning
    ROS_INFO("Mapper DONE! Started scanning...");
    setScanner(&toggle_pub, true);

    // Broadcast the transform from base_link to base_footprint
    while(ros::ok())
    {
        static tf2_ros::TransformBroadcaster bc;

        // Make and broadcast transform
        geometry_msgs::TransformStamped ts;
        setTransform(&ts, base_footprint, base_link);
        bc.sendTransform(ts);

        ros::spinOnce();
        loop_rate.sleep();
    }

    // Stop scanner
    setScanner(&toggle_pub, false);
}