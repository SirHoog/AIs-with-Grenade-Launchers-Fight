#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <xtensor/xtensor.hpp>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct neuron
{
    float a; // Activation
    std::vector<float> w; // Weights

    neuron(float _a, int wCount)
    {
        a = _a;
        
        for (int i = 0; i < wCount; i++)
        {
            w.push_back(rand());
        }
    }
};

struct neuralNetwork
{
    std::array<neuron, 5> input =
    {
        neuron(0, 5), // Position X
        neuron(0, 5), // Position Y
        neuron(0, 5), // Closest enemy X
        neuron(0, 5), // Closest enemy Y
        neuron(0, 5)  // Distance from Closest Enemy Grenade
    };
    std::array<std::array<neuron, 5>, 1> hiddenLayers =
    {
        {
            neuron()
        }
    };

    void propagateForward(std::array<neuron, 5> _input)
    {
        xt
    };

    void mutate(json nn, int mutationAmount)
    {

    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file(JSON_FileName);

        json parsedFile = json::parse(file);


    };

    void write(std::string JSON_FileName, std::string jsonCode)
    {

    }
};