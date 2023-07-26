#include <vector>
#include "neuron.hpp"

struct layer
{
    
    float bias = 0.5;
    std::vector<neuron> neurons;

    layer(std::vector<neuron> _neurons = {}, float _bias = 0.5)
    {
        bias = _bias;
        neurons = _neurons;
    };
};