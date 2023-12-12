#pragma once

#include <sstream>
#include <iostream>
#include "GameEngine/state.hpp"
#include "GameEngine/game.hpp"
#include "definitions.hpp"

namespace SirHoog
{
    class MainMenuState : public State
    {
        GameDataRef data;
        sf::Clock _clock;
        sf::View cameraView;
        sf::View UI_View;

        sf::VertexArray background;
        sf::Sprite title;
        sf::Sprite playButton;
        sf::Sprite settingsButton;
        sf::Sprite quitButton;

        public:
            MainMenuState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Render(float Interpolation);

            void Pause();
    };
}