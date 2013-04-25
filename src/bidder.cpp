#include "ros/ros.h"
#include "std_msgs/String.h"
#include "taskallocator/Request.h"
#include "taskallocator/Instruction.h"
#include "taskallocator/Bid.h"
#include <math.h>
#include <queue>
//TODO bernadine dias auction based task allocation 
//TODO contract nets
ros::NodeHandle n;

float currentX;
float currentY;

std::queue<taskallocator::Instruction> InstrQueue;

float totalQueueTime;

float endOfQueueX;
float endOfQueueY;

int numRobots;
float bid;


float getDistance (float startX, float startY, float endX, float endY){
  return sqrt(pow(endX-startX,2)+pow(endY-startY,2));
}

void bidOnTask(taskallocator::Instruction instr){
	
	//bid equal to totalQueueTime + distanceBetween(endOfQueueLoc, Instr.startLoc) + 
	//distanceBetween(Instr.startLoc, Instr.endLoc)

	bid = 0;
	bid += totalQueueTime;
	bid += getDistance(endOfQueueX,endOfQueueY,instr.startX,instr.startY);
	bid += getDistance(instr.startX,instr.startY,instr.endX,instr.endY);

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


