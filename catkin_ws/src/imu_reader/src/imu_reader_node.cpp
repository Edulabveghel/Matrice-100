
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

#include "stdio.h"
#include "ctime"

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Vector3.h>

#include "tf/transform_datatypes.h"

#define GRAVITY 		9.81
#define QUEUE_SIZE 		5
#define PI 				3.141592
#define TO_RAD(angle) 	(angle / 180 * PI) // should not be needed since the rotations are in rad/sec

float lp = 0;
float hp = 0;

// Parameters (TODO: But in param file)
float zero_velocity = 0.1;
float zero_acceleration = 1;
float zero_rotation = 0.3; // about 17 degrees rotation

float getVectorLength(geometry_msgs::Vector3 v)
{
	float sum = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	float sqrt = std::sqrt(sum);
	return sqrt;
}

/*
*	Note: This is a temporary test function, not to be included in the final build
*/
void accelerationMagic(geometry_msgs::Vector3* linear_acceleration, geometry_msgs::Vector3 velocity)
{
	if(getVectorLength(*linear_acceleration) < zero_acceleration)
	{
		linear_acceleration->x = 0;
		linear_acceleration->y = 0;
		linear_acceleration->z = 0;
	}
}

/*
*	Note: This is a temporary test function, not to be included in the final build
*/
void velocityMagic(geometry_msgs::Vector3* velocity, geometry_msgs::Vector3 acceleration)
{
	if(getVectorLength(*velocity) < zero_velocity)
	{
		velocity->x = 0;
		velocity->y = 0;
		velocity->z = 0;
	}
	/*if(fabsf(velocity->x) < zero_velocity)
		velocity->x = 0;
	if(fabsf(velocity->y) < zero_velocity)
		velocity->y = 0;
	if(fabsf(velocity->z) < zero_velocity)
		velocity->z = 0;*/
}


/*
*	Velocity = Time * Acceleration
*/
void calculateNewVelocity(geometry_msgs::Vector3* velocity, geometry_msgs::Vector3 linear_acceleration, float deltaTime)
{
	velocity->x += deltaTime * linear_acceleration.x;
	velocity->y += deltaTime * linear_acceleration.y;
	velocity->z += deltaTime * linear_acceleration.z;
}

/*
*	Position = Time * Velocity
*/
void calculateNewPosition(geometry_msgs::Pose* pose, geometry_msgs::Vector3 velocity, float deltaTime)
{
	pose->position.x += deltaTime * velocity.x;
	pose->position.y += deltaTime * velocity.y;
	pose->position.z += deltaTime * velocity.z;
}

/*
*	Get Roll Pitch Yaw from a tf Quaternion and store them in a geometry_msgs vector
*/
geometry_msgs::Vector3 getRPY(geometry_msgs::Quaternion q)
{
	geometry_msgs::Vector3 rpy;
	tf::Matrix3x3(tf::Quaternion(q.x, q.y, q.z, q.w)).getRPY(rpy.x, rpy.y, rpy.z);
	return rpy;
}

//void writeRPYtoLog( geometry_msgs::Pose poseIn, FILE* pFile){
/*
void writeRPYtoLog( geometry_msgs::Pose poseIn)
{
	FILE* pFile = fopen("/home/ubuntu/imu_bagfiles/RPY.txt" , "a");
	fprintf(pFile, "Roll, Pitch and Yaw: r: %.5f p: %.5f y: %.5f \n", poseIn.orientation.x, poseIn.orientation.y, poseIn.orientation.z);
	fclose(pFile);
}

*/
///
/*
*	This callback is called every time new imu data is available
*/
//void imuCallback(const sensor_msgs::Imu::ConstPtr& msg, std::string path)
void imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
	// Variables to keep between callbacks
	static geometry_msgs::Pose pose;
	static geometry_msgs::Vector3 velocity;
	static ros::Time prev_time;

	// One time variables
	geometry_msgs::Vector3 acceleration = msg->linear_acceleration;
	ros::Time now = ros::Time::now();

	// First time setup
	if (prev_time.toSec() == 0)
	{
		ROS_INFO("setup");
		prev_time = ros::Time::now();
		return;
	}

	// Calculate elapsed time in seconds
	float timePassed = ros::Duration(now - prev_time).toSec();
	
	// Error catching
	if (timePassed < 0)
		return;
	else
		prev_time = now;

	// store the orientation in a msg
	geometry_msgs::Vector3 RPY = getRPY(msg->orientation);


	// TODO: Acceleration magic
	accelerationMagic(&acceleration, velocity);

	// Calculate new velocity
	calculateNewVelocity(&velocity, acceleration, timePassed);

	// TODO: Magic to make it work
	velocityMagic(&velocity, acceleration);

	// Calculate new position
	calculateNewPosition(&pose, velocity, timePassed);

	// Set new orientation
	pose.orientation = msg->orientation;

	if(pose.position.z < lp)
	{
		lp = pose.position.z;
	}

	if(pose.position.z > hp)
	{
		hp = pose.position.z;
	}

	// Code made by Tim:
	// ROS_INFO("%.3f <- %.3f -> %.3f | %.3f %.3f", lp, pose.position.z, hp, getVectorLength(velocity), getVectorLength(acceleration));
	
	// Display current orientation
	ROS_INFO("Roll, Pitch and Yaw: r: %.5f p: %.5f y: %.5f", pose.orientation.x, pose.orientation.y, pose.orientation.z);
	//writeRPYtoLog(pose, FILE* pFile = fopen(path , "a"););

	//ROS_INFO("%f %f %f", velocity.x, velocity.y, velocity.z);
	//ROS_INFO("%f %f %f", msg->linear_acceleration.x / 9.81, msg->linear_acceleration.y / 9.81, msg->linear_acceleration.z / 9.81);
	//ROS_INFO("%f, %f, %f, %f", pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w);
}

/*
*	Main loop
*/
int main(int argc, char *argv[])
{
		//TODO: make this into an init method
    // Initialize Node and handles
		//std::time_t t = std::time(0); //get time now
	//	std::tm* now = std::localtime(&t);
	//	std::string currentTime = (now->tm_mon + 1) + "-" + now->tm_mday + "\n");
	//	std::string path = "/home/ubuntu/imu_bagfiles/RPY-" + currentTime + ".txt");	

    ros::init(argc, argv, "imu_reader_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");     

    // Subscribe to the imu data
    ros::Subscriber sub = nh.subscribe("/dji_sdk/imu", QUEUE_SIZE, imuCallback);
    //ros::Subscriber sub = nh.subscribe("/dji_sdk/imu", QUEUE_SIZE, imuCallback(path);
    
		ros::spin();
}
