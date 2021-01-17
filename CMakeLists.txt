cmake_minimum_required(VERSION 3.17)

project(Neural_network)

add_subdirectory(Network_lib)

add_executable(xor_example examples/xor_example.cpp)
target_link_libraries (xor_example NeuralNetwork)

add_executable(mnist_example examples/mnist_example.cpp)
target_link_libraries(mnist_example NeuralNetwork)

set(CMAKE_PREFIX_PATH "/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INSTALL_PATH})
add_executable(mnist_with_opencv examples/mnist_with_opencv.cpp)
target_link_libraries(mnist_with_opencv NeuralNetwork ${OpenCV_LIBS})

install(FILES $<TARGET_FILE:opencv_world> DESTINATION $<TARGET_FILE_DIR:mnist_with_opencv>)
file(COPY ${PROJECT_SOURCE_DIR}/images/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/train_data/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/weights/ DESTINATION ${CMAKE_BINARY_DIR})
