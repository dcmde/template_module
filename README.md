# Template module

## Module creation

If you want to create a ros2 package from scratch.

```
ros2 pkg create --build-type ament_cmake --node-name template_module template_module
```

Otherwise you can copy this repo in the `src` directory of `CIDN_ROS`.

## Package dependencies

If your module depends of another ros2 pkg you need to change the `package.xml` and the `CMakeList.txt`

Below is an example where the `communication_module` is added:

```
  <buildtool_depend>ament_cmake</buildtool_depend>
  <buildtool_depend>rosidl_default_generators</buildtool_depend>

  <build_depend>rosidl_default_generators</build_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>

  <member_of_group>rosidl_interface_packages</member_of_group>

  <depend>rclcpp</depend>
  <depend>communication_module</depend>
  <depend>std_msgs</depend>

  <member_of_group>rosidl_interface_packages</member_of_group>
```

```
find_package(communication_module REQUIRED)
...
set(dependencies "rclcpp" "std_msgs" "communication_module")
...
add_executable(ctrl_mav_module ${SOURCES})
ament_target_dependencies(ctrl_mav_module ${dependencies})
```

Before compiling this module you need to compile the package `colcon build --packages-select desired_module` and
then `source install/setup.zsh` in order to have `find_package` to work properly.

## Custom message

If you want to send custom ros2 message you need to create a file in the `msg` directory. You can find all usable
types https://docs.ros.org/en/foxy/Concepts/About-ROS-Interfaces.html#interfaceconcept
You also need to change the `packge.xml` and `CMakeList.txt`.

package.xml

```
    <buildtool_depend>rosidl_default_generators</buildtool_depend>
    <build_depend>rosidl_default_generators</build_depend>
    <exec_depend>rosidl_default_runtime</exec_depend>
    ...
    <member_of_group>rosidl_interface_packages</member_of_group>
```

CMakeList.txt

```
    ...
    ############# Message type #############
    # With standard string
    #find_package(std_msgs REQUIRED)
    # With custom message
    find_package(rosidl_default_generators REQUIRED)
    ...
    rosidl_generate_interfaces(${PROJECT_NAME}
            "msg/CustomMsg.msg"
            )
    ...
    # Custom message
    rosidl_target_interfaces(tmpl_module ${PROJECT_NAME} "rosidl_typesupport_cpp")
```
