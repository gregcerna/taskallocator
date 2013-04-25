#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "taskallocator/Request.h"
#include <string>


int main(int argc, char **argv) {
	ros::init(argc, argv, "requester");
	ros::NodeHandle n;
	ros::Publisher requester_pub = n.advertise<taskallocator::Request>("requests",1000);
	ros::Rate loop_rate(0.5);

	int count = 0;
	while(ros::ok()) {
		taskallocator::Request msg;
		msg.taskType = "goToPoint";
		msg.requestDevice = "robot";
		msg.startFloor = 3;
		msg.startX = count;
		msg.startY = count;
		msg.endFloor = 3;
		msg.endX = count + 1;
		msg.endY = count + 1;
		
		requester_pub.publish(msg);
		
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}

	return 0;

}
