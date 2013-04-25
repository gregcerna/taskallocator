#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "taskallocator/Request.h"
#include <math.h>
#include <queue>
#include <iostream>


std::queue<float> tasks;
float totalTime;


float getDistance (float startX, float startY, float endX, float endY){
  return sqrt(pow(endX-startX,2)+pow(endY-startY,2));
}
	
void processRequest(taskallocator::Request msg){
	
	float distance =getDistance (msg.startX, msg.startY, msg.endX, msg.endY);

	tasks.push(distance);
	totalTime+=distance;

	ROS_INFO("Message type: %s",msg.taskType.c_str());
	ROS_INFO("Request device %s", msg.requestDevice.c_str());
	ROS_INFO("Distance - %f ",distance);
	ROS_INFO("Total Time - %f",totalTime);
	ROS_INFO("Total Tasks - %d",(int)tasks.size());
}

int main (int argc, char **argv) {

	ros::init(argc, argv, "tasker");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe<taskallocator::Request>("requests", 1000, processRequest);
	ros::spin();
	return 0;

}
