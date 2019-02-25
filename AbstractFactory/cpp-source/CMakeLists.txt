set(
    SOURCES
    rooms/Room.cpp
    rooms/NormalRoom.cpp
    rooms/HardRoom.cpp
    rooms/BasementHardRoom.cpp
    main.cpp factories/BasementFactory.cpp
        rooms/BasementNormalRoom.cpp rooms/BasementNormalRoom.h)
set(
    HEADERS
    rooms/Room.h
    rooms/NormalRoom.h
    rooms/HardRoom.h
    rooms/BasementHardRoom.h
    factories/RoomFactory.h
    factories/BasementFactory.h
        rooms/BasementNormalRoom.cpp rooms/BasementNormalRoom.h)

add_executable(AbstractFactory ${SOURCES} ${HEADERS})