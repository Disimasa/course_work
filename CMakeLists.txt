cmake_minimum_required(VERSION 3.17)

project(Neural_network)

# adding library
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_library(NeuralNetwork Network.h Network.cpp Layer.h Layer.cpp FullyConnected.h FullyConnected.cpp
        Convolutional.h Convolutional.cpp ActivationMethods.h)
target_link_libraries(NeuralNetwork Eigen3::Eigen)

add_executable(xor_example xor_example.cpp)
target_link_libraries (xor_example NeuralNetwork)

add_executable(mnist_example mnist_example.cpp)
target_link_libraries(mnist_example NeuralNetwork)

set(CMAKE_PREFIX_PATH "C:/opencv/opencv/build/")
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mnist_with_opencv mnist_with_opencv.cpp)
target_link_libraries(mnist_with_opencv NeuralNetwork ${OpenCV_LIBS})