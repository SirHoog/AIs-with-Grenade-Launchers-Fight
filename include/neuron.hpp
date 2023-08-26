#pragma once

#include <vector>
#include <random>

struct neuron
{
    float activation;
    std::vector<float> weights;

    neuron(float _activation, std::vector<float> _weights = {}, int weightCount = 0)
    {
        activation = _activation;

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