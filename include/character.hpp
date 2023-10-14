#pragma once

#include "grenade.hpp"

// MADE TO: Share the same stuff with the AI class and player class
// PIN: // CREATE: a player class

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
                Animation animation = Animation(),
                sf::Texture spriteTexture = sf::Texture(),
                sf::Vector2f Position = sf::Vector2f(0, 0),
                sf::Vector2f Velocity = sf::Vector2f(0, 0),
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~Character() {};

            void Update(float dt);
            void Render(float interpolation);

            void LaunchGrenade(float aimAngle, float power);
        protected:
            std::vector<Grenade> grenadeList = {};
            sf::Clock grenadeCooldown;
    };

    static std::vector<Character> CharacterList;
}