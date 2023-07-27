#include <vector>
#include <random>
#include "xtensor/xarray.hpp"

struct neuron
{
    float activation;
    float biasTerm = 0.5;
    std::vector<float> weights;

    neuron(float _activation, float _biasTerm, std::vector<float> _weights = {}, int weightCount = 0)
    {
        activation = _activation;
        biasTerm = _biasTerm;

        if (_weights.empty())
        {
            for (int i = 0; i < weightCount; i++)
            {
                weights.push_back(rand());
            }
        }
        else
        {
            weights = _weights;
        }
    }
};