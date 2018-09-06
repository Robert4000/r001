# r001

Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity
Robert Banegas, 2018  


 BUILD  
 =====
  #  Use an Ubuntu 16.04 machine
  #  Install Ros Kinetic
  #  Create rosrover_ws directory & pull this git
    -  mkdir rosrover_ws 
    -  cd rosrover_ws
    -  git init
    -  git pull https://github.com/Robert4000/r001.git
     

 TEST
 ====
 - Execute the following commands on different terminals ( Use Ctrl-Shift-T )
  
 # run ros kinetic
    roscore
 
 # build the project
    cd rosrover_ws
    catkin_make
    source ~/rosrover_ws/devel/setup.bash
 
 # Run the ros publisher that computes and broadcast the 2D pose values
    rosrun random_driver random_driver
 
 # Run the ros subscriber that reads and shows the 2D pose values
    rostopic echo /odom
 
 # Run the ros computation graph 
    rosrun rqt_graph rqt_graph
    
 
 
 REFERENCES
 ==========
 ROS.ORG Kinetic
 OPENSLAM.ORG slam
 
  
 VISION
 ======
 GOOGLE TensorFlow
 NVIDIA TensorRT
 Visual slam 
 
 
 
