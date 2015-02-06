project(lcmMultithread)
cmake_minimum_required(VERSION 2.8)
#aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} main.cpp
                               lcm.cpp
                               lcm_p.cpp)

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -pthread")

