#include "character.hpp"

namespace SirHoog
{
    Grenade::Grenade
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
    {
        data->assetManager.LoadTexture("Explosion", assetsPath + "Grenade/explosionSpritesheet.png");
        data->assetManager.LoadTexture("Grenade", assetsPath + "Grenade/grenade.png");
    };

    void Grenade::Update(Character &owner, float dt)
    {
        Entity::Update(dt);

        if (!exploded)
        {
            if (Impact)
            {
                if (Position.y >= data->window.getSize().y)
                {
                    Explode(owner); // If you read it, it sounds like it explodes the owner, but, no, that's not the case XD
                }
            }
            else if (lifeTime.getElapsedTime().asSeconds() >= MaxLifeTime)
            {
                Explode(owner);
            }
        }
        else
        {
            float updateSpeed = TPS / DefaultTPS;

            sinceExploded += dt * updateSpeed;
        }
    };
    void Grenade::Render(float interpolation)
    {
        if (exploded)
        {
            sf::Texture explosion = data->assetManager.GetTexture("Explosion");
            float frameWidth = explosion.getSize().y;
            int frame = std::round(sinceExploded * explosion.getSize().x / frameWidth);
            float frameLocationX = frame * frameWidth;

            sprite.setTexture(explosion);
            sprite.setTextureRect(sf::IntRect(sf::Vector2i(frameLocationX, 0), sf::Vector2i(explosion.getSize().y, explosion.getSize().y)));
            sprite.setOrigin(explosion.getSize().x / 2.f, explosion.getSize().y); // Middle bottom
            sprite.setScale({5, 5});

            data->window.draw(sprite);
            data->window.display();
        }
        else
        {
            Entity::Render(interpolation, data->assetManager.GetTexture("Grenade"));
        }
    };

    void Grenade::Explode(Character &owner)
    {
        exploded = true;

        for (Character character : CharacterList)
        {
            if (&owner == &character && !SelfDamage)
            {
                return;
            };
            
            float distance = std::sqrt(std::pow(Position.x - character.Position.x, 2) + std::pow(Position.y - character.Position.y, 2));

            if (distance < BlastRadius)
            {
                float damage = (BlastRadius - distance) / BlastRadius;

                character.Health -= damage;

                if (Knockback)
                {
                    character.Velocity -= (character.Position - Position) * damage;
                }
            }
        }
    }
}