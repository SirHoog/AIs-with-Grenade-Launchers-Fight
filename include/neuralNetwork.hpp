#include <vector>
#include <string>
#include <random>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct neuron
{
    std::string valueName = "";
    float a; // Activation
    std::vector<float> w; // Weights

    neuron(std::string _valueName, float _a, int wCount)
    {
        valueName = _valueName;
        a = _a;
        
        for (int i = 0; i < wCount; i++)
        {
            w.push_back(rand());
        };
    };
};

struct neuralNetwork
{
    std::array<neuron, 5> input =
    {
        neuron("X", rand(), 5), // Position X
        neuron("Y", rand(), 5), // Position Y
        neuron("eX", rand(), 5), // Closest enemy X
        neuron("eY", rand(), 5), // Closest enemy Y
        neuron("g", rand(), 5)  // Distance from Closest Enemy Grenade
    };
    std::array<std::array<neuron, 5>, 1> hiddenLayers =
    {
        {}
    };

    void calculateOutput()
    {
        
    };

    void mutate(json nn, int mutationAmount)
    {

    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file(JSON_FileName);

        json parsedFile = json::parse(file);

        for ()
    };

    void write(std::string JSON_FileName, std::string jsonCode)
    {

    };
};