#pragma once

#include <SFML/Graphics.hpp>
#include "GameEngine/game.hpp"
#include "definitions.hpp"

namespace SirHoog
{
    class Animation
    {
        GameDataRef data;

        sf::Sprite sprite;

        sf::IntRect startFrame;
        sf::IntRect currentFrame;
        sf::IntRect endFrame;
        float elapsedTime;
        float duration;
        bool loop = true;
        bool horizontal = true;

        public:
            Animation();

            Animation
            (
                GameDataRef data,
                sf::Sprite sprite,
                sf::IntRect startFrame,
                sf::IntRect endFrame,
                float duration,
                bool loop = true,
                bool horizontal = true
            );
            ~Animation();

            void Update(float dt);
            void Render(float interpolation);
    };
}