#include "entity.hpp"

namespace SirHoog
{
    void Entity::Update()
    {
        Position += Velocity;
        Velocity = {0, 0};

        if (affectedByGravity)
        {
            Velocity -= {0, GravitationalConstant}; // Not negative since SFML Y axis is flipped
        };

        Position.x = std::clamp(Position.x, (float)0, (float)data->window.getSize().x);
        Position.y = std::clamp(Position.y, (float)0, (float)data->window.getSize().y);
    };
    void Entity::Render(float interpolation, sf::Texture spriteTexture)
    {
        sprite.setTexture(spriteTexture);
        sprite.setOrigin(spriteTexture.getSize().x / 2.f, spriteTexture.getSize().y); // Middle bottom

        data->window.draw(sprite);

        data->window.display();
    }
}