cmake_minimum_required(VERSION 2.8)

project(IsaacRooms)

set(
        SOURCES
        BasementHardRoom.cpp
        BasementNormalRoom.cpp
        CavesHardRoom.cpp
        CavesNormalRoom.cpp
        HardRoom.cpp
        NormalRoom.cpp
        Room.cpp
)

add_library(isaac_rooms SHARED ${SOURCES})

install(TARGETS isaac_rooms
	LIBRARY DESTINATION lib
)
