#include <SFML/System.hpp>
#include <vector>
#include "neuralNetwork.hpp"
#include "raycast.hpp"

struct ai
{
    int health = 100;

    sf::Vector2 prevPos = {0, 0};
    sf::Vector2 pos = {0, 0}; // Bottom left of map
    sf::Vector2 hitBoxSize = {10, 25};
    sf::Vector2 accel = {0, 0};
    sf::Vector2 aimVector = {0, 0};

    neuralNetwork nn;
    int gen = 0;

    void calculate()
    {
        // Output
        
        // Calculations

        // Update variables
    };

    ai(bool saveGeneration)
    {
        calculate();

        AI_List.push_back(nn);
    };
};

neuralNetwork prevGenNN; // store the previous generations neural network to build upon for the next generation
std::vector<neuralNetwork> AI_List;