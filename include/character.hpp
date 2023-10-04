#include "entity.hpp"
#include "grenade.hpp"

// Made this class to share the same stuff with the AI class and Player class

namespace SirHoog
{
    class Character : public Entity
    {
        GameDataRef data;

        public:
            float Health = 100;
            Character(GameDataRef data, sf::Vector2f Position, sf::Vector2f Velocity, bool affectedByGravity, bool bounces, bool friction, float bounceAmount, float frictionAmount) : Entity() {}
            ~Character() {};

            void Update(float dt) {};
            void Render(float interpolation, sf::Texture spriteTexture) {};

            void LaunchGrenade(float aimAngle, float power) {};
        protected:
            std::vector<Grenade> grenadeList = {};
            sf::Clock grenadeCooldown;
    };

    std::vector<Character> CharacterList;
}