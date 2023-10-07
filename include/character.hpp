#pragma once

#include "grenade.hpp"

// MADE TO: Share the same stuff with the AI class and player class
// CREATE: a player class // PIN

namespace SirHoog
{
    class Character : public Entity
    {
        GameDataRef data;

        public:
            float Health = 100;
            Character
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
            ~Character() {};

            void Update(float dt);
            void Render(float interpolation, sf::Texture spriteTexture);

            void LaunchGrenade(float aimAngle, float power);
        protected:
            std::vector<Grenade> grenadeList = {};
            sf::Clock grenadeCooldown;
    };

    static std::vector<Character> CharacterList;
}