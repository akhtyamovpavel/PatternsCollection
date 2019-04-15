cmake_minimum_required(VERSION 3.5)
project(ChainResponsibility)


set(CMAKE_CXX_STANDARD 14)
set(
    SOURCES
    LogLevel.cpp
    LoggingHandler.cpp
    BaseHandler.cpp
    DivisionZeroHandler.cpp
        FileHandler.cpp FileHandler.h StderrHandler.cpp StderrHandler.h)

add_executable(ChainResponsibility ${SOURCES} main.cpp)