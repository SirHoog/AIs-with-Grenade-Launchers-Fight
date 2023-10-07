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
        const float RenderSpeed = 1.f / 60.f; // USED TO: Maintain 60 FPS
        sf::Clock _clock;

        GameDataRef data = std::make_shared<GameData>();

        void Run();

        public:
            Game(int width, int height, std::string title);
    };
}