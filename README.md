#  showpath_tum_full

#### introduce
Compared to https://github.com/hsiaochao/showpath_tum,
This work uses rviz to draw a full picture of the trajectory in Tum format in a text file at onc
#### Software architecture
Description Using ROS system and C++language, refer to CMakeLists.txt for configuration, usually only ROS and cmake need to be installed.

#### Installation and Compilation
Download this source code into the src folder of your catkin worksapce:
```
$ cd catkin_ws/src
$  git clone https://github.com/hsiaochao/showpath_tum_full
```
Compile the project:
```
$ cd catkin_ws
$ source devel/setup.bash
$ catkin_make
```
#### How to use it

Start the project on a terminal:
```
$ roslaunch showpath_tum showpath01.launch
```
You can complete the playback trajectory in rviz.
#### Participate in contributions

Fork warehouse
Create a new Feature_ Xxx branch
Submit code
Create a new Pull Request
