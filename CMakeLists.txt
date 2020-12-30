cmake_minimum_required(VERSION 3.17)

project(Neural_network)

add_subdirectory(Network_lib)


add_executable(xor_example examples/xor_example.cpp)
target_link_libraries (xor_example NeuralNetwork)

add_executable(mnist_example examples/mnist_example.cpp)
target_link_libraries(mnist_example NeuralNetwork)

set(CMAKE_PREFIX_PATH "C:/opencv/opencv/build/")
find_package( OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mnist_with_opencv examples/mnist_with_opencv.cpp)
target_link_libraries(mnist_with_opencv NeuralNetwork ${OpenCV_LIBS})

file(COPY ${PROJECT_SOURCE_DIR}/dlls/ DESTINATION ${CMAKE_BINARY_DIR} PATTERN "*.rar" EXCLUDE)
file(COPY ${PROJECT_SOURCE_DIR}/images/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/weights/ DESTINATION ${CMAKE_BINARY_DIR})

#add_custom_command(TARGET mnist_with_opencv POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${PROJECT_SOURCE_DIR}/dlls/opencv_world451.dll"
#        $<TARGET_FILE_DIR:mnist_with_opencv>)
