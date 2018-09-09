
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




#include "../include/RobotMotionController.hpp"



#include <cmath>




    RobotMotionController::RobotMotionController() 
        

    {


        registerPublisher(); 



        ROS_INFO("robot_motion_controller node launched.");

    }

    RobotMotionController::~RobotMotionController()
    {
    }
    



    void RobotMotionController::registerPublisher()
    {
	// Publisher for the Husky Robot Gazebo
        pub_vel_    =     node_handler_.advertise< geometry_msgs::Twist>("/husky_velocity_controller/cmd_vel", 10); 

	// Publisher for the topic odom.
        pub_odom_   =     node_handler_.advertise< nav_msgs::Odometry>("odom", 50);
    }



  void RobotMotionController::estimate()
  { 
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



	}



 	void RobotMotionController::publish()
       {

		geometry_msgs::Twist msg;

		    msg.linear.x = vx;
                    msg.linear.y = vy;
		    msg.angular.z = vth;

		// Publish the Velocities.  For testing with Husky Gazebo
		 pub_vel_.publish(msg);




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



 		//Publish the Pose to the topic odom. Test it with the terminal
		pub_odom_.publish( odom );


       }	



  void RobotMotionController::Run()
  
  {

	//Sets up the random number generator
	srand(time(0));

	current_time 	= ros::Time::now();
	last_time 	= ros::Time::now();

	
	//Sets the loop to publish at a rate of 10Hz
	ros::Rate rate(10);


  	while(ros::ok()) 
	{

		estimate();

                publish();


		//Delays until it is time to send another message
		rate.sleep();
	}
}




