#include "entity.hpp"
#include "GameEngine/assetManager.hpp"

namespace SirHoog
{
    bool impact = false; // false = frag, true = impact
    float maxLifeTime = 5; // Seconds
    int blastRadius = 200;
    int maxDamage = 75;
    std::vector

    class Grenade: Entity
    {
        sf::Clock LifeTime;

        public:
            void Update(sf::RenderWindow &window)
            {
                if (impact)
                {
                    if (pos.y >= window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {

                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= maxLifeTime)
                {
                    
                }
            };

            void Explode(sf::RenderWindow &window)
            {
                
            }
    };
}