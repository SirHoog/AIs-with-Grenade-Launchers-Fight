#include "neuron.hpp"

namespace SirHoog
{
    Neuron::Neuron(float activation = 0, std::vector<float> weights = {}, int weightSize = 0)
    {
        if (weightSize > 0)
        {
            for (int i = 0; i < weightSize; i++)
            {
                weights.push_back(0.f);
            }
        }
        else
        {
            this->weights = weights;
        }
    }
}