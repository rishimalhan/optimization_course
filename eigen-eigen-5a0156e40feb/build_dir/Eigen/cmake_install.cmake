# Install script for directory: /home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/StdList"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SparseLU"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Core"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/QR"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Eigenvalues"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/LU"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Jacobi"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SparseCore"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Sparse"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SPQRSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Geometry"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/OrderingMethods"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SVD"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SuperLUSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/CholmodSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Dense"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/MetisSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/IterativeLinearSolvers"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SparseQR"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/UmfPackSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Cholesky"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/StdDeque"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/PardisoSupport"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/QtAlignedMalloc"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/StdVector"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/SparseCholesky"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Eigen"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/Householder"
    "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/PaStiXSupport"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/badass/optimization/eigen-eigen-5a0156e40feb/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

