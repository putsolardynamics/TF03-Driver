#include "rclcpp/rclcpp.hpp"
#include <TF03.h>

int main(int argc, char **argv)
{
    //ros::init(argc, argv, "tf03_node");
    //ros::NodeHandle nh("~");
    rclcpp::init(argc, argv);
    // auto node = rclcpp::Node::make_shared("tf03_node");
    //ROS_INFO("Init TF03 object");
    // RCLCPP_INFO(node->get_logger(),"Init TF03 object");
    rclcpp::spin(std::make_shared<TF03>());
    // TF03 tf03(node);
    return 0;
}