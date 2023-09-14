#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "stateMachine.hpp"
#include "assetManager.hpp"
#include "inputManager.hpp"

namespace SirHoog
{
    struct GameData
    {
        StateMachine stateMachine;
        sf::RenderWindow window;
        AssetManager assetManager;
        InputManager inputManager;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
        public:
            Game(int width, int height, std::string title);
        private:
            const float dt = 1.f / 60.f;
            sf::Clock _clock;

            GameDataRef _data = std::make_shared<GameData>();

            void Run();
    };
}