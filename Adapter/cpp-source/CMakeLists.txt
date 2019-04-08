cmake_minimum_required(VERSION 3.5)
project(Adapter)

set(CMAKE_CXX_STANDARD 14)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp TextStorage.cpp JsonStorage.cpp TextJsonAdapter.cpp TextJsonAdapter.h)

add_executable(Adapter ${SOURCE_FILES})
target_link_libraries(Adapter ${Boost_LIBRARIES})

file(COPY data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
