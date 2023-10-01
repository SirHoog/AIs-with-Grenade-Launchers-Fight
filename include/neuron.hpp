#pragma once

#include <vector>

namespace SirHoog
{
    class Neuron
    {
        public:
            float activation = 0;
            std::vector<float> weights = {};

            Neuron(float activation = 0, std::vector<float> weights = {}, int weightSize = 0)
            {
                this->activation = activation;

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
    };
}