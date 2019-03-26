cmake_minimum_required(VERSION 2.8)
project(IsaacFactories)

set(SOURCES BasementFactory.cpp CavesFactory.cpp RoomFactory.cpp)

add_library(isaac_factories SHARED ${SOURCES})
target_link_libraries(isaac_factories isaac_rooms)

install(TARGETS isaac_factories
	LIBRARY DESTINATION lib
)
