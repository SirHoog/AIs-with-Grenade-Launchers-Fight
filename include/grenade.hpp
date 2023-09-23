#include "entity.hpp"

namespace SirHoog
{
    class Grenade : public Entity
    {
        sf::Clock lifeTime;
        bool exploding = false;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};
            ~Grenade() {};

            void Update(sf::RenderWindow &window)
            {
                if (Impact)
                {
                    if (Position.y >= window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {
                        exploding = true;

                        // Render explosion gif
                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
                {
                    exploding = true;

                    // Render explosion gif
                }
            };

            bool isExploding() // I hate why I have to make an entire function just to return a variable
            {
                return exploding;
            }
    };
}