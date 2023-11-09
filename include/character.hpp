#pragma once

#include "grenade.hpp"

// MADE TO: Share the same stuff with the AI class and player class
// PIN: // CREATE: a player class

namespace SirHoog
{
    class Character : public Entity
    {
        public:
            float Health = 100;
            
            Character
            (
                GameDataRef data,
                Animation animation = Animation(),
                sf::Vector2f Position = sf::Vector2f(0, 0),
                sf::Vector2f Velocity = sf::Vector2f(0, 0),
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~Character() {};

            virtual void Update(float dt) override;
            virtual void Render(float interpolation) override;

            void LaunchGrenade(float aimAngle, float power);
        protected:
            std::vector<Grenade> grenadeList = {};
            sf::Clock grenadeCooldown;
    };

    static std::vector<Character> CharacterList;
}