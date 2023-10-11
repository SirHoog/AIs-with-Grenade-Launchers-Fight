cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY RULE_MESSAGES OFF) # For me personally

project(BoomBots VERSION 1.0.0)

add_executable(BoomBots
    main.cpp

    src/animation.cpp
    src/entity.cpp
    src/character.cpp
    src/grenade.cpp
    src/neuron.cpp
    src/neuralNetwork.cpp
    src/ai.cpp

    src/GameEngine/stateMachine.cpp
    src/GameEngine/assetManager.cpp
    src/GameEngine/inputManager.cpp
    src/GameEngine/game.cpp

    src/States/mainMenuState.cpp
    src/States/simulationState.cpp
)

target_include_directories(BoomBots
    PRIVATE include
    PRIVATE include/GameEngine
    PRIVATE include/States
    PRIVATE include/NC
    PRIVATE include/NC/NumCpp
)

target_link_directories(BoomBots
    PUBLIC lib/NumCpp
)

target_link_libraries(BoomBots sfml-graphics sfml-window sfml-system)