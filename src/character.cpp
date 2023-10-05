#include "character.hpp"

namespace SirHoog
{
    Character::Character
    (
        GameDataRef data,
        sf::Vector2f Position,
        sf::Vector2f Velocity,
        bool affectedByGravity,
        bool bounces,
        bool friction,
        float bounceAmount,
        float frictionAmount
    ) :
    Entity
    (
        data,
        Position,
        Velocity,
        affectedByGravity,
        bounces,
        friction,
        bounceAmount,
        frictionAmount
    )
    {};
    void Character::Update(float dt)
    {
        Entity::Update(dt);

        if (Health <= 0)
        {
            delete this;
        }
    };
    void Character::Render(float interpolation, sf::Texture spriteTexture)
    {
        Entity::Render(interpolation, spriteTexture);
    };

    void Character::LaunchGrenade(float aimAngle, float power)
    {
        Grenade *grenade = new Grenade(data, Position, sf::Vector2f(std::sin(aimAngle), std::cos(aimAngle)) * power, true, true, true, 0.5, 0.25);

        grenadeList.push_back(*grenade);
    }
}