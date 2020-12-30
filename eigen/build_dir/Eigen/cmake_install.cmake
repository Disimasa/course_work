# Install script for directory: C:/Eigen/build_dir/source_dir/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "C:/Eigen/build_dir/source_dir/Eigen/Cholesky"
    "C:/Eigen/build_dir/source_dir/Eigen/CholmodSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/Core"
    "C:/Eigen/build_dir/source_dir/Eigen/Dense"
    "C:/Eigen/build_dir/source_dir/Eigen/Eigen"
    "C:/Eigen/build_dir/source_dir/Eigen/Eigenvalues"
    "C:/Eigen/build_dir/source_dir/Eigen/Geometry"
    "C:/Eigen/build_dir/source_dir/Eigen/Householder"
    "C:/Eigen/build_dir/source_dir/Eigen/IterativeLinearSolvers"
    "C:/Eigen/build_dir/source_dir/Eigen/Jacobi"
    "C:/Eigen/build_dir/source_dir/Eigen/LU"
    "C:/Eigen/build_dir/source_dir/Eigen/MetisSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/OrderingMethods"
    "C:/Eigen/build_dir/source_dir/Eigen/PaStiXSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/PardisoSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/QR"
    "C:/Eigen/build_dir/source_dir/Eigen/QtAlignedMalloc"
    "C:/Eigen/build_dir/source_dir/Eigen/SPQRSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/SVD"
    "C:/Eigen/build_dir/source_dir/Eigen/Sparse"
    "C:/Eigen/build_dir/source_dir/Eigen/SparseCholesky"
    "C:/Eigen/build_dir/source_dir/Eigen/SparseCore"
    "C:/Eigen/build_dir/source_dir/Eigen/SparseLU"
    "C:/Eigen/build_dir/source_dir/Eigen/SparseQR"
    "C:/Eigen/build_dir/source_dir/Eigen/StdDeque"
    "C:/Eigen/build_dir/source_dir/Eigen/StdList"
    "C:/Eigen/build_dir/source_dir/Eigen/StdVector"
    "C:/Eigen/build_dir/source_dir/Eigen/SuperLUSupport"
    "C:/Eigen/build_dir/source_dir/Eigen/UmfPackSupport"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "C:/Eigen/build_dir/source_dir/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

