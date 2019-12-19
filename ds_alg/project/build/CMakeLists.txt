cmake_minimum_required(VERSION 3.6)

project(phoenix VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS " -pthread")

SET(CMAKE_CXX_COMPILER /usr/bin/g++)
SET(CMAKE_BUILD_TYPE Debug)

add_library(linkedlist ../../lib/src/linked_list.cpp ../../lib/incl/linked_list.hpp)
add_library(circularqueue ../../lib/src/circular_queue.cpp ../../lib/incl/circular_queue.hpp)

include_directories(../incl)

set(SOURCE_FILES ../src/ctci/bt_in_order_successor.cpp)

add_executable(phoenix ${SOURCE_FILES})

target_link_libraries(phoenix linkedlist circularqueue)




