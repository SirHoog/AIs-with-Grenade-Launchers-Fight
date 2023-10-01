#include <cmath>
#include "entity.hpp"

namespace SirHoog
{
    class AI : public Entity {};

    class Grenade : public Entity
    {
        GameDataRef data;

        sf::Clock lifeTime;
        bool exploding = false;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, GameDataRef data) : Entity(), data(data) {};
            ~Grenade() {};

            void Update()
            {
                if (Impact)
                {
                    if (Position.y >= data->window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {
                        exploding = true;
                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
                {
                    exploding = true;
                }
            };
            void Render() {};
            void Explode(AI &owner) {};
    };
}