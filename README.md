# DYROS JET Repository 

* This is a DYROS JET Humanoid Repository FOR Ubuntu 20.04
* Remove real-robot components. (imu & dynamixel..)
* Remove v-rep components.
* Migrate qt4 to qt5 for GUI

## How do I get set up? ##



* 1. Install ros-noetic-realtime-tools and qtbase5-private-dev
```sh
sudo apt-get install ros-noetic-realtime-tools qtbase5-private-dev
```

* 2. Install RBDL (urdfreader is installed with default on this repo)
```sh
git clone --recursive https://github.com/saga0619/rbdl-orb
mkdir build
cd build
make all
sudo make install
```
 
* 3. Clone mujoco_ros_sim
```sh
cd ~/catkin_ws/src
git clone https://github.com/saga0619/mujoco_ros_sim.git
```
* 4. Clone HumanoidJET project
```sh
cd ~/catkin_ws/src
git clone https://github.com/saga0619/HumanoidJETLecture.git
```

* 5. Compile ros project
```sh
cd ~/catkin_ws
catkin_make (or catkin build)
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

