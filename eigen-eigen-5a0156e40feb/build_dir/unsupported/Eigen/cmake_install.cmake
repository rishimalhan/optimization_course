# Install script for directory: /home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/AdolcForward"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/AlignedVector3"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/ArpackSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/AutoDiff"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/BVH"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/EulerAngles"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/FFT"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/IterativeSolvers"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/KroneckerProduct"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/LevenbergMarquardt"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/MatrixFunctions"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/MoreVectorization"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/MPRealSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/NonLinearOptimization"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/NumericalDiff"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/OpenGLSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/Polynomials"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/Skyline"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/SparseExtra"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/SpecialFunctions"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/Splines"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "/home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

