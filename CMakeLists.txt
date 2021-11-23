cmake_minimum_required(VERSION 3.20)
project(pong_plus_plus)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic -g)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options(-stdlib=libstdc++)
    endif ()
endif ()

set(SOURCES main.cpp cantec.cpp album.cpp cantaret.cpp grupare_artistica.cpp jucator.cpp joc.cpp colind.cpp colind.h cantec_aniversar.cpp cantec_aniversar.h erori_cantec.cpp erori_cantec.h)

add_executable(${PROJECT_NAME} ${SOURCES})
#add_executable(heah main.cpp cantec.cpp cantaret.cpp album.cpp cantec.cpp grupare_artistica.cpp joc.cpp jucator.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)