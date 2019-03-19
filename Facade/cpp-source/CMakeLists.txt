cmake_minimum_required(VERSION 3.0)
project(Facade)

add_executable(Facade facades/BurgerFacade.cpp facades/IsaacFacade.cpp facades/IsaacFacade.h)

target_include_directories(Facade PUBLIC ../../)