#include <stdint.h>
#include <vector>

namespace SirHoog
{
    class Neuron
    {
        public:
            float activation = 0;
            std::vector<float> weights = {};

            Neuron(float activation = 0, std::vector<float> weights = {}, uint8_t weightSize = 0)
            {
                this->activation = activation;

                if (weightSize > 0)
                {
                    for (uint8_t i = 0; i < weightSize; i++)
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