cmake_minimum_required(VERSION 3.5)

project(Strategy)

add_executable(Strategy
    main.cpp
    Duck.cpp
    SimpleFlyBehaviour.cpp
    FlyBehaviour.cpp
    DuckHuntFlyBehaviour.cpp
    QuackBehaviour.cpp
    SimpleQuackBehaviour.cpp
    SwimBehaviour.cpp
    SimpleSwimBehaviour.cpp
)

