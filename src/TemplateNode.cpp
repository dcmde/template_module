#include "TemplateNode.hpp"

const char *publisher_name = "template_publisher";
const char *subscription_name = "template_subscription";

TemplateNode::TemplateNode(const std::string &nodeName) : Node(nodeName) {

    // The subscription will run the callback function each timer a new message is received.
    subscription_ = create_subscription<std_msgs::msg::String>(subscription_name,
                                                               10,
                                                               std::bind(&TemplateNode::subscription_callback,
                                                                         this,
                                                                         std::placeholders::_1));

    // This is used to publish messages on a given topic when needed.
    publisher_ = create_publisher<std_msgs::msg::String>(publisher_name, 10);

    // The timer is called every 500 ms.
    timer_ = create_wall_timer(std::chrono_literals::operator ""ms(500),
                               std::bind(&TemplateNode::timer_callback,
                                         this));

}

void TemplateNode::subscription_callback(std_msgs::msg::String::SharedPtr ros_msg) {
    // Process the new message.
    std::cout << ros_msg->data << std::endl;
}

void TemplateNode::timer_callback() {
    // This method is run every 500ms.
    std_msgs::msg::String ros_msg;
    ros_msg.set__data("Template Module message");
    // Publish the message on the topic.
    publisher_->publish(ros_msg);
}

