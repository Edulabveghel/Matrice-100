cmake_minimum_required(VERSION 2.8.3)
project(mapper)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
)

catkin_package(
# INCLUDE_DIRS include
# LIBRARIES mapper
  CATKIN_DEPENDS roscpp std_msgs tf
# DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_node src/mapper_node.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
)
