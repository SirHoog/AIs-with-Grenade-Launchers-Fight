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
                sf::Vector2f Position = {0, 0},
                sf::Vector2f Velocity = {0, 0},
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~Grenade() {};

            void Update(Character &owner, float dt);
            void Render(float interpolation);

            void Explode(Character &owner);
    };
}