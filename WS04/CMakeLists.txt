cmake_minimum_required(VERSION 3.19)
project(WS04_p1)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS04_p1 w4_p2.cpp Reservation.cpp Reservation.h Restaurant.cpp Restaurant.h ConfirmationSender.cpp ConfirmationSender.h)