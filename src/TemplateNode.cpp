#include "TemplateNode.hpp"

const char *publisher_name = "template_publisher";
const char *subscription_name = "template_subscription";

TemplateNode::TemplateNode(const std::string &nodeName) : Node(nodeName) {

    // The subscription will run the callback function each timer a new message is received.
    subscription_ = create_subscription<template_module::msg::CustomMsg>(subscription_name,
                                                               10,
                                                               std::bind(&TemplateNode::subscription_callback,
                                                                         this,
                                                                         std::placeholders::_1));

    // This is used to publish messages on a given topic when needed.
    publisher_ = create_publisher<template_module::msg::CustomMsg>(publisher_name, 10);

    // The timer is called every 500 ms.
    timer_ = create_wall_timer(std::chrono_literals::operator ""ms(500),
                               std::bind(&TemplateNode::timer_callback,
                                         this));

}

void TemplateNode::subscription_callback(template_module::msg::CustomMsg::SharedPtr ros_msg) {
    // Process the new message.
    std::cout << ros_msg->msg_float << std::endl;
}

void TemplateNode::timer_callback() {
    std::vector<double> vec;
    vec.push_back(0.1);
    vec.push_back(0.2);

    // This method is run every 500ms.
    template_module::msg::CustomMsg ros_msg;
    ros_msg.set__msg_float(100.1);
    ros_msg.set__msg_float_array(vec);
    // Publish the message on the topic.
    publisher_->publish(ros_msg);
}

