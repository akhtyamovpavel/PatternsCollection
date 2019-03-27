cmake_minimum_required(VERSION 3.5)
project(Composite)

set(SOURCES ration/DishComponent.cpp ration/Dish.cpp ration/Milk.cpp ration/Breakfast.cpp)

add_executable(Composite main.cpp ${SOURCES})
target_include_directories(Composite PRIVATE include)