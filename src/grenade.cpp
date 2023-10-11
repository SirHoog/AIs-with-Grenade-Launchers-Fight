#include "character.hpp"

namespace SirHoog
{
    Grenade::Grenade
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
    {
        data->assetManager.LoadTexture("Explosion", assetsPath + "Grenade/explosionSpritesheet.png");
        data->assetManager.LoadTexture("Grenade", assetsPath + "Grenade/grenade.png");
    };

    void Grenade::Update(float dt, Character &owner)
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

            spriteTexture = explosion;
            animation = Animation(data, sprite, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(spriteTexture.getSize().y, spriteTexture.getSize().y)), sf::IntRect(sf::Vector2i(spriteTexture.getSize().x, 0), sf::Vector2i(spriteTexture.getSize().y, spriteTexture.getSize().y)), 1, false);
        };

        Entity::Render(interpolation);
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