


#include <ros/ros.h>

#include "../include/RobotMotionController.hpp"



int main(int argc, char** argv)
{

 //Initializes ROS, and sets up a node

 
  ros::init(argc, argv, "robot_motion_controller");

  
  RobotMotionController controller = RobotMotionController();

  controller.Run();

  
   return 0;
}




