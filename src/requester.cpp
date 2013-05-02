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
	ros::Rate loop_rate(.1);

	srand(time(NULL));

	int count = 0;
	while(ros::ok()) {
		taskallocator::Request msg;
		msg.taskType = "goToPoint";
		msg.requestDevice = "robot";
		msg.startFloor = 1;
		msg.startX = rand()%20 ;
		msg.startY = rand()%20;
		msg.endFloor = 1;
		msg.endX = rand()%20;
		msg.endY = rand()%20;
		
		requester_pub.publish(msg);
		
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}
