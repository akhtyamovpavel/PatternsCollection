cmake_minimum_required(VERSION 3.0)
project(Facade)

add_executable(Facade
        facades/BurgerFacade.cpp facades/IsaacFacade.cpp facades/IsaacFacade.h facades/Facade.cpp facades/Facade.h main.cpp)

target_include_directories(Facade PRIVATE ../../)
target_include_directories(Facade PRIVATE ../../AbstractFactory/cpp-source/rooms)
