
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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Vector3.h>

#include "tf/transform_datatypes.h"

#define GRAVITY 		9.81
#define QUEUE_SIZE 		5
#define PI 				3.141592
#define TO_RAD(angle) 	(angle / 180 * PI)

float lp = 0;
float hp = 0;

// Parameters (TODO: But in param file)
float zero_velocity = 0.1;
float zero_acceleration = 1;

/*
*	Calculate the length of a 3D vector
*/
float getVectorLength(geometry_msgs::Vector3 v)
{
	float sum = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	float sqrt = std::sqrt(sum);
	return sqrt;
}

/* 
*	displacement = velocity * time + 0.5 * acceleration * time^2 
*/
float distanceChange(float v, float t, float a)
{
	return (v * t) + (0.5f * a * t * t);
}

/* 
*	velocity = acceleration * time 
*/
float velocityChange(float t, float a)
{
	return a * t;
}

/* 
*	Calculate new position for all 3 directions 
*/
void calculateNewPosition(geometry_msgs::Pose* pose,
							  geometry_msgs::Vector3 velocity,
							  geometry_msgs::Vector3 linear_acceleration,
							  float deltaTime)
{
	pose->position.x += distanceChange(velocity.x, deltaTime, linear_acceleration.x);	
	pose->position.y += distanceChange(velocity.y, deltaTime, linear_acceleration.y);		
	pose->position.z += distanceChange(velocity.z, deltaTime, linear_acceleration.z);	
}

/* 
*	Calculate new velocity in all 3 directions 
*/
void calculateNewVelocity(geometry_msgs::Vector3* velocity,
							  geometry_msgs::Vector3 linear_acceleration,
							  float deltaTime)
{
	velocity->x += velocityChange(linear_acceleration.x, deltaTime);
	velocity->y += velocityChange(linear_acceleration.y, deltaTime);
	velocity->z += velocityChange(linear_acceleration.z, deltaTime);
}

/*
*	Get Roll Pitch Yaw from a tf Quaternion and store them in a geometry_msgs vector3
*/
geometry_msgs::Vector3 getRPY(geometry_msgs::Quaternion q)
{
	geometry_msgs::Vector3 rpy;
	tf::Matrix3x3(tf::Quaternion(q.x, q.y, q.z, q.w)).getRPY(rpy.x, rpy.y, rpy.z);
	return rpy;
}

/*
*	This callback is called every time new imu data is available
*/
void imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
	// Variables to keep between callbacks
	static geometry_msgs::Pose pose;
	static geometry_msgs::Vector3 velocity;
	static ros::Time prev_time;

	// One time variables
	geometry_msgs::Vector3 acceleration = msg->linear_acceleration;
	ros::Time now = msg->header.stamp;

	// First time setup
	if (prev_time.toSec() == 0)
	{
		ROS_INFO("setup");
		prev_time = msg->header.stamp;
		return;
	}

	// Calculate elapsed time in seconds
	float timePassed = ros::Duration(now - prev_time).toSec();
	
	// Error catching
	if (timePassed < 0)
		return;
	else
		prev_time = now;

	geometry_msgs::Vector3 RPY = getRPY(msg->orientation);

	calculateNewPosition(&pose, velocity, msg->linear_acceleration, timePassed);

	calculateNewVelocity(&velocity, msg->linear_acceleration, timePassed);

	// Set new orientation
	pose.orientation = msg->orientation;
	
	// Display current position
	ROS_INFO("x: %.3f y:%.3f z: %.3f", pose.position.x, pose.position.y, pose.position.z);
	//ROS_INFO("%f %f %f", velocity.x, velocity.y, velocity.z);
	//ROS_INFO("%f %f %f", msg->linear_acceleration.x, msg->linear_acceleration.y, msg->linear_acceleration.z);
	//ROS_INFO("x: %.3f y:%.3f z: %.3f", RPY.x, RPY.y, RPY.z);
}

/*
*	Main loop
*/
int main(int argc, char *argv[])
{
    // Initialize Node and handles
    ros::init(argc, argv, "imu_reader_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");     

    // Subscribe to the imu data
    ros::Subscriber sub = nh.subscribe("/dji_sdk/imu", QUEUE_SIZE, imuCallback);

    ros::spin();
}