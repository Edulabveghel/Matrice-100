cmake_minimum_required(VERSION 2.8.3)
project(imu_reader)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  std_msgs
  tf
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES drone_sim
  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(${PROJECT_NAME}_node src/imu_reader_node.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
 )
