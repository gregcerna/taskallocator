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
//TODO bernadine dias auction based task allocation 
//TODO contract nets
//TODO wolfstetter [4] single item auction theory

unsigned int robotID;


ros::Publisher bidPub;

taskallocator::Task latestTask;
taskallocator::Instruction currentInstr;
bool executing = false;
std::queue<taskallocator::Instruction> instrQueue;

std::vector<taskallocator::Bid> bidList;

float totalQueueTime;
float instrTimeLeft;

float endOfQueueX = rand()%20;//initialize starting location
float endOfQueueY = rand()%20;//to random values

unsigned int numRobots = 4;

float bidVal;


float getDistance (float startX, float startY, float endX, float endY){
  return sqrt(pow(endX-startX,2)+pow(endY-startY,2));
}

void bidOnTask(taskallocator::Task task){
	
	//bidOnTask is only called when a new task is made
	latestTask = task;
	bidList.clear();

	//right now, only handle a single goto
	taskallocator::Instruction instr = task.instructions[0];
	
	//we are using the MINSUM bidding rule, or minimizing the sum
	//of all the path lengths of the robots
	//aiming to add the LEAST distance to total robot path length

	//robot with least distance between end point of queue and start point
	//will win the auction because the task distance is fixed
	bidVal = 0;
	bidVal = getDistance(endOfQueueX,endOfQueueY,instr.startX,instr.startY);
	
	//sidenote - this is a VERY simplistic implementation. bidding rules
	//become MUCH more complex as you start adding multi-instruction tasks,
	//allowing the queue to be rearranged, incorporate human interaction, etc

	
	
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
	if(bidList.size() == numRobots - 1){
		
		bool iWin = true;
		
		//lowest bid wins. robot only cares whether it wins or not
		for(unsigned int i = 0; i < bidList.size(); i++){
			if(bidList[i].bidCost < bidVal){
				iWin = false;
			}
		}

		if(iWin){

			//instruction to get from end of last task to beginning of new one
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
			totalQueueTime += bidVal; //equivalent to getToNewTask distance
			
			endOfQueueX = getToNewTask.endX;
			endOfQueueY = getToNewTask.endY;
			
			//loop through all instructions in task
			for(unsigned int j = 0; j < latestTask.instructions.size();j++){
				
				taskallocator::Instruction instr = latestTask.instructions[j];
				instrQueue.push(instr);
				
				totalQueueTime += getDistance(instr.startX, instr.startY,
							instr.endX, instr.endY);
			
				endOfQueueX = instr.endX;
				endOfQueueY = instr.endY;
			}

			ROS_INFO("\nI, Robot %d, won! My bid was %f.",robotID,bidVal);
			ROS_INFO("Total Queue Time - %f \n\n", totalQueueTime);
		}
		else{
			ROS_INFO("I, Robot %d, lost :( My bid was %f.",robotID,bidVal);
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

	srand(time(NULL));
	robotID = rand()%1000;//each robot has a random ID

	ros::Rate loop_rate(1);

	//simulate execution
	while(ros::ok()){
		
		//wasnt doing anything before but there is a new task available
		if(!executing && instrQueue.size() > 0){
			executing = true;	
			currentInstr = instrQueue.front();
			instrQueue.pop();
			instrTimeLeft = getDistance(currentInstr.startX, currentInstr.startY,
						currentInstr.endX, currentInstr.endY);
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
			instrTimeLeft = getDistance(currentInstr.startX, currentInstr.startY,
						currentInstr.endX, currentInstr.endY);
			instrTimeLeft -= leftover;
			
			ROS_INFO("Task finished! %d tasks (%f seconds) to go.",
				instrQueue.size()+1,totalQueueTime);
		
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


