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
        float elapsedTime = 0;
        float duration = 0;
        bool loop = true;
        bool horizontal = true;

        public:
            bool Playing = false;

            Animation();

            Animation
            (
                GameDataRef data,
                sf::Sprite sprite,
                sf::IntRect startFrame,
                sf::IntRect endFrame,
                float duration,
                bool loop = true,
                bool playing = false,
                bool horizontal = true
            );

            void Update(float dt);
            void Render(float interpolation);
    };
}