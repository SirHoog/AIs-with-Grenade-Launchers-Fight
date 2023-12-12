#include "entity.hpp"

namespace SirHoog
{
    Entity::Entity
    (
        GameDataRef data,
        sf::Texture spriteTexture,
        Animation animation,
        sf::Vector2f Position,
        sf::Vector2f Velocity,
        bool affectedByGravity,
        bool bounces,
        bool friction,
        float bounceAmount,
        float frictionAmount
    ) :
    data(data),
    animation(animation),
    Position(Position),
    affectedByGravity(affectedByGravity),
    bounces(bounces),
    friction(friction),
    bounceAmount(bounceAmount),
    frictionAmount(frictionAmount)
    {
        sprite = sf::Sprite(spriteTexture, sf::IntRect(0, 0, spriteTexture.getSize().x, spriteTexture.getSize().y));

        animation = Animation(data, sprite, sf::IntRect(sf::Vector2i(0, 0), (sf::Vector2i)spriteTexture.getSize()), sf::IntRect(sf::Vector2i(0, 0), (sf::Vector2i)spriteTexture.getSize()), 0, false, false, false); // Not changing
    };
    
    void Entity::Update(float dt)
    {
        animation.Update(dt);

        Position += Velocity;

        Position = sf::Vector2f(
            std::clamp(Position.x, (float)0, (float)WindowWidth),
            std::clamp(Position.y, (float)0, (float)WindowHeight)
        );
    
        if (bounces)
        {
            if (Position.x == 0)
            {
                Velocity.x = std::abs(Velocity.x);
            };
            if (Position.x == WindowWidth)
            {
                Velocity.x = std::abs(Velocity.x);
            };
            if (Position.y == 0)
            {
                Velocity.y = std::abs(Velocity.y);
            };
            if (Position.y == WindowHeight)
            {
                Velocity.y = -std::abs(Velocity.y);
            };

            Velocity *= bounceAmount; // PURPOSE: Loses some energy from impact
        };
        if (affectedByGravity)
        {
            Velocity.y -= Gravity; // PURPOSE: Not negative because SFML uses an inverted Y axis
        };
        if (Position.y == WindowHeight)
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
        sprite.setOrigin(sprite.getTexture()->getSize().x / 2.f, sprite.getTexture()->getSize().y); // Middle bottom

        animation.Render(interpolation);

        data->window.draw(sprite);
    }
}