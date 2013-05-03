#include "ros/ros.h"
#include "std_msgs/String.h"
#include "taskallocator/Request.h"
#include "taskallocator/Task.h"
#include "taskallocator/Instruction.h"
#include "taskallocator/Bid.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>

unsigned int robotID;

ros::Publisher bidPub;


taskallocator::Task latestTask;//task to bid on
std::vector<taskallocator::Bid> bidList;
bool auctionComplete = false;

taskallocator::Instruction currentInstr;//instruction currently being executed
std::queue<taskallocator::Instruction> instrQueue;
bool executing = false;

float totalQueueTime;
float instrTimeLeft;

float endOfQueueX;
float endOfQueueY;

unsigned int numRobots = 4;

float bidVal;


float getDistance (float startX, float startY, float endX, float endY){
  return sqrt(pow(endX-startX,2)+pow(endY-startY,2));
}
float getDistance(taskallocator::Instruction instr){
	return getDistance(instr.startX, instr.startY, instr.endX, instr.endY);
}

void bidOnTask(taskallocator::Task task){
	
	//bidOnTask is only called when a new task is made
	latestTask = task;
	bidList.clear();
	auctionComplete = false;	


	//right now, only handle a single goto
	taskallocator::Instruction instr = task.instructions[0];
	
	//we are using the MINIMAX bidding rule, or minimizing the longest
	//path length of the robots
	//aiming to spread out load across robots
	//usually gives task to robot with least workload

	//robot with shortest queue time and distance to new task
	//will win the auction because task distance is constant for all robots
	bidVal = totalQueueTime;
	bidVal += getDistance(endOfQueueX,endOfQueueY,instr.startX,instr.startY);
	bidVal += getDistance(instr);
	//sidenote - this is a VERY simplistic implementation. bidding rules
	//become MUCH more complex as you start adding multi-instruction tasks,
	//allowing the queue to be rearranged, incorporate human interaction, etc

	
	//create bid	
	taskallocator::Bid myBid;
	myBid.task = latestTask;
	myBid.ID = robotID;
	myBid.bidCost = bidVal;

	bidPub.publish(myBid);


}

void evaluateBids(taskallocator::Bid bid){
	
	//only put other robots' bids in bidList
	if(bid.ID != robotID){
		bidList.push_back(bid);
	}
	
	//if robot has received all bids
	if(bidList.size() == numRobots - 1 && !auctionComplete){
		
		bool iWin = true;
		auctionComplete = true;

		//lowest bid wins. robot only cares whether it wins or not
		for(unsigned int i = 0; i < bidList.size(); i++){
			if(bidList[i].bidCost < bidVal){
				iWin = false;
			}else if(bidList[i].bidCost == bidVal){
				iWin = robotID > bidList[i].ID;//tiebreaker, assumes all IDs unique
				//TODO implement robotIDs so they are *for sure* different
				//instead of just random and probable that they are different
			}
		}

		if(iWin){

			//create instruction to get from end of last task to beginning of new one
			taskallocator::Instruction getToNewTask;
			
			getToNewTask.reqsHumanHelp = false;
			getToNewTask.helpDescriptor = "";

			getToNewTask.startFloor = 1;
			getToNewTask.startX = endOfQueueX;
			getToNewTask.startY = endOfQueueY;
			
			getToNewTask.endFloor = 1;
			getToNewTask.endX = latestTask.instructions[0].startX;
			getToNewTask.endY = latestTask.instructions[0].startY;		

			instrQueue.push(getToNewTask);
			totalQueueTime += getDistance(getToNewTask); 
			
			endOfQueueX = getToNewTask.endX;
			endOfQueueY = getToNewTask.endY;
			
			//loop through all instructions in task
			for(unsigned int j = 0; j < latestTask.instructions.size();j++){
				
				taskallocator::Instruction instr = latestTask.instructions[j];
				instrQueue.push(instr);
				
				totalQueueTime += getDistance(instr);
			
				endOfQueueX = instr.endX;
				endOfQueueY = instr.endY;
			}

			ROS_INFO("\nI won task %d! My bid was %f.",latestTask.header.seq,bidVal);
			ROS_INFO("Total Queue Time - %f \n\n", totalQueueTime);
		}
		else{
			ROS_INFO("I lost task %d. My bid was %f.",latestTask.header.seq,bidVal);
			ROS_INFO("Total Queue Time - %f\n", totalQueueTime);
		}


	}


}

int main (int argc, char **argv){

	//AnonymousName allows multiple bidder nodes to be created simultaneously
	ros::init(argc, argv, "bidder", ros::init_options::AnonymousName);
	ros::NodeHandle n;	

	ros::Subscriber taskSub = n.subscribe<taskallocator::Task>("tasks", 1000, bidOnTask);
	ros::Subscriber bidSub = n.subscribe<taskallocator::Bid>("bids", 1000, evaluateBids);

	bidPub = n.advertise<taskallocator::Bid>("bids",1000);

	srand(time(NULL));//init random seed

	robotID = rand()%1000;//each robot has a random ID

	endOfQueueX = rand()%20;//represents random starting location
	endOfQueueY = rand()%20;

	ros::Rate loop_rate(1);

	//simulate execution
	while(ros::ok()){
		
		//wasnt doing anything before but there is a new task available
		if(!executing && instrQueue.size() > 0){
			executing = true;	
			currentInstr = instrQueue.front();
			instrQueue.pop();
			instrTimeLeft = getDistance(currentInstr);
		}

		
		if(instrTimeLeft > 0){
			//move 1 "unit" of space every second
			totalQueueTime -= 1;
			instrTimeLeft   -= 1;

		}//current task is done but there are tasks left
		else if(totalQueueTime > 0){
			
			float leftover = instrTimeLeft;// -1 < leftover < 0
			currentInstr = instrQueue.front();
			instrQueue.pop();
			instrTimeLeft = getDistance(currentInstr);
			instrTimeLeft -= leftover;
			
			ROS_INFO("Executing new task. %d tasks (%f seconds) left in queue.",
				instrQueue.size(),totalQueueTime);
		
		}//robot has finished all tasks
		else if(executing){
			totalQueueTime = 0;
			instrTimeLeft = 0;
			executing = false;
			ROS_INFO("All tasks finished!");
		}
		
		ros::spinOnce();
		loop_rate.sleep();

	}
	
	ros::spin();

	


	return 0;
}


