cmake_minimum_required(VERSION 3.0)
project(Facade)

add_executable(
        Facade
        facades/BurgerFacade.cpp
        facades/IsaacFacade.cpp
        facades/IsaacFacade.h
        facades/Facade.cpp
        facades/Facade.h
        main.cpp
)

link_directories(../../lib)

target_include_directories(Facade PRIVATE ../../)
target_include_directories(Facade PRIVATE ../../AbstractFactory/cpp-source/rooms)
target_link_libraries(Facade serializers isaac_rooms isaac_factories burger_shop)

# set_target_properties(Facade PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
install(TARGETS Facade
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
