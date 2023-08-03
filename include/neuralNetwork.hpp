#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <fstream>
#include <xtensor/xarray.hpp>
#include <xtensor/xjson.hpp>
#include <xtensor/xview.hpp>
#include "nlohmann/json.hpp"
#include "layer.hpp"

using json = nlohmann::json;

int TPC = 5; // Ticks per calculation

struct neuralNetwork
{
    std::vector<layer> layers;

    neuralNetwork(std::string fileName = "", int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0)
    {
        if (fileName != "")
        {
            read(fileName);
        }
        else
        {
            layer input;
            layer output;

            for (int i = 0; i < inputSize + 1; i++) // + 1 because of the bias neuron
            {
                input.neurons.push_back(neuron(0 + (i == inputSize), {}, hiddenLayerSize)); // I did `0 + (i == inputSize)` instead of doing an if statement. It's to check if it's the last neuron (bias neuron / term) and set it's value to 1
            };

            layers.push_back(input);

            for (int i = 0; i < hiddenLayerCount; i++)
            {
                layer hidden;

                for (int j = 0; j < hiddenLayerSize + 1; j++)  // + 1 because of the bias neuron
                {
                    hidden.neurons.push_back(neuron(0 + (i == hiddenLayerSize), {}, outputSize)); // Same as the input layer pretty much
                };
                
                layers.push_back(hidden);
            };

            for (int i = 0; i < outputSize; i++) // No + 1, because output doesn't have bias neuron ofc
            {
                output.neurons.push_back(neuron(0, {}, 0));
            };

            layers.push_back(output);
        }
    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file("savedNeuralNetworks\\" + JSON_FileName); // `i` stands for `in`

        json parsedFile = json::parse(file);

        for (int i = 0; i < parsedFile.size(); i++) // For every layer in file
        {
            layer temp;
            
            if (i != parsedFile.size()) { // If i is not output layer
                for (int j = 0; j < parsedFile[i].size(); j++)
                {
                    json neuronJ = parsedFile[i][j];
                    neuron neuronN(0, {}, neuronJ.size());

                    for (int k = 0; k < neuronJ.size(); k++)
                    {
                        neuronN.weights[k] = neuronJ[k];
                    };

                    temp.neurons.push_back(neuronN);
                }
            }
            else
            {
                for (int j = 0; j < parsedFile[i][0]; j++) // The first value in `parsedFile[i]` (the output layer) is just the amount of neurons in the output layer
                {
                    temp.neurons.push_back(neuron(0, {}, 0));
                }
            };

            layers.push_back(temp);
        };

        file.close();
    };

    void write(std::string JSON_FileName)
    {
        std::ofstream file("savedNeuralNetworks\\" + JSON_FileName); // "o" stands for "out"

        json jsonCode;

        for (int i = 0; i < layers.size(); i++) // For every layer
        {
            jsonCode.push_back({});

            layer layerL = layers[i];
            json layerJ = jsonCode[i];

            for (int j = 0; j < layerL.neurons.size(); j++) // For every neuron
            {
                layerJ.push_back({});

                neuron neuronN = layerL.neurons[j];
                json neuronJ = layerJ[j];

                neuronJ.push_back(neuronN.weights);
            };

            jsonCode.push_back(layerJ);
        };

        file << jsonCode.dump() << std::endl;
        file.close();
    };

    std::string toBinary()
    {
        std::string binaryFloats = "";

        for (int i = 0; i < layers.size(); i++) // For every layer
        {
            for (int j = 0; j < layers[i].neurons.size(); j++) // For every neuron
            {
                for (int k = 0; k < layers[i].neurons[j].weights.size(); k++) // For every weight
                {
                    std::bitset<32> weight = layers[i].neurons[j].weights[k];

                    binaryFloats.append(weight.to_string());
                }
            }
        };

        return binaryFloats;
    };

    void fromBinary(std::string binary, int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0)
    {
        layers = {};

        layer input;
        layer output;

        for (int i = 0; i < inputSize + 1; i++) // + 1 because of the bias neuron
        {
            std::vector<float> weights;

            for (int j = 0; j < hiddenLayerSize; j++)
            {
                unsigned long long weightBinary = std::bitset<32>(binary.substr(0, 32)).to_ullong();
                float weight;

                memcpy(&weight, &weightBinary, 4);

                binary = binary.substr(32); // Remove the float we just translated

                weights.push_back(weight);
            };

            input.neurons.push_back(neuron(0 + (i == inputSize), weights)); // I did `0 + (i == inputSize)` instead of doing an if statement. It's to check if it's the last neuron (bias neuron / term) and set it's value to 1
        };

        layers.push_back(input);

        for (int i = 0; i < hiddenLayerCount; i++)
        {
            layer hidden;

            for (int j = 0; j < hiddenLayerSize + 1; j++)  // + 1 because of the bias neuron
            {
                std::vector<float> weights;

                for (int k = 0; k < ((i == hiddenLayerSize) ? outputSize : hiddenLayerSize); k++) // `((i == hiddenLayerSize) ? outputSize : hiddenLayerSize)` checks to see if `i` is the last hidden layer, and if it is, then k < outputSize
                {
                    unsigned long long weightBinary = std::bitset<32>(binary.substr(0, 32)).to_ullong();
                    float weight;

                    memcpy(&weight, &weightBinary, 4);

                    binary = binary.substr(32);

                    weights.push_back(weight);
                };

                hidden.neurons.push_back(neuron(0 + (i == hiddenLayerSize), weights)); // Same as the input layer pretty much
            };
            
            layers.push_back(hidden);
        };

        for (int i = 0; i < outputSize; i++) // No + 1, because output doesn't have bias neuron ofc
        {
            output.neurons.push_back(neuron(0, {}, 0));
        };

        layers.push_back(output);
    };

    void propagateForward(std::vector<float> _input)
    {
        // https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
        // Formula: layer = tanh(weights * activations + bias) // tanh means hyperbolic tangent and it's sorta like a sigmoid, but instead of ranging from 0 to 1, it ranges from -1 to 1

        xt::xarray<float> a;
        xt::xarray<float> w;
        xt::xarray<float> b;

        for (int i = 0; i < _input.size(); i++) // Do not subtract 1, because `_input` doesn't include the bias neuron / bias term ofc
        {
            layers[0].neurons[i].activation = tanh(_input[i]); // normalize input
        };
        
        b.fill(layers[0].neurons[layers[0].neurons.size()].weights); // im not sure if the `b` vector is filled with bias activations or bias weights, but bias weights makes the most sense

        for (int i = 1; i < layers.size(); i++) // For every layer // i = 1 to skip the input layer
        {
            layer pLayer = layers[i - 1]; // p: previous
            layer cLayer = layers[i]; // c: current

            for (int j = 0; j < pLayer.neurons.size() - 1; j++) // For every neuron in pLayer // Subtract 1 to not include bias neuron / bias term
            {
                xt::xarray<float> rowOfWeights; 

                a.fill(pLayer.neurons[j].activation); // a

                for (int k = 0; k < cLayer.neurons.size(); k++)
                {
                    rowOfWeights.fill(pLayer.neurons[j].weights[k]);
                };

                w.fill(rowOfWeights); // w
            };

            xt::xarray<float> layerActivations = xt::view((w * a) + b); // not done yet, gotta chuck it in the tanh function
            xt::xarray<float> formula;

            for (int j = 0; j < layerActivations.shape()[0]; j++) // tanh loop // DON'T CHANGE `formula.shape()[0]` TO `formula.size()` BECAUSE SOMETHING MAY NOT WORK (idk)
            {
                xt::xarray<float> row = xt::view(layerActivations, j);
                xt::xarray<float> temp;

                for (int k = 0; k < row.shape()[0]; k++) // SAME HERE
                {
                   temp.fill(tanh(xt::view(row, k)));
                };

                formula.fill(temp);
            }
        }
    }
};