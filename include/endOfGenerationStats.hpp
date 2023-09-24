#pragma once

#include <SFML/Graphics.hpp>
#include "GameEngine/state.hpp"
#include "GameEngine/game.hpp"

namespace SirHoog
{
    class GenerationStatsState : public State
    {
        GameDataRef data;
        sf::Clock _clock;
        sf::Texture backgroundTexture;
        sf::Sprite background;

        public:
            GenerationStatsState(GameDataRef);

            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Render(float dt);
    };
}