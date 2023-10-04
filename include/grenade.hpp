#include <cmath>
#include "entity.hpp"

namespace SirHoog
{
    class Character : public Entity {};

    class Grenade : public Entity
    {
        GameDataRef data;

        sf::Clock lifeTime;
        
        bool exploded = false;
        float sinceExploded = 0;

        public:
            Grenade(GameDataRef data, sf::Vector2f Position, sf::Vector2f Velocity, bool affectedByGravity, bool bounces, bool friction, float bounceAmount, float frictionAmount) : Entity() {};
            ~Grenade() {};

            void Update(Character &owner, float dt) {};
            void Render(float interpolation) {};

            void Explode(Character &owner) {};
    };
}