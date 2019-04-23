project(Visitor)
set(SOURCES main.cpp rooms/ElementRoom.cpp rooms/ElementRoom.h workers/Visitor.h workers/Visitor.cpp rooms/Kitchen.cpp rooms/Kitchen.h rooms/LivingRoom.cpp rooms/LivingRoom.h rooms/BathRoom.cpp rooms/BathRoom.h workers/Tiler.cpp workers/Tiler.h workers/Painter.cpp workers/Painter.h)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)