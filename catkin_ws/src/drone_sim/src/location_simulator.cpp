
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

#include "drone_sim/location_simulator.h"

LocationSimulator::LocationSimulator()
{
    move_sub = nh.subscribe("move", QUEUE_SIZE, &LocationSimulator::moveCallback, this);
    set_zero_pose();
}

geometry_msgs::Pose LocationSimulator::getCurrentPose()
{
    return current_pose;
}

tf::Quaternion LocationSimulator::makeQuad(geometry_msgs::Quaternion orientation)
{
    tf::Quaternion q(orientation.x,
                            orientation.y,
                            orientation.z,
                            orientation.w);
    return q;
}

// Add movement to current pose
void LocationSimulator::moveCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
    ROS_INFO("MOVE CALLBACK!");
    current_pose.position.x += msg->position.x;
    current_pose.position.y += msg->position.y;
    current_pose.position.z += msg->position.z;

    tf::Quaternion q = makeQuad(msg->orientation) * makeQuad(current_pose.orientation);
    q = q.normalize();

    current_pose.orientation.x = q.x();
    current_pose.orientation.y = q.y();
    current_pose.orientation.z = q.z();
    current_pose.orientation.w = q.w();
}

// Ensure the pose is reset.
void LocationSimulator::set_zero_pose()
{
    ROS_INFO("SET ZERO POSE");
	current_pose.position.x = 0.0;
	current_pose.position.y = 0.0;
	current_pose.position.z = 0.0;
	current_pose.orientation.x = 0.0;
	current_pose.orientation.y = 0.0;
	current_pose.orientation.z = 0.0;
	current_pose.orientation.w = 1.0;
}

// Broadcast pose on TF
void LocationSimulator::send_transform()
{
    static tf2_ros::TransformBroadcaster bc;
    geometry_msgs::TransformStamped ts;

    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "odom";
    ts.child_frame_id = "base_link";
    ts.transform.translation.x = current_pose.position.x;
    ts.transform.translation.y = current_pose.position.y;
    ts.transform.translation.z = current_pose.position.z;
    ts.transform.rotation.x = current_pose.orientation.x;
    ts.transform.rotation.y = current_pose.orientation.y;
    ts.transform.rotation.z = current_pose.orientation.z;
    ts.transform.rotation.w = current_pose.orientation.w;
    bc.sendTransform(ts);
}