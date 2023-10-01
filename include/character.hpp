#include "entity.hpp"
#include "grenade.hpp"

// Made this class to share the same stuff with the AI class and Player class

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

            void Update() {};
            void Render(float interpolation, sf::Texture spriteTexture) {};

            void LaunchGrenade(float aimAngle, float power) {};
    };
}