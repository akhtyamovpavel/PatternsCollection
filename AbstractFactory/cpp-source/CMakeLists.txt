set(
    SOURCES
    rooms/Room.cpp
    rooms/NormalRoom.cpp
    rooms/HardRoom.cpp
    rooms/BasementHardRoom.cpp
    factories/BasementFactory.cpp
    rooms/BasementNormalRoom.cpp
    rooms/BasementNormalRoom.h)
set(
    HEADERS
    rooms/Room.h
    rooms/NormalRoom.h
    rooms/HardRoom.h
    rooms/BasementHardRoom.h
    factories/RoomFactory.h
    factories/BasementFactory.h
    rooms/BasementNormalRoom.cpp rooms/BasementNormalRoom.h factories/CavesFactory.cpp factories/CavesFactory.h rooms/CavesNormalRoom.cpp rooms/CavesNormalRoom.h rooms/CavesHardRoom.cpp rooms/CavesHardRoom.h)

add_executable(AbstractFactory ${SOURCES} ${HEADERS} main.cpp)

add_subdirectory(serializers)

add_executable(AbstractFactorySerializer main_serializer.cpp ${SOURCES} ${HEADERS})
target_include_directories(AbstractFactorySerializer PRIVATE rooms serializers factories)
target_link_libraries(AbstractFactorySerializer serializers)