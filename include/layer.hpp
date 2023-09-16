#include "neuron.hpp"

namespace SirHoog
{
    class Layer
    {
        public:
            std::vector<Neuron> neurons;

            Layer(std::vector<Neuron> neurons = {}): neurons(neurons) {};
    };
}