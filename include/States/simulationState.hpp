#pragma once

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
        sf::View view;
        sf::Sprite background;
        sf::Sprite mainMenuButton;

        public:
            SimulationState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update();
            void Render(float Interpolation);

            void GameSpeed(int _TPS);
    };
}