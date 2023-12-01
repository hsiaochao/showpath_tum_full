#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

nav_msgs::Path readTumPath(const std::string& file_path) {
    nav_msgs::Path path;
    path.header.frame_id = "map";

    std::ifstream file(file_path.c_str());
    if (!file) {
        ROS_ERROR_STREAM("Failed to open the file: " << file_path);
        return path;
    }


    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double timestamp, x, y, z;
        if (!(iss >> timestamp >> x >> y >> z)) {
            ROS_WARN_STREAM("Invalid line format: " << line);
            continue;
        }

        geometry_msgs::PoseStamped pose;
        pose.header.stamp = ros::Time(timestamp);
        pose.pose.position.x = x;
        pose.pose.position.y = y;
        pose.pose.position.z = z;

        path.poses.push_back(pose);
    }

    return path;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "tum_path_publisher");
    ros::NodeHandle nh;

  // 从参数服务器获取路径//Get path from parameter server
  std::string file_path;
  if (!nh.getParam("tum_file_path", file_path)) {
    ROS_ERROR("Failed to retrieve 'file_path' parameter");
    return 1;
  }

    nav_msgs::Path path = readTumPath(file_path);

    ros::Publisher path_pub = nh.advertise<nav_msgs::Path>("tum_path", 1);
    ros::Rate rate(1); 

    while (ros::ok()) {
        path_pub.publish(path);
        rate.sleep();
    }

    return 0;
}

