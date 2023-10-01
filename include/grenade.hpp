#include <cmath>
#include "entity.hpp"

namespace SirHoog
{
    class Grenade : public Entity
    {
        GameDataRef data;

        sf::Clock lifeTime;

        public:
            Grenade(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, GameDataRef data) : Entity(), data(data) {};
            ~Grenade() {};

            // void Update(AI &owner, std::vector<AI> &AI_List) {};
            // void Render() {};
            // void Explode(AI &owner, std::vector<AI> &AI_List) {};
    };
}