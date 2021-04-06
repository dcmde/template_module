cmake_minimum_required(VERSION 3.5)
project(template_module)

# Default to C99
if (NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif ()

# Default to C++14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
############# Message type #############
# With standard string
#find_package(std_msgs REQUIRED)
# With custom message
find_package(rosidl_default_generators REQUIRED)

############# Add other package #############
#find_package(communication_module REQUIRED)

include_directories(include/template_module)

rosidl_generate_interfaces(${PROJECT_NAME}
        "msg/CustomMsg.msg"
        )


set(dependencies
        "rclcpp"
        ############# Message type #############
        "std_msgs"
        ############# Add other package #############
        #        "communication_module"
        )

set(SOURCES
        src/template_module.cpp
        src/TemplateNode.cpp)

add_executable(tmpl_module ${SOURCES})
ament_target_dependencies(tmpl_module ${dependencies})

# Custom message
rosidl_target_interfaces(tmpl_module ${PROJECT_NAME} "rosidl_typesupport_cpp")

target_include_directories(tmpl_module PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

install(TARGETS tmpl_module
        DESTINATION lib/${PROJECT_NAME})

if (BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    # the following line skips the linter which checks for copyrights
    # uncomment the line when a copyright and license is not present in all source files
    #set(ament_cmake_copyright_FOUND TRUE)
    # the following line skips cpplint (only works in a git repo)
    # uncomment the line when this package is not in a git repo
    #set(ament_cmake_cpplint_FOUND TRUE)
    ament_lint_auto_find_test_dependencies()
endif ()

ament_package()
