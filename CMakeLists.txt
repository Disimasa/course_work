cmake_minimum_required(VERSION 3.17)

project(Neural_network)

add_subdirectory(Network_lib)

add_executable(xor_example examples/xor_example.cpp)
target_link_libraries (xor_example NeuralNetwork)

add_executable(mnist_example examples/mnist_example.cpp)
target_link_libraries(mnist_example NeuralNetwork)

#set(CMAKE_PREFIX_PATH "C:/opencv/opencv/build/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INSTALL_PATH})
add_executable(mnist_with_opencv examples/mnist_with_opencv.cpp)
target_link_libraries(mnist_with_opencv NeuralNetwork ${OpenCV_LIBS})

install(FILES $<TARGET_FILE:opencv_world> DESTINATION bin)
install(TARGETS
        xor_example mnist_example mnist_with_opencv
        DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/images/ DESTINATION images)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/train_data/ DESTINATION train_data)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/weights/ DESTINATION weights)
message(${CMAKE_INSTALL_PREFIX})
#file(COPY ${PROJECT_SOURCE_DIR}/images/ DESTINATION bin)
#file(COPY ${PROJECT_SOURCE_DIR}/train_data/ DESTINATION bin)
#file(COPY ${PROJECT_SOURCE_DIR}/weights/ DESTINATION bin)
