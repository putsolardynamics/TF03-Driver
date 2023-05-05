#include "rclcpp/rclcpp.hpp"
#include <TF03.h>
class TF03Driver : public rclcpp::Node 
{
public: 
    TF03Driver() : rclcpp::Node("tf03_driver") 
    {
        driver_instance_ = TF03(this);
    }

private:
    TF03 driver_instance_;
};
int main(int argc, char **argv)
{
    //ros::init(argc, argv, "tf03_node");
    //ros::NodeHandle nh("~");
    rclcpp::init(argc, argv);
    // auto node = rclcpp::Node::make_shared("tf03_node");
    //ROS_INFO("Init TF03 object");
    // RCLCPP_INFO(node->get_logger(),"Init TF03 object");
    rclcpp::spin(std::make_shared<TF03Driver>());
    // TF03 tf03(node);
    return 0;
}