#pragma once

#include <sstream>
#include <iostream>
#include "GameEngine/state.hpp"
#include "GameEngine/game.hpp"
#include "mainMenuState.hpp"
#include "ai.hpp"

namespace SirHoog
{
    class SimulationState : public State
    {
        GameDataRef data;
        sf::Clock _clock;
        // REMOVING TEMPORARILY: sf::View view; // REASON: Annoying to deal with, so I won't add it until I'm finished with everything else
        sf::Sprite background;
        sf::Sprite mainMenuButton;

        int generation = 0;

        public:
            SimulationState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Render(float Interpolation);

            void GameSpeed(int _TPS);
    };
}