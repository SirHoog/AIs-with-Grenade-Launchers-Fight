#pragma once

#include <sstream>
#include <iostream>
#include "GameEngine/state.hpp"
#include "GameEngine/game.hpp"
#include "ai.hpp"

namespace SirHoog
{
    class SimulationState : public State
    {
        GameDataRef data;
        sf::Clock _clock;
        sf::View cameraView;
        sf::View UI_View;
        std::vector<sf::RectangleShape> Grid;
        sf::Sprite mainMenuButton;

        int generation = 0;

        public:
            SimulationState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Render(float Interpolation);

            void Pause();
    };
}