cmake_minimum_required(VERSION 3.16)
project(Vec2D)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(Vec2D
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/Vec2D.cbp
        CMakeLists.txt
        main.cpp
        Vec2D.cpp
        Vec2D.h)
