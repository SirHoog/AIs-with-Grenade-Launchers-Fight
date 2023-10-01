#include "entity.hpp"
#include "grenade.hpp"

namespace SirHoog
{
    class Character : public Entity
    {
        GameDataRef data;

        std::vector<Grenade> grenadeList = {};
        sf::Clock grenadeCooldown;

        public:
            float Health = 100;
            Character(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, GameDataRef data) : Entity(), data(data) {}
            ~Character() {};

            void LaunchGrenade(float aimAngle, float power) {};
    };
}