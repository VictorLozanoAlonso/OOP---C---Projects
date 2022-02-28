cmake_minimum_required(VERSION 3.19)
project(MS03)

set(CMAKE_CXX_STANDARD 17)

add_executable(MS03 ms3.cpp CustomerOrder.h CustomerOrder.cpp Station.h Station.cpp Utilities.cpp Utilities.h Workstation.cpp Workstation.h LineManager.cpp LineManager.h)