#include "neuron.hpp"

namespace SirHoog
{
    Neuron::Neuron(float activation, std::vector<float> weights, int weightSize) : activation(activation)
    {
        if (weightSize > 0)
        {
            for (int i = 0; i < weightSize; i++)
            {
                weights.push_back(std::rand());
            }
        }
        else
        {
            this->weights = weights;
        }
    }
}