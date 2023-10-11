#pragma once

#include <cmath>
#include "entity.hpp"

namespace SirHoog
{
    class Character;

    class Grenade : public Entity
    {
        GameDataRef data;

        sf::Clock lifeTime;
        
        bool exploded = false;
        float sinceExploded = 0;

        public:
            Grenade
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
            ~Grenade() {};

            void Update(float dt, Character &owner);
            void Render(float interpolation);

            void Explode(Character &owner);
    };
}