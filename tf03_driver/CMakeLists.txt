cmake_minimum_required(VERSION 3.8)
project(tf03_driver)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${SERIAL_INCLUDE_DIRS}
)

add_executable(tf03_node src/tf03_node.cpp src/TF03.cpp)

#target_link_libraries(tf03_node
 # ${catkin_LIBRARIES}
  #${SERIAL_LDFLAGS}
#)
ament_target_dependencies(tf03_node 
rclcpp
sensor_msgs
#libserial
)
target_link_libraries(tf03_node ${SERIAL_LDFLAGS})

#install(DIRECTORY launch
#	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)

#install(TARGETS tf03_node
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS tf03_node
RUNTIME DESTINATION lib/${PROJECT_NAME}
ARCHIVE DESTINATION lib/${PROJECT_NAME}
LIBRARY DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rclcpp)
  ament_package()
