#include <vector>
#include "neuron.hpp"

struct layer
{
    std::vector<neuron> neurons;

    layer(std::vector<neuron> _neurons = {})
    {
        neurons = _neurons;
    }
};