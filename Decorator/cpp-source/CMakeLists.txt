cmake_minimum_required(VERSION 3.0)

project(Decorator)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

ExternalProject_Add(
        tgbot
        GIT_REPOSITORY https://github.com/reo7sp/tgbot-cpp
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

ExternalProject_Add(
        inicpp_project
        GIT_REPOSITORY https://github.com/SemaiCZE/inicpp
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        -DINCLUDE_INSTALL_DIR=${EXTERNAL_INSTALL_LOCATION}/include
        -DLIB_INSTALL_DIR=${EXTERNAL_INSTALL_LOCATION}/lib
)

ExternalProject_Add(
        vmime_project
        GIT_REPOSITORY https://github.com/kisli/vmime
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DVMIME_HAVE_SASL_SUPPORT=OFF
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)



add_executable(Decorator
    main.cpp
    notifiers/Notifier.cpp
    notifiers/LogNotifier.cpp
    notifiers/DecoratorNotifier.cpp
    notifiers/TgNotifier.cpp
    notifiers/EmailNotifier.cpp
)

add_dependencies(Decorator tgbot inicpp_project vmime_project)
target_include_directories(Decorator PRIVATE include)

target_link_libraries(Decorator
    TgBot inicpp vmime
    ${CMAKE_THREAD_LIBS_INIT}
    ${OPENSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CURL_LIBRARIES}
)

message(INFO ${Decorator_SOURCE_DIR}/configs/config.ini)
add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/configs/config.ini
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${Decorator_SOURCE_DIR}/configs/config.ini ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/configs/config.ini
        DEPENDS ${Decorator_SOURCE_DIR}/configs/config.ini
        COMMENT Copying configs
)

add_custom_target(
    copy_configs ALL DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/configs/config.ini
)

add_dependencies(Decorator copy_configs)