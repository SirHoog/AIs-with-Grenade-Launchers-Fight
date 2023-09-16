#include <random>
#include "grenade.hpp"
#include "neuralNetwork.hpp"

namespace SirHoog
{
    class AI: Entity
    {
        float health = 100;
        int fitness = 0;
        sf::Color color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
        float aimAngle = 0;
        float power = 0;
        std::vector<Grenade> grenadeList
    };
}