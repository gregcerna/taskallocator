#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "taskallocator/Request.h"
#include <math.h>
#include <queue>

queue<float> tasks;
float totalTime;


float getDistance (float startX, float startY, float endX, float endY)
{
  return sqrt(pow(endX-startX,2)+pow(endY-startY,2));


}
	
void processRequest(taskallocator::Request msg){
	ROS_INFO("Message type: %s",msg.taskType.c_str());
	ROS_INFO("Request device %s", msg.requestDevice.c_str());
	ROS_INFO("Start - (%f,%f) End - (%f,%f)",msg.startX, msg.startY, msg.endX, msg.endY);
	float distance =getDistance (msg.startX, msg.startY, msg.endX, msg.endY);
	totalTime+=distance;


}

int main (int argc, char **argv) {
	ros::init(argc, argv, "tasker");
	ros::NodeHandle n;
	unsigned int buffer = 1000;

	ros::Subscriber sub = n.subscribe<taskallocator::Request>("requests", buffer, processRequest);
	ros::spin();
	return 0;

}
