set(SOURCES
        Chef.cpp
        builders/BurgerBuilder.cpp
        builders/HamburgerBuilder.cpp
        builders/base/Burger.cpp
        builders/VegiburgerBuilder.cpp)

add_executable(Builder ${SOURCES} main.cpp)

add_library(burger_shop SHARED ${SOURCES})

install(TARGETS burger_shop
	LIBRARY DESTINATION lib
)
