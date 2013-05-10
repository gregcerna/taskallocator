HOW TO USE

The nodes can technically be started in any order, but this is my preferred order. It is important to start the requester node last if you want all tasks to be bid on. This is because tasks can only be successfully be auctioned off if all bidder nodes are running.

1. start roscore - roscore

2. start tasker node - rosrun taskallocator tasker

3. start bidder nodes - rosrun taskallocator bidder. There should be a bidder node for each "robot" that will be accepting tasks. Bidder nodes currently don't need to be run on robots as they simulate execution of tasks. The number of bidder nodes running needs to be >>EXACTLY<< the same as the numRobots variable in bidder.cpp (currently 4 at project submission). If there are less nodes than numRobots, no tasks will be awarded because the nodes do not try and figure out if they've won until they've received numRobots-1 bids (they ignore their own). If there are more nodes running than numRobots, the nodes will calculate whether or not they've won before they've received all the bids, possibly causing multiple robots to think that they've won the task.

4. start requester node LAST - rosrun taskallocator requester. This technically does not matter, but is strongly advised. If the requester is started before the bidder nodes, any tasks sent before a bidder node starts will not be received by it, preventing the other nodes from ever auctioning off that task. A new task will overwrite will clear any old task waiting to be auctioned, so the system will continue to work fine, but the task will be lost.

