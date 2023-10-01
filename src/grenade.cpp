#include "grenade.hpp"

namespace SirHoog
{
    // void Grenade::Update(AI &owner, std::vector<AI> &AI_List)
    // {
    //     Entity::Update();

    //     if (Impact)
    //     {
    //         if (Position.y >= data->window.getSize().y - 5) // Just in case it's not perfectly at the bottom
    //         {
    //             Explode(owner, AI_List);
    //         }
    //     }
    //     else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
    //     {
    //         Explode(owner, AI_List);
    //     }
    // }
    // void Grenade::Explode(AI &owner, std::vector<AI> &AI_List)
    // {
    //     for (AI ai : AI_List)
    //     {
    //         if (&owner == &ai && !SelfDamage)
    //         {
    //             return;
    //         };
            
    //         float distance = std::sqrt(std::pow(Position.x - ai.Position.x, 2) + std::pow(Position.y - ai.Position.y, 2));

    //         if (distance < BlastRadius)
    //         {
    //             float damage = (BlastRadius - distance) / BlastRadius;

    //             ai.Health -= damage;

    //             if (Knockback)
    //             {
    //                 ai.Velocity -= (ai.Position - Position) * damage;
    //             }
    //         }
    //     }
    // }
}