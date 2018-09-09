#pragma once


// ROS
#include <ros/ros.h>
#include <stdlib.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>


// STD
#include <string>

	/*
     *Class containing the Robot Motion Controller
     */

    class RobotMotionController
    {

    public:
        /*
         *Constructor.
         */
        RobotMotionController();

        /*
         * Destructor.
         */
        virtual ~RobotMotionController();

	void  Run();
	 

    private:
	void  estimate(); 
	
        void  publish();
         
        void  registerPublisher();
   

    private:

        ros::NodeHandle node_handler_;
        ros::Publisher  pub_vel_;
        ros::Publisher  pub_odom_;


	double x  = 0.0;
	double y  = 0.0;
	double th = 0.0;


	double vx;
	double vy;
	double vth;


	ros::Time current_time, last_time;


  	double 	steering_angle;
        int 	encoder_ticks;
        double  angular_velocity;
        double  wheel_radius = 0.2; 
        double  wheel_circunference;
        double  wheel_travel_distance;

    };


