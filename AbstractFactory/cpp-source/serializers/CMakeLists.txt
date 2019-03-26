cmake_minimum_required(VERSION 2.8)
project(Serializers)

set(SOURCES ../rooms/HardRoom.cpp ../rooms/NormalRoom.cpp ../rooms/Room.cpp RoomSerializer.cpp RoomSerializer.h GameSerializer.cpp GameSerializer.h)
add_library(serializers SHARED ${SOURCES})
target_include_directories(serializers PRIVATE ../rooms)

install(TARGETS serializers
	LIBRARY DESTINATION lib
)
