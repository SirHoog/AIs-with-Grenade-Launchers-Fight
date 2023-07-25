#include <vector>
#include <random>
#include "xtensor/xarray.hpp"

struct neuron
{
    float activation;
    std::vector<float> weights;

    neuron(float _activation, std::vector<float> _weights, int wCount = 0)
    {
        activation = _activation;
        
        if (_weights.empty())
        {
            for (int i = 0; i < wCount; i++)
            {
                weights.push_back(rand());
            }
        }
        else
        {
            weights = _weights;
        }
    };

    neuron operator+(neuron& other)
    {
        std::vector<float> w = weights;

        for (int i = 0; i < sizeof(w); i++)
        {
            w[i] += other.weights[i];
        };

        neuron n(activation + other.activation, w);

        return n;
    };

    neuron operator-(neuron& other)
    {
        std::vector<float> w = weights;

        for (int i = 0; i < sizeof(w); i++)
        {
            w[i] -= other.weights[i];
        };

        neuron n(activation - other.activation, w);

        return n;
    };
};