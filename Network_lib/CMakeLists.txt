find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_library(NeuralNetwork headers/Network.h source/Network.cpp headers/Layer.h source/Layer.cpp
        headers/FullyConnected.h source/FullyConnected.cpp headers/Convolutional.h
        source/Convolutional.cpp headers/ActivationMethods.h)
target_link_libraries(NeuralNetwork Eigen3::Eigen)
target_include_directories(NeuralNetwork PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})