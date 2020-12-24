cmake_minimum_required(VERSION 3.17)

project(Neural_network)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_executable(test main.cpp Network.h Network.cpp)
target_link_libraries (test Eigen3::Eigen)