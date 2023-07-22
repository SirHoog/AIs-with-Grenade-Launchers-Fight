#include <SFML/System.hpp>
#include <array>
#include <random>
#include "map.hpp"
#include "neuralNetwork.hpp"
#include "nlohmann/json.hpp"

struct ai
{
    float health = 100;
    int fitness = 0; // 30 per 30 sec of survival and 10 per kill
    sf::Color color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
    sf::Vector2f pos = {rand() % map.size.x, rand() % map.size.y};
    sf::Vector2f accel = {0, 0};
    float aimAngle = 0; // 0 is pointing right, and positive is clockwise

    neuralNetwork nn;
    int gen;

    ai(int _gen, neuralNetwork _nn)
    {
        gen = _gen;
        nn = _nn;
    };
};

std::vector<int> saveGenChampion = {0, 1, 2, 3, 4, 5, 10, 20, 50, 75, 100, 200, 300, 400, 500};
const int AI_Count = 50;
std::vector<ai> AI_List;