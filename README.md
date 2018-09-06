# R001 - COMPUTE THE 2D POSE OF A ROBOT

Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity.

Robert Banegas, 2018  


 A. BUILD  
 ========
 #  Use an Ubuntu 16.04 machine
 #  Install Ros.org / Kinetic
 #  Set the rosrover_ws directory name to avoid catkin_make building errors. 
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
  
 
 # run ros kinetic
    roscore
   
 # Run the ros publisher that computes and broadcast the 2D pose values
    rosrun random_driver random_driver
 
 # Run the ros subscriber that reads and shows the 2D pose values
    rostopic echo /odom
 
 # Run the ros computation graph 
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
 
 
 
 
