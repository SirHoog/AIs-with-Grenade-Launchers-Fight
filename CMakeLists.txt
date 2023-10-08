cmake_minimum_required(VERSION 3.10)

project(boom_bots)

add_executable(boom_bots
    main.cpp

    src/ai.cpp
    src/character.cpp
    src/entity.cpp
    src/grenade.cpp
    src/neuralNetwork.cpp
    src/neuron.cpp

    src/GameEngine/assetManager.cpp
    src/GameEngine/game.cpp
    src/GameEngine/inputManager.cpp
    src/GameEngine/stateMachine.cpp

    src/States/mainMenuState.cpp
    src/States/simulationState.cpp
)

target_include_directories(boom_bots
    PRIVATE include
    PRIVATE include/GameEngine
    PRIVATE include/States
    PRIVATE include/NC
    PRIVATE include/NC/NumCpp
)

target_link_directories(boom_bots
    PUBLIC lib/NumCpp
)

target_link_libraries(boom_bots sfml-graphics sfml-window sfml-system)