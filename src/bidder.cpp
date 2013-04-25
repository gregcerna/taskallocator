#include "ros/ros.h"
#include "std_msgs/String.h"
#include "taskallocator/Request.h"
#include <math.h>


ros::NodeHandle n;

void bidOnTask(taskallocator::Instruction){


	ros::Publisher bidPub = n.advertise<taskallocator::Bid>("bids",1000);
}

void evaluateBids(taskallocator::Bid){


}

int main (int argc, char **argv){

	ros::init(argc, argv, "bidder", ros::init_options::AnonymousName);
	ros::Subscriber taskSub = n.subscribe<taskallocator::Instruction>("tasks", 1000, bidOnTask);
	ros::Subscriber bidSub = n.subscribe<taskallocator::Bid>("bids", 1000, evaluateBids);

	ros::spin();



	return 0;
}
