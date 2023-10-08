cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(boom_bots VERSION 1.0.0)

add_executable(boombots
    main.cpp
    src/GameEngine/*.cpp
    src/States/*.cpp
    src/*.cpp
)

find_package(SFML 2 REQUIRED network audio graphics window system) # ADD: `sfml-audio` when you're gonna add the explosion sound effects

target_include_directories(boom_bots
    PRIVATE include
)

target_link_directories(boom_bots
    PUBLIC lib
)