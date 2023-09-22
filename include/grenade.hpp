#include "entity.hpp"

namespace SirHoog
{
    bool Impact = false; // false = frag, true = impact
    bool RocketJumping = false;
    bool SelfDamage = false;
    int BlastRadius = 100;
    int MaxDamage = 35; // Idk why, but why not?
    float MaxLifeTime = 5; // Seconds

    class AI : public Entity {};

    class Grenade : public Entity
    {
        sf::Clock lifeTime;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};
            ~Grenade() {};

            void Update(sf::RenderWindow &window, AI &owner, std::vector<AI> &AI_List)
            {
                if (Impact)
                {
                    if (Position.y >= window.getSize().y - 5) // Just in case it's not perfectly at the bottom
                    {
                        Explode(window, owner, AI_List);
                    }
                }
                else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
                {
                    Explode(window, owner, AI_List);
                }
            };

            void Explode(sf::RenderWindow &window, AI &owner, std::vector<AI> &AI_List)
            {
                for (AI ai : AI_List)
                {
                    if (&owner == &ai && !SelfDamage)
                    {
                        return;
                    };
                    
                    float distance = std::sqrt(std::pow(Position.x - ai.Position.x, 2) + std::pow(Position.y - ai.Position.y, 2));

                    if (distance < BlastRadius)
                    {
                        float damage = (BlastRadius - distance) / BlastRadius;

                        ai.Health -= damage;

                        if (RocketJumping)
                        {
                            ai.Velocity -= (ai.Position - Position) * damage;
                        }
                    }
                }
            }
    };
}