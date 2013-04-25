#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "taskallocator/Request.h"
#include <string>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "requester");
	ros::NodeHandle n;
	ros::Publisher requester_pub = n.advertise<taskallocator::Request>("requests",1000);
	ros::Rate loop_rate(0.5);


	srand(time(NULL));

	

	int count = 0;
	while(ros::ok()) {
		taskallocator::Request msg;
		msg.taskType = "goToPoint";
		msg.requestDevice = "robot";
		msg.startFloor = 1;
		msg.startX = rand()%100 ;
		msg.startY = rand()%100;
		msg.endFloor = 1;
		msg.endX = rand()%100;
		msg.endY = rand()%100;
		
		requester_pub.publish(msg);
		
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}

	return 0;

}
