cmake_minimum_required(VERSION 2.8)

project(PatternsCollection)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PatternsCollection_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PatternsCollection_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PatternsCollection_SOURCE_DIR}/bin)

add_subdirectory(AbstractFactory/cpp-source)
add_subdirectory(Builder/cpp-source)
add_subdirectory(Prototype/cpp-source)
add_subdirectory(Adapter/cpp-source)