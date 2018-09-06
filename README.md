# r001

Compute 2d pose of the robot based on the wheel encoder, steering wheel angle and imu angular velocity
Robert Banegas, 2018  


 Build  
 =====
  #  Use an Ubuntu 16.04 machine
  #  Install Ros Kinetic
  #  Create rosrover_ws directory & pull this git
    -  mkdir rosrover_ws 
    -  cd rosrover_ws
    -  git init
    -  git pull https://github.com/Robert4000/r001.git
     

 Test
 ====
 - Execute the following commands on different terminals ( Use Ctrl-Shift-T )
  
 # run ros kinetic
    roscore
 
 # build the project
    cd rosrover_ws
    catkin_make
 
 # Run the ros publisher
    rosrun random_driver random_driver
 
 # Run the ros subscriber
    rostopic echo /odom
 
 # Run the ros computation graph 
    rosrun rqt_graph rqt_graph
    
    
