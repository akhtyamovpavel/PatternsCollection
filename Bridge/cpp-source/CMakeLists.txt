cmake_minimum_required(VERSION 3.5)
project(Bridge)

set(SOURCES
    wheels/SteeringWheel.cpp
    axles/Axle.cpp
    wheels/Gamepad.cpp
    axles/CarAxle.cpp
    wheels/PlaneWheel.cpp
    axles/PlaneAxle.cpp
)

add_executable(Bridge main.cpp ${SOURCES})

target_include_directories(Bridge PRIVATE include)