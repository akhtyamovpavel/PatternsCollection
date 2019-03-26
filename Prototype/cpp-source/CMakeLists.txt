cmake_minimum_required(VERSION 3.5)
project(Prototype)

set(CMAKE_CXX_STANDARD 11)

set(
	SOURCE_FILES
	main.cpp 
	Prototype.cpp
	Prototype.h
	FerrariPrototype.cpp
	FerrariPrototype.h 
	PirelliFerrari.cpp
	PirelliFerrari.h
)
add_executable(Prototype ${SOURCE_FILES})
