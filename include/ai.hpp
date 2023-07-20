#include <SFML/System.hpp>
#include <array>
#include "neuralNetwork.hpp"

struct ai
{
    float health = 100;
    int fitness = 0; // 30 per 30 sec of survival and 10 per kill

    sf::Vector2f pos = {0, 0}; // Bottom left of map
    sf::Vector2i hitBoxSize = {10, 25};
    sf::Vector2f accel = {0, 0};
    char aimAngle = 0; // 0 is pointing right

    neuralNetwork nn;
    int gen = 0;

    ai(bool saveGeneration)
    {

    };
};

std::vector<int> saveGenChampion = {0, 10, 100, 500, 1'000, 2'000, 3'000, 4'000, 5'000, 6'000, 7'000, 8'000, 9'000, 10'000, 20'000};
const int AI_Count = 50;

ai champion; // store the previous generations neural network to build upon for the next generation
std::array<ai> AI_List;