#include <string>
#include <fstream>
#include <iostream>
#include "layer.hpp"
#include <NC/NumCpp/NdArray.hpp>
#include <NC/NumCpp/Functions/append.hpp>

namespace SirHoog
{
    class NeuralNetwork
    {
        std::vector<Layer> layers;

        public:
            NeuralNetwork(std::string fileName = "", uint8_t inputSize = 0, uint8_t hiddenLayerCount = 0, uint8_t hiddenLayerSize = 0, uint8_t outputSize = 0)
            {
                if (!fileName.empty())
                {
                    ReadFromFile(fileName);
                }
                else
                {
                    Layer input;
                    Layer output;

                    for (int i = 0; i < inputSize + 1; i++) // + 1 because of the bias neuron
                    {
                        input.neurons.push_back(Neuron(0 + (i == inputSize), {}, hiddenLayerSize)); // I did `0 + (i == inputSize)` instead of doing an if statement. It's to check if it's the last neuron (bias neuron / term) and set it's value to 1
                    };

                    layers.push_back(input);

                    for (int i = 0; i < hiddenLayerCount; i++)
                    {
                        Layer hidden;

                        for (int j = 0; j < hiddenLayerSize + 1; j++)  // + 1 because of the bias neuron
                        {
                            hidden.neurons.push_back(Neuron(0 + (i == hiddenLayerSize), {}, outputSize)); // Same as the input layer pretty much
                        };
                        
                        layers.push_back(hidden);
                    };

                    for (int i = 0; i < outputSize; i++) // No + 1, because output doesn't have bias neuron ofc
                    {
                        output.neurons.push_back(Neuron(0, {}, 0));
                    };

                    layers.push_back(output);
                }
            };
            Layer Update(std::vector<float> _input) // Forward Propagation
            {
                // https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
                // Formula: layer = tanh(weights * activations + bias) // tanh means hyperbolic tangent and it's sorta like a sigmoid, but instead of ranging from 0 to 1, it ranges from -1 to 1

                nc::NdArray<float> a;
                nc::NdArray<float> w;
                nc::NdArray<float> b;

                for (int i = 0; i < _input.size(); i++) // Do not subtract 1, because `_input` doesn't include the bias neuron / bias term ofc
                {
                    layers[0].neurons[i].activation = tanh(_input[i]); // normalize input
                };

                std::vector<Neuron> temp = layers[0].neurons;

                nc::append(b, static_cast<nc::NdArray<float>>(temp[temp.size()].weights)); // im not sure if the `b` vector is filled with bias activations or bias weights, but bias weights makes the most sense

                for (int i = 1; i < layers.size(); i++) // For every layer // i = 1 to skip the input layer
                {
                    Layer pLayer = layers[i - 1]; // p: previous
                    Layer cLayer = layers[i]; // c: current

                    for (int j = 0; j < pLayer.neurons.size() - 1; j++) // For every neuron in pLayer // Subtract 1 to not include bias neuron / bias term
                    {
                        nc::NdArray<float> rowOfWeights; 

                        a.fill(pLayer.neurons[j].activation); // a

                        for (int k = 0; k < cLayer.neurons.size(); k++)
                        {
                            rowOfWeights.fill(pLayer.neurons[j].weights[k]);
                        };

                        nc::append(w, rowOfWeights); // w
                    };

                    nc::NdArray<float> layerActivations = ((w.dot(a)) + b); // not done yet, gotta chuck it in the tanh function

                    for (int j = 0; j < layerActivations.shape().rows; j++) // tanh loop
                    {
                        layerActivations[j] = tanh(layerActivations[j]);
                    }
                };

                return layers.back();
            }
            void ReadFromFile(std::string fileName)
            {
                std::string line;
                std::ifstream file("savedNeuralNetworks\\" + fileName); // `i` stands for in

                if (file.is_open())
                {
                    int inputSize = 0;
                    int hiddenLayerCount = 0;
                    int hiddenLayerSize = 0;
                    int outputSize = 0;
                    std::string binary;

                    // std::getline(file, line); // Continue when you need this function
                }
                else
                {
                    std::cout << "Unable to open file";
                };

                file.close();
            };
            void WriteToFile(std::string fileName)
            {

            };
            std::string FromBinary()
            {

            };
            std::string ToBinary()
            {

            };
    };
}