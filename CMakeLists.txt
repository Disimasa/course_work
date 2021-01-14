cmake_minimum_required(VERSION 3.17)

project(Neural_network)

add_subdirectory(Network_lib)


add_executable(xor_example examples/xor_example.cpp)
target_link_libraries (xor_example NeuralNetwork)
set_target_properties(xor_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(xor_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})

add_executable(mnist_example examples/mnist_example.cpp)
target_link_libraries(mnist_example NeuralNetwork)
set_target_properties(mnist_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(mnist_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_PREFIX_PATH ./opencv/build/)
find_package( OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mnist_with_opencv examples/mnist_with_opencv.cpp)
target_link_libraries(mnist_with_opencv NeuralNetwork ${OpenCV_LIBS})
set_target_properties(mnist_with_opencv PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(mnist_with_opencv PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${OpenCV_DIR}/x64/vc15/bin/opencv_world451.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${OpenCV_DIR}/x64/vc15/bin/opencv_world451d.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/images/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/weights/ DESTINATION ${CMAKE_BINARY_DIR})

#add_custom_command(TARGET mnist_with_opencv POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${PROJECT_SOURCE_DIR}/dlls/opencv_world451.dll"
#        $<TARGET_FILE_DIR:mnist_with_opencv>)
