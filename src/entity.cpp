#include "entity.hpp"

namespace SirHoog
{
    Entity::Entity(GameDataRef data, sf::Vector2f Position, sf::Vector2f Velocity, bool affectedByGravity, bool bounces, bool friction, float bounceAmount, float frictionAmount)
    {
        this->data = data;
        
        this->Position = Position;
        this->Velocity = Velocity;

        this->affectedByGravity = affectedByGravity;
        this->bounces = bounces;
        this->friction = friction;

        this->bounceAmount = bounceAmount;
        this->frictionAmount = frictionAmount;
    };
    
    void Entity::Update(float dt)
    {
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
                Velocity.y = -std::abs(Velocity.y); // Makes it negative because SFML uses an inverted Y axis
            };

            Velocity *= bounceAmount; // Loses some energy
        };
        if (affectedByGravity)
        {
            Velocity.y -= GravitationalConstant; // Not negative because SFML uses an inverted Y axis
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
    void Entity::Render(float interpolation, sf::Texture spriteTexture)
    {
        sprite.setTexture(spriteTexture);
        sprite.setOrigin(spriteTexture.getSize().x / 2.f, spriteTexture.getSize().y); // Middle bottom

        data->window.draw(sprite);
        data->window.display();
    }
}