#include "TemplateNode.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);
  auto sharedPtr = std::make_shared<TemplateNode>("TemplateNode");
  rclcpp::spin(sharedPtr);
  rclcpp::shutdown();
  return 0;
}
