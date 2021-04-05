cmake_minimum_required(VERSION 2.8)


option(ON_PI "Build on PI" OFF)



if(ON_PI)
	message("Compiling on Pi")
	if("${SYSROOT}" STREQUAL "")
		message(FATAL_ERROR "Need sysroot for compiling")
	endif()

    set(CMAKE_CXX_COMPILER ${SYSROOT}/aarch64-linux-gnu-g++)
    set(CMAKE_C_COMPILER ${SYSROOT}/aarch64-linux-gnu-gcc)
	set(CMAKE_FIND_ROOT_PATH ${SYSROOT})
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib-arm)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib-arm)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin-arm)
    set(
		CMAKE_CXX_FLAGS
		"${CMAKE_CXX_FLAGS} -fasm"
    )

    set(
        CMAKE_C_FLAGS
        "${CMAKE_CXX_FLAGS} -fasm"
    )
else()
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
endif()

set(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# the RPATH to be used when installing
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
# don't add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH


message("Bin dir is ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
project(PatternsCollection)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(FactoryMethod/cpp-source)
add_subdirectory(AbstractFactory/cpp-source)
add_subdirectory(Builder/cpp-source)
add_subdirectory(Prototype/cpp-source)
add_subdirectory(Bridge/cpp-source)
add_subdirectory(ChainResponsibility/cpp-source)
add_subdirectory(Strategy/cpp-source)
add_subdirectory(Observer/cpp-source)
add_subdirectory(Command/cpp-source)
add_subdirectory(Mediator/cpp-source)
add_subdirectory(Memento/cpp-source)
add_subdirectory(State/cpp-source)
add_subdirectory(Visitor/cpp-source)

if(NOT ON_PI)
	add_subdirectory(Adapter/cpp-source)
	add_subdirectory(Composite/cpp-source)
	add_subdirectory(Decorator/cpp-source)
endif()
add_subdirectory(Facade/cpp-source)

