# R001 - COMPUTE THE 2D POSE OF A ROBOT

Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity.

Robert Banegas, 2018  


 A. BUILD  
 ========
 #  Use Ubuntu 16.04
 #  Use Ros Kinetic 
 #  Set  
    -  mkdir rosrover_ws 
    -  cd rosrover_ws
 
 #  Pull  
    -  git init
    -  git pull https://github.com/Robert4000/r001.git
     
 
 #  Build
    catkin_make
    source ~/rosrover_ws/devel/setup.bash



 B. TEST
 =======
 - Execute the following commands on different terminals ( Use Ctrl-Shift-T )
  
 
 # Run Ros
    roscore
   
 # Run Publisher
    rosrun random_driver random_driver
 
 # Run Subscriber
    rostopic echo /odom
 
 # Run Ros Graph 
    rosrun rqt_graph rqt_graph
    
 
 
 C. REFERENCES
 ==============
 ROS.ORG / Kinetic
 
 ROS.ORG / Robot_Localization. Fusing multiple sensors' data.
 
 OPENSLAM.ORG 
 
 
 
  
 D. VISION
 ========
 GOOGLE TensorFlow

 NVIDIA TensorRT

 VISUAL Slam
 
 
 
 
