cmake_minimum_required(VERSION 2.8)
project(IsaacAbstractFactory)

add_executable(AbstractFactory main.cpp)
add_subdirectory(serializers)
add_subdirectory(rooms)
add_subdirectory(factories)

set(ADDITIONAL_LIBRARIES isaac_rooms isaac_factories serializers)


target_link_libraries(AbstractFactory ${ADDITIONAL_LIBRARIES})

add_executable(AbstractFactorySerializer main_serializer.cpp ${SOURCES} ${HEADERS})
target_include_directories(AbstractFactorySerializer PRIVATE rooms serializers factories)
target_link_libraries(AbstractFactorySerializer ${ADDITIONAL_LIBRARIES})