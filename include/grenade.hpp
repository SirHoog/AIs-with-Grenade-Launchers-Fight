#include "entity.hpp"

namespace SirHoog
{
    bool impact = false; // false = frag, true = impact
    float maxLifeTime = 5; // Seconds
    int blastRadius = 100;
    int maxDamage = 75;

    class AI : public Entity {};

    class Grenade : public Entity
    {
        sf::Clock lifeTime;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};
            ~Grenade() {};

            void Update(sf::RenderWindow &window, std::vector<AI> &AI_List)
            {
                if (impact)
                {
                    if (Position.y >= window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {
                        Explode(window, AI_List);
                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= maxLifeTime)
                {
                    Explode(window, AI_List);
                }
            };

            void Explode(sf::RenderWindow &window, std::vector<AI> &AI_List)
            {
                for (AI ai : AI_List)
                {
                    float distance = std::sqrt(std::pow(Position.x - ai.Position.x, 2) + std::pow(Position.y - ai.Position.y, 2));

                    if (distance < blastRadius)
                    {
                        ai.TakeDamage((blastRadius - distance) / blastRadius, *this);
                    }
                }
            }
    };
}