cmake_minimum_required(VERSION 3.0)
project(FactoryMethod)

set(
    SOURCES
        main.cpp routes/Route.cpp routes/Route.h routes/EthernetRoute.cpp routes/EthernetRoute.h routes/WifiRoute.cpp routes/WifiRoute.h routers/Router.cpp routers/Router.h routers/Hub.cpp routers/Hub.h routers/WifiRouter.cpp routers/WifiRouter.h)

add_executable(FactoryMethod ${SOURCES})
target_include_directories(FactoryMethod PRIVATE ${FactoryMethod_SOURCE_DIR})
