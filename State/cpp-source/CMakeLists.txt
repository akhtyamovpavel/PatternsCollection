project(State)

set(SOURCES states/State.cpp states/State.h TrafficLight.cpp TrafficLight.h states/Red.cpp states/Red.h states/Yellow.cpp states/Yellow.h states/Green.cpp states/Green.h)
add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)