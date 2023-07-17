#include "vector2d.hpp"
#include "neuralNetwork.hpp"
#include "raycast.hpp"

struct ai
{
    int health = 100;

    vector2 prevPos = {0, 0};
    vector2 pos = {0, 0}; // Bottom left of map
    vector2 accel = {0, 0};
    vector2 aimVector = {0, 0};

    neuralNetwork brain;
    int gen = 0;

    void calculate()
    {
        // Output
        
        // Calculations

        // Update variables
    };

    void ai(bool saveGeneration)
    {
        calculate
    };
};

neuralNetwork prevGenNN; // store the previous generations neural network to build upon for the next generation
std::vector<neuralNetwork> AI_List;