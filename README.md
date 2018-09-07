# Estimate the 2D pose of a robot

Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity.

Robert Banegas, 2018  


 Build  
 ========
 -  Use Ubuntu 16.04
 -  Use Ros Kinetic 
 -  Set  
    mkdir rosrover_ws 
    cd rosrover_ws
 
 -  Pull  
    git init
    git pull https://github.com/Robert4000/r001.git
     
 
 -  Build
    catkin_make
    source ~/rosrover_ws/devel/setup.bash



 Test
 ====
 
  - Execute the following commands on different terminals ( Use Ctrl-Shift-T )
  
  - Run Ros
    roscore
   
 - Run Publisher
    rosrun random_driver random_driver
 
 - Run Subscriber
    rostopic echo /odom
 
 - Run Ros Graph 
    rosrun rqt_graph rqt_graph
    
 
 
 References
 ==========
 - ros.org / Kinetic
 - ros.org / Robot_Localization. Fusing multiple sensors' data.
 - openslam.org 
 
 
 
  
 Vision
 =======
 - Google TensorFlow
 - Nvidia TensorRT
 - Visual Slam
 
 
 
 
