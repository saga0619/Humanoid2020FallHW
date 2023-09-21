# DYROS JET Repository 

* This is a DYROS JET Humanoid Repository FOR Ubuntu 20.04
* Remove real-robot components. (imu & dynamixel..)
* Remove v-rep components.
* Migrate qt4 to qt5 for GUI
* ROS NOETIC



## How do I get set up? ##

* 1. CLONE [mujoco_ros_sim](https://github.com/saga0619/mujoco_ros_sim) to your catkin_ws/src
* 2. CLONE [HumanoidJetLecture](https://github.com/saga0619/HumanoidJetLecture) to your catkin_ws/src
* 3. RUN install_prereq.sh in this repo.
* 4. COMPILE cloned projects!!


##### INSTALLATION USING PREREQUISITIES INSTALLATION SCRIPT 
```sh
cd ~/catkin_ws/src
git clone https://github.com/saga0619/HumanoidJETLecture.git
git clone https://github.com/saga0619/mujoco_ros_sim.git
sudo ./HumanoidJetLecture/install_prereq.sh
cd ~/catkin_ws
catkin_make
```

##### COMPONENTS MANUAL INSTALLATION (if auto installation script now work)

* 1. Install ros-noetic-realtime-tools and qtbase5-private-dev
```sh
sudo apt-get install ros-noetic-realtime-tools qtbase5-private-dev
```

* 2. Install RBDL (urdfreader is installed with default on this repo)
```sh
git clone --recursive https://github.com/saga0619/rbdl-orb
mkdir build
cd build
cmake ..
make all
sudo make install
```

* 2. Install QPoases
```sh
git clone --recursive https://github.com/saga0619/qpoases
mkdir build
cd build
cmake ..
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

* launch GUI only
```sh
rosrun dyros_jet_gui dyros_jet_gui
```

* launch simulation only
```sh
roslaunch dyros_jet_launch mujoco.lanuch
```

* launch simulation and gui together
```sh
roslaunch dyros_jet_launch simulation.launch
```

### How do I contribuite to this repo? ###
* Read this http://wiki.ros.org/CppStyleGuide

