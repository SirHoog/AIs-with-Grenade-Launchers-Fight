#include "entity.hpp"

namespace SirHoog
{
    bool Impact = false; // false = frag, true = impact
    float MaxLifeTime = 5; // Seconds
    int BlastRadius = 100;
    int MaxDamage = 35; // Idk why, but why not?

    class AI : public Entity {};

    class Grenade : public Entity
    {
        sf::Clock lifeTime;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};
            ~Grenade() {};

            void Update(sf::RenderWindow &window, std::vector<AI> &AI_List)
            {
                if (Impact)
                {
                    if (Position.y >= window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {
                        Explode(window, AI_List);
                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
                {
                    Explode(window, AI_List);
                }
            };

            void Explode(sf::RenderWindow &window, std::vector<AI> &AI_List)
            {
                for (AI ai : AI_List)
                {
                    float distance = std::sqrt(std::pow(Position.x - ai.Position.x, 2) + std::pow(Position.y - ai.Position.y, 2));

                    if (distance < BlastRadius)
                    {
                        ai.TakeDamage((BlastRadius - distance) / BlastRadius, *this);
                    }
                }
            }
    };
}