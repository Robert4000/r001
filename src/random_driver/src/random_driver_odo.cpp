
//  Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity
//  Robert Banegas, 2018  
//

//  wheel_circunference = 2 * wheel_radius * 3.14;
//  wheel_travel_distance = wheel_circunference  * ( ticks / ticks_per_revolution )


//  wheel_travel_distance  -> hypotenuse
//  x 			   -> adjacent
//  y 			   -> opposite

//  x =  wheel_travel_distance * cos ( steering_angle )
//  y =  wheel_travel_distance * sin ( steering_angle )

//  velocities
//  vx  *= 10;  // Adjust vx velocity/s at a 10Hz loop
//  vy  *= 10;  // Adjust vy velocity/s at a 10Hz loop
//  vth  =      // From the Gyro 


//  Compute odometry  given the velocities of the robot  



#include <ros/ros.h>
#include <stdlib.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>




int main(int argc, char **argv) 
{

	//Initializes ROS, and sets up a node

	ros::init(argc, argv, "random_driver");

	ros::NodeHandle n;

	//Ceates the publisher, and tells it to publish

	ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
	//tf::TransformBroadcaster odom_broadcaster;

	//Sets up the random number generator
	srand(time(0));


	double x  = 0.0;
	double y  = 0.0;
	double th = 0.0;


	double vx;
	double vy;
	double vth;


	ros::Time current_time, last_time;
	current_time 	= ros::Time::now();
	last_time 	= ros::Time::now();


        // TODO. create a robot object from stdr_robot.h
  	double 	steering_angle;
        int 	encoder_ticks;
        double  angular_velocity;
        double  wheel_radius = 0.2; 
        double  wheel_circunference;
        double  wheel_travel_distance;

	
	//Sets the loop to publish at a rate of 10Hz
	ros::Rate rate(10);


  	while(ros::ok()) 
	{

		ros::spinOnce();               // check for incoming messages
		current_time = ros::Time::now();

		// Get sensors data
                // TODO The following 3 lines are random simulated. Use ros subscribers and device drivers.   

                steering_angle		= int   ( rand() %  90  );  // 90 steering 
                encoder_ticks		= double( rand() %  512 );  // 512 ticks per evolution
 		angular_velocity	= double( rand() %  120 );  // imu gyro

		//  compute velocities of the robot
		wheel_circunference 	= 2 * wheel_radius * 3.14;
		wheel_travel_distance 	= wheel_circunference  * ( encoder_ticks / 512 );

		x =  wheel_travel_distance * cos ( steering_angle );
		y =  wheel_travel_distance * sin ( steering_angle );

		vx 	*= 10;  // Adjust vx velocity/s at a 10Hz loop or ( run this loop at 1HZ & remove 10 )
		vy 	*= 10;  // Adjust vy velocity/s at a 10Hz loop or ( run this loop at 1HZ & remove 10 )
		vth  	= angular_velocity; 


		//compute odometry given the velocities of the robot
		double dt 	=  ( current_time - last_time ).toSec();
		double delta_x 	=  ( vx * cos (th) - vy * sin (th) ) * dt;
		double delta_y 	=  ( vx * sin (th) + vy * cos (th) ) * dt;
		double delta_th =  vth * dt;

		x 	+= delta_x;
		y 	+= delta_y;
		th 	+= delta_th;


		//since all odometry is 6DOF we'll need a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw( th );

		//publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp 		= current_time;
		odom_trans.header.frame_id 		= "odom";
		odom_trans.child_frame_id 		= "base_link";

		odom_trans.transform.translation.x 	= x;
		odom_trans.transform.translation.y 	= y;
		odom_trans.transform.translation.z 	= 0.0;
		odom_trans.transform.rotation 		= odom_quat;


		//send the transform
		//odom_broadcaster.sendTransform( odom_trans );  


		nav_msgs::Odometry odom;
		odom.header.stamp 		= ros::Time::now();
		odom.header.frame_id 		= "odom";


		//set the position
		odom.pose.pose.position.x 	= x;
		odom.pose.pose.position.y 	= y;
		odom.pose.pose.position.z 	= 0.0;
		odom.pose.pose.orientation 	= odom_quat;


		//set the velocity
		odom.child_frame_id 		= "base_link";
		odom.twist.twist.linear.x 	= vx;
		odom.twist.twist.linear.y 	= vy;
		odom.twist.twist.angular.z 	= vth;


		//publish the message
		odom_pub.publish(odom);

		//Delays until it is time to send another message
		rate.sleep();
	}
}







