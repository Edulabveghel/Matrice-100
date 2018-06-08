
/*The MIT License (MIT)
 *
 * Copyright (c) 2017, Actemium
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

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Pose.h>
#include <tf/transform_datatypes.h>

#define QUEUE_SIZE 1
#define PI 3.141592
#define TO_RAD(angle) (angle / 180 * PI)

// Note: The drone sim node uses scanf functions to poll user input. The regular
// ros signal handlers calls ros::shutdown to terminate a process. This doesn't 
// terminate the scanf, therefor we use a custom signal handler to call exit.
void signal_handler(int signal)
{
	ROS_INFO("Drone_Sim: ros::shutdown is not sufficient, calling exit...");
	exit(1);
}

void setScanner(ros::Publisher* pub, bool scanning)
{
    std_msgs::Bool scan;
    scan.data = scanning;
    pub->publish(scan);
}

void publishPose(ros::Publisher* pub, float x, float y, float angle)
{
    // Set up quaternion
    tf::Quaternion q = tf::createQuaternionFromYaw(TO_RAD(angle));
    q = q.normalize();

    // Set up total pose
    geometry_msgs::Pose pose;
    pose.position.x = x;
    pose.position.y = y;
    pose.position.z = 0.0;
    pose.orientation.x = q.x();
    pose.orientation.y = q.y();
    pose.orientation.z = q.z();
    pose.orientation.w = q.w();
    pub->publish(pose);
}

int main(int argc, char *argv[])
{
    // Initialize Node and handles
    ros::init(argc, argv, "drone_sim_node", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    // Set custom signal handler for SIGINT
	signal(SIGINT, signal_handler);

    // Get scan_time
    int scan_time;
    nh_private.param<int>("scan_time", scan_time, 20);

    ros::Publisher toggle_pub = nh.advertise<std_msgs::Bool>("toggle_scanner", QUEUE_SIZE);
    ros::Publisher move_pub = nh.advertise<geometry_msgs::Pose>("move", QUEUE_SIZE);

    ros::Rate loop_rate(100);

    // Sleep until subscribers are available
    ROS_INFO("Waiting for subscribers...");
    while(toggle_pub.getNumSubscribers() == 0 || 
          move_pub.getNumSubscribers() == 0)
    {
        loop_rate.sleep();
    }     

    // Move and Scan
    // Note: Due to custom signal handler ros::ok is always true
    while(ros::ok())
    {
        // Start scan
        ROS_INFO("Scanning...");
        setScanner(&toggle_pub, true);

        // Wait while scaner is running
        ros::Time begin = ros::Time::now();
        while (ros::Time::now() < begin + ros::Duration(scan_time))
        {
            loop_rate.sleep();
        }

        // Stop scanner
        setScanner(&toggle_pub, false);
        ROS_INFO("Scan done!");

        // Move LIDAR
        bool done = false;
        while (!done)
        {
            ROS_INFO("Move the LIDAR without rotating it, then input the movement here:");
            float x, y, angle;
            ROS_INFO("How far did you move the LIDAR forward, in meters? (LED indicator is forward/positive)");
            scanf("%f", &x);
            ROS_INFO("How far did you move the LIDAR sideways, in meters? (Left side is positive)");
            //scanf("%f", &y);
            ROS_INFO("You can now rotate the LIDAR. How much did you rotate the lidar in degrees? (CCW is positive)");
            //scanf("%f", &angle);
            if(x != 0.0 || y != 0.0 || angle != 0.0)
            {
                publishPose(&move_pub, x, y, angle);
                done = true;
            }
            else
            {
                ROS_INFO("Given input was not valid!");
            }
        }
    }

    // Stop scanner
    setScanner(&toggle_pub, false);
}