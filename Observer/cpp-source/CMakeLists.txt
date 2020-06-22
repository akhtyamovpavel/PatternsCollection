cmake_minimum_required(VERSION 3.5)

project(Observer)

add_executable(Observer main.cpp)

target_link_libraries(Observer Threads::Threads)