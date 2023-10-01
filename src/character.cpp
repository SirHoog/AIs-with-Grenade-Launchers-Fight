#include "character.hpp"

namespace SirHoog
{
    void Character::Update()
    {
        Entity::Update();

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
        grenadeList.push_back(Grenade(Position, sf::Vector2f(std::sin(aimAngle), std::cos(aimAngle)) * power, true, data));
    }
}