#ifndef TEMPLATE_MODULE_TEMPLATENODE_HPP
#define TEMPLATE_MODULE_TEMPLATENODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class TemplateNode : public rclcpp::Node {

public:
    explicit TemplateNode(const std::string &nodeName);

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void subscription_callback(std_msgs::msg::String::SharedPtr ros_msg);

    void timer_callback();
};

#endif //TEMPLATE_MODULE_TEMPLATENODE_HPP
