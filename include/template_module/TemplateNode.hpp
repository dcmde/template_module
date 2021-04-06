#ifndef TEMPLATE_MODULE_TEMPLATENODE_HPP
#define TEMPLATE_MODULE_TEMPLATENODE_HPP

#include <rclcpp/rclcpp.hpp>
#include "template_module/msg/custom_msg.hpp"

class TemplateNode : public rclcpp::Node {

public:
    explicit TemplateNode(const std::string &nodeName);

private:
    rclcpp::Subscription<template_module::msg::CustomMsg>::SharedPtr subscription_;
    rclcpp::Publisher<template_module::msg::CustomMsg>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void subscription_callback(template_module::msg::CustomMsg::SharedPtr ros_msg);

    void timer_callback();
};

#endif //TEMPLATE_MODULE_TEMPLATENODE_HPP
