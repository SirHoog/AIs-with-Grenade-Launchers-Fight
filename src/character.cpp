#include "character.hpp"

namespace SirHoog
{
    void Character::LaunchGrenade(float aimAngle, float power)
    {
        grenadeList.push_back(Grenade(Position, sf::Vector2f(std::sin(aimAngle), std::cos(aimAngle)) * power, true, data));
    }
}