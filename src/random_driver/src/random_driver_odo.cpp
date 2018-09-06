#include <ros/ros.h>
//#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

// odo - random values

int main(int argc, char **argv) {

//Initializes ROS, and sets up a node

ros::init(argc, argv, "random_driver");

ros::NodeHandle n;

//Ceates the publisher, and tells it to publish
//to the husky_velocity_controller/cmd_vel topic, with a queue size of 100
//ros::Publisher pub=n.advertise<geometry_msgs::Twist>("husky_velocity_controller/cmd_vel", 100);

ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
//tf::TransformBroadcaster odom_broadcaster;

//Sets up the random number generator
srand(time(0));


//Sets the loop to publish at a rate of 10Hz
ros::Rate rate(10);

  while(ros::ok()) {
    //Declares the message to be sent
  //  geometry_msgs::Twist msg;
    //Random x value between -2 and 2
   // msg.linear.x=4*double(rand())/double(RAND_MAX)-2;
    //Random z value between -3 and 3
   // msg.angular.z=6*double(rand())/double(RAND_MAX)-3;
    //Publish the message
   /// pub.publish(msg);




       nav_msgs::Odometry odom;
       odom.header.stamp = ros::Time::now();
       odom.header.frame_id = "odom";
   
       //set the position
       odom.pose.pose.position.x = 4*double(rand())/double(RAND_MAX)-2;;
       odom.pose.pose.position.y = 6*double(rand())/double(RAND_MAX)-2;;
       odom.pose.pose.position.z = 0.0;
       odom.pose.pose.orientation =  tf::createQuaternionMsgFromYaw(4*double(rand())/double(RAND_MAX)-2);
   
       //set the velocity
       odom.child_frame_id = "base_link";
       odom.twist.twist.linear.x = 4*double(rand())/double(RAND_MAX)-2;
    //   odom.twist.twist.linear.y = 0.0;
       odom.twist.twist.angular.z = 6*double(rand())/double(RAND_MAX)-3;

	//publish the message
        odom_pub.publish(odom);

    //Delays until it is time to send another message
    rate.sleep();
    }
}


///
///

//  wheel_circunference = 2 * wheel_radius * 3.14;
//  wheel_travel_distance = wheel_circunference  * ( ticks / ticks_per_revolution )

//  wheel_turning_distance =  steering_wheel_turn_angle * wheel_travel_distance
//  x = -wheel_turning_distance * sin ( steering_wheel_turn_angle )
//  y =  wheel_turning_distance * cos ( steering_wheel_turn_angle )

//  xv *= 10;  // Adjust x velocity/s at 10Hz
//  yv *= 10;  // Adjust y velocity/s at 10Hz
//  zv  = zv   // Merge from the Gyro 

//  Compute odometry in a typical way given the velocities of the robot  



