#include "character.hpp"

namespace SirHoog
{
    Character::Character
    (
        GameDataRef data,
        Animation animation,
        sf::Texture spriteTexture,
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
        animation,
        spriteTexture,
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
    void Character::Render(float interpolation)
    {
        Entity::Render(interpolation);
    };

    void Character::LaunchGrenade(float aimAngle, float power)
    {
        Grenade *grenade = new Grenade(data, Animation(), sf::Texture(), Position, sf::Vector2f(std::sin(aimAngle), std::cos(aimAngle)) * power);

        grenadeList.push_back(*grenade);
    }
}