#pragma once

#include <algorithm>
#include "animation.hpp"

namespace SirHoog
{
    class Entity
    {
        GameDataRef data;

        bool affectedByGravity = true;
        bool bounces = false;
        bool friction = false;

        float bounceAmount = 0.5; // STATES: 1 = Transfer all velocity in direction of bounce
        float frictionAmount = 0.25; // STATES: 1 = Instant stop
        

        public:
            sf::Sprite sprite;
            sf::Texture spriteTexture;
            Animation animation;
            sf::Vector2f Position = sf::Vector2f(0, 0);
            sf::Vector2f Velocity = sf::Vector2f(0, 0);

            Entity
            (
                GameDataRef data,
                Animation animation,
                sf::Texture spriteTexture = sf::Texture(),
                sf::Vector2f Position = sf::Vector2f(0, 0),
                sf::Vector2f Velocity = sf::Vector2f(0, 0),
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~Entity() {};

            void Update(float dt);
            void Render(float interpolation);
    };
}