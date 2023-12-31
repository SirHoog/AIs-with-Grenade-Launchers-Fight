#pragma once

#include <vector>
#include <random>

namespace SirHoog
{
    class Neuron
    {
        public:
            float activation = 0;
            std::vector<float> weights = {};

            Neuron(float activation = 0, std::vector<float> weights = {}, int weightSize = 0);
    };
}