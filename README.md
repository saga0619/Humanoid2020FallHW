# DYROS JET Repository 

* This is a DYROS JET Humanoid Repository FOR Ubuntu 20.04

## How do I get set up? ##

```sh
sudo apt-get install ros-noetic-realtime-tools 
cd ~/catkin_ws/src
git clone https://github.com/saga0619/mujoco_ros_sim.git
```

### RBDL Setup ###
```sh
git clone --recursive https://github.com/saga0619/rbdl-orb
mkdir build
cd build
make all
sudo make install
```

### How do I run the simulation? ###
### Mujoco Update (19/01/31) ###
* mujoco_ros - [MUJOCO_ROS_SIM](https://github.com/saga0619/mujoco_ros_sim)

* GUI
```sh
rosrun dyros_jet_gui dyros_jet_gui
```
* roslaunch
```sh
roslaunch dyros_jet_launch mujoco.launch
```

### How do I contribuite to this repo? ###
* Read this http://wiki.ros.org/CppStyleGuide

