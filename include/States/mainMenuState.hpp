#pragma once

#include "GameEngine/state.hpp"
#include "GameEngine/game.hpp"

namespace SirHoog
{
    class MainMenuState : public State
    {
        GameDataRef data;
        sf::Clock _clock;
        sf::Sprite background;
        sf::Sprite title;
        sf::Sprite playButton;
        sf::Sprite settingsButton;
        sf::Sprite quitButton;

        public:
            MainMenuState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update();
            void Render(float Interpolation);

            void GameSpeed(int _TPS);
    };
}