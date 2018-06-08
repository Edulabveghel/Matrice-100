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

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/Pose.h>
#include <tf/transform_datatypes.h>

#define QUEUE_SIZE 10

class LocationSimulator
{
public:
	LocationSimulator();
	void send_transform();
	void moveCallback(const geometry_msgs::Pose::ConstPtr&);
	geometry_msgs::Pose getCurrentPose();

private:
    ros::NodeHandle nh;
	ros::Subscriber move_sub;
	ros::Subscriber set_sub;
	geometry_msgs::Pose current_pose;
	tf::Quaternion makeQuad(geometry_msgs::Quaternion);
	void set_zero_pose();
	
};
