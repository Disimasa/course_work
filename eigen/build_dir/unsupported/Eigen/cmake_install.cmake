# Install script for directory: C:/Eigen/build_dir/source_dir/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Eigen3")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/AdolcForward"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/AlignedVector3"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/ArpackSupport"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/AutoDiff"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/BVH"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/EulerAngles"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/FFT"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/IterativeSolvers"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/KroneckerProduct"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/LevenbergMarquardt"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/MatrixFunctions"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/MoreVectorization"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/MPRealSupport"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/NonLinearOptimization"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/NumericalDiff"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/OpenGLSupport"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/Polynomials"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/Skyline"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/SparseExtra"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/SpecialFunctions"
    "C:/Eigen/build_dir/source_dir/unsupported/Eigen/Splines"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "C:/Eigen/build_dir/source_dir/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Eigen/build_dir/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

