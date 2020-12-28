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

add_custom_target(Dlls
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/dlls/opencv_world451.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/dlls/opencv_world451d.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/one.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/two.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/three.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/four.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/five.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/six.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/seven.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/eight.jpg ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/images/nine.jpg ${CMAKE_BINARY_DIR}
        )

add_dependencies(mnist_with_opencv Dlls)

#add_custom_command(TARGET mnist_with_opencv POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${PROJECT_SOURCE_DIR}/dlls/opencv_world451.dll"
#        $<TARGET_FILE_DIR:mnist_with_opencv>)
