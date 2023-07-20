#include <vector>
#include <string>
#include <random>
#include <fstream>
#include "json.hpp"

struct neuron
{
    float activation = rand();
    std::vector<int> weights;
};

struct neuralNetwork
{
    

    neuralNetwork(std::string JSON_FileName)
    {
        std::ifstream file(JSON_FileName);
        json
    };
};