#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <fstream>
#include <xtensor/xarray.hpp>
#include <xtensor/xjson.hpp>
#include "nlohmann/json.hpp"
#include "layer.hpp"

using json = nlohmann::json;

struct neuralNetwork
{
    std::vector<layer> layers;

    neuralNetwork(std::string fileName = "", int inputSize = 0, int hiddenLayerCount, int hiddenLayerSize = 0, int outputSize = 0)
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
                input.neurons.push_back(neuron(0, rand(), {}, hiddenLayerSize));
            };

            layers.push_back(input);

            for (int i = 0; i < hiddenLayerCount; i++)
            {
                layer hidden;

                for (int j = 0; j < hiddenLayerSize + 1; j++)  // + 1 because of the bias neuron
                {
                    hidden.neurons.push_back(neuron(0, rand(), {}, outputSize));
                };
                
                layers.push_back(hidden);
            };

            for (int i = 0; i < outputSize + 1; i++) // + 1 because of the bias neuron
            {
                output.neurons.push_back(neuron(0, rand(), {}, 0));
            };

            layers.push_back(output);

            for (int i = 0; i < layers.size(); i++) // Make the first neuron of each layer a bias neuron
            {
                neuron bias = layers[i].neurons[0];

                bias.activation = 1;
                bias.biasTerm = 0;
            }
        }
    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file("savedNeuralNetworks\\" + JSON_FileName); // i for in

        json parsedFile = json::parse(file);

        for (int i = 0; i < parsedFile.size(); i++)
        {
            layer temp;
            
            if (i != parsedFile.size()) {
                for (int j = 0; j < parsedFile[i].size(); j++)
                {
                    json neuronJ = parsedFile[i][j];
                    neuron neuronN(0, neuronJ[0], {}, neuronJ.size() - 1);

                    for (int k = 0; k < neuronJ.size() - 1; k++)
                    {
                        neuronN.weights[k] = neuronJ[k];
                    };

                    temp.neurons.push_back(neuronN);
                }
            }
            else
            {
                temp.neurons.push_back(neuron(0, 0, {}, 0));
            };

            layers.push_back(temp);
        };

        file.close();
    };

    void write(std::string JSON_FileName)
    {
        std::ofstream file("savedNeuralNetworks\\" + JSON_FileName); // o for out

        json jsonCode;

        for (int i = 0; i < layers.size(); i++)
        {
            jsonCode.push_back({});

            layer layerL = layers[i];
            json layerJ = jsonCode[i];

            for (int j = 0; j < layerL.neurons.size(); j++)
            {
                layerJ.push_back({});

                json neuronJ = layerJ[j];
                neuron neuronN = layerL.neurons[j];

                neuronJ.push_back(neuronN.biasTerm);
                neuronJ.push_back(neuronN.weights);
            };

            jsonCode.push_back(layerJ);
        };

        file << jsonCode.dump() << std::endl;
        file.close();
    };

    float sigmoid(float x)
    {
        return x / (1 + std::abs(x));
    };

    void propagateForward(std::vector<float> _input)
    {
        // https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
        // Formula: layer = sigmoid(weights * activations + bias)

        for (int i = 1; i < _input.size(); i++) // Initialize input activations // i = 1 to skip the bias neuron which is already set to 1
        {
            layers[0].neurons[i].activation = sigmoid(_input[i]); // normalize input
        };

        for (int i = 1; i < layers.size(); i++) // i = 1 to skip the input layer
        {
            layer prevLayer = layers[i - 1];
            layer curLayer = layers[i];
            xt::xarray<float> a;
            xt::xarray<float> w;
            xt::xarray<float> b;

            for (int j = 0; j < prevLayer.neurons.size(); j++)
            {
                xt::xarray<float> rowOfWeights; 

                a.fill(prevLayer.neurons[j].activation); // a
                b.fill(prevLayer.neurons[j].biasTerm); // b

                for (int k = 0; k < curLayer.neurons.size(); k++)
                {
                    rowOfWeights.fill(prevLayer.neurons[j].weights[k]);
                };

                w.fill(rowOfWeights); // w
            };

            xt::xarray<float> formula = xt::operator+(xt::operator*(w, a), b);

            for (int j = 0; j < curLayer.neurons.size(); j++)
            {
                
            }
        }
    };

    void mutate(int mutationAmount)
    {
        // use std::rand for rand ints
    }
};