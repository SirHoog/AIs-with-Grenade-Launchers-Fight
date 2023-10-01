#include "grenade.hpp"

namespace SirHoog
{
    Grenade::Explode(AI &owner)
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

                if (Knockback)
                {
                    ai.Velocity -= (ai.Position - Position) * damage;
                }
            }
        }
    }
}