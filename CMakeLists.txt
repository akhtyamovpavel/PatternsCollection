cmake_minimum_required(VERSION 2.8)


option(ON_PI "Build on PI" OFF)

if("${SYSROOT}" STREQUAL "")
	message(FATAL_ERROR "Need sysroot for compiling")
endif()

if(ON_PI)
	message("Compiling on Pi")

	set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
	set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
	set(CMAKE_FIND_ROOT_PATH ${SYSROOT})
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib-arm)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib-arm)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin-arm)
else()
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
endif()

message("Bin dir is ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
project(PatternsCollection)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(AbstractFactory/cpp-source)
add_subdirectory(Builder/cpp-source)
add_subdirectory(Prototype/cpp-source)

if(NOT ON_ARM)
	add_subdirectory(Adapter/cpp-source)
endif()
add_subdirectory(Facade/cpp-source)
