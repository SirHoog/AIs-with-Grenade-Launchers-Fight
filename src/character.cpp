#include "character.hpp"

namespace SirHoog
{
    Character::Character
    (
        GameDataRef data,
        Animation animation,
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
        sf::Texture(),
        animation,
        Position,
        Velocity,
        affectedByGravity,
        bounces,
        friction,
        bounceAmount,
        frictionAmount
    )
    {
        // TODO: Render the grenade launcher

        data->assetManager.reset_cd("assets/AI/");

        data->assetManager.LoadTexture("AIIL", "Idle/Left.png");
        data->assetManager.LoadTexture("AIIR", "Idle/Right.png");

        data->assetManager.LoadTexture("AIML", "Move/Left.png");
        data->assetManager.LoadTexture("AIMR", "Move/Right.png");

        sprite.setTexture(data->assetManager.GetTexture("AIIR"));
        animation.Playing = true;
        
        CharacterList.push_back(this);
    };
    void Character::Update(float dt)
    {
        // OPTIMIZE
        // ORGANIZE

        if (Velocity.x > WalkSpeed / 2)
        {
            sprite.setTexture(data->assetManager.GetTexture("AIMR"));
        }
        else if (Velocity.x < -WalkSpeed / 2)
        {
            sprite.setTexture(data->assetManager.GetTexture("AIIR"));
        };

        if (Velocity.x < -WalkSpeed / 2)
        {
            sprite.setTexture(data->assetManager.GetTexture("AIML"));
        }
        else if (Velocity.x > WalkSpeed / 2)
        {
            sprite.setTexture(data->assetManager.GetTexture("AIIL"));
        };

        if (Velocity.y > JumpPower / 2)
        {
            if (Velocity.x > WalkSpeed / 2)
            {
                sprite.setTexture(data->assetManager.GetTexture("AIMR"));
            };
            if (Velocity.x < -WalkSpeed / 2)
            {
                sprite.setTexture(data->assetManager.GetTexture("AIML"));
            }
        };
        
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
        Grenade* grenade = new Grenade(data, Animation(), Position, sf::Vector2f(std::sin(aimAngle), std::cos(aimAngle)) * power);

        grenadeList.push_back(grenade);
    }
}