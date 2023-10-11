#include "entity.hpp"

namespace SirHoog
{
    Entity::Entity
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
    data(data),
    spriteTexture(spriteTexture),
    animation(animation),
    Position(Position),
    affectedByGravity(affectedByGravity),
    bounces(bounces),
    friction(friction),
    bounceAmount(bounceAmount),
    frictionAmount(frictionAmount)
    {
        animation = Animation(data, sprite, sf::IntRect(sf::Vector2i(0, 0), (sf::Vector2i)spriteTexture.getSize()), sf::IntRect(sf::Vector2i(0, 0), (sf::Vector2i)spriteTexture.getSize()), 0, false, false); // Not changing
    };
    
    void Entity::Update(float dt)
    {
        animation.Update(dt);

        Position += Velocity;

        Position.x = std::clamp(Position.x, (float)0, (float)data->window.getSize().x);
        Position.y = std::clamp(Position.y, (float)0, (float)data->window.getSize().y);
    
        if (bounces)
        {
            if (Position.x == 0)
            {
                Velocity.x = std::abs(Velocity.x);
            };
            if (Position.x == data->window.getSize().x)
            {
                Velocity.x = std::abs(Velocity.x);
            };
            if (Position.y == 0)
            {
                Velocity.y = std::abs(Velocity.y);
            };
            if (Position.y == data->window.getSize().y)
            {
                Velocity.y = -std::abs(Velocity.y);
            };

            Velocity *= bounceAmount; // PURPOSE: Loses some energy from impact
        };
        if (affectedByGravity)
        {
            Velocity.y -= GravitationalConstant; // PURPOSE: Not negative because SFML uses an inverted Y axis
        };
        if (Position.y == data->window.getSize().y)
        {
            if (friction)
            {
                Velocity.x -= Velocity.x * frictionAmount;
            }
            else
            {
                Velocity.x = 0;
            }
        };
    };
    void Entity::Render(float interpolation)
    {
        sprite.setTexture(spriteTexture);
        sprite.setOrigin(spriteTexture.getSize().x / 2.f, spriteTexture.getSize().y); // Middle bottom

        animation.Render(interpolation);

        data->window.draw(sprite);
    }
}