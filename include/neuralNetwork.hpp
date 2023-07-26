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

    neuralNetwork(std::string fileName = "", int inputSize = 0, int hiddenLayerCount, int hiddenSize = 0, int outputSize = 0)
    {
        if (fileName != "")
        {
            read(fileName);
        }
        else
        {
            layer input;
            layer output;

            for (int i = 0; i < inputSize; i++)
            {
                input.neurons.push_back(neuron(0, {}, hiddenSize));
            };

            layers.push_back(input);

            for (int i = 0; i < hiddenLayerCount; i++)
            {
                layer hidden;

                for (int j = 0; j < hiddenSize; j++)
                {
                    hidden.neurons.push_back(neuron(0, {}, outputSize));
                };
                
                layers.push_back(hidden);
            };

            for (int i = 0; i < outputSize; i++)
            {
                output.neurons.push_back(neuron(0, {}, 0));
            };

            layers.push_back(output);
        }
    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file("savedNeuralNetworks\\" + JSON_FileName); // i for in

        json parsedFile = json::parse(file);

        for (int i = 0; i < parsedFile.size(); i++)
        {
            layer temp;

            temp.bias = parsedFile[i][0];
            
            if (i != parsedFile.size()) {
                for (int j = 0; j < parsedFile[i][1].size(); j++)
                {
                    temp.neurons.push_back(neuron(0.0f, parsedFile[i][1][j].array()));
                }
            }
            else
            {
                temp.neurons.push_back(neuron(0, {}, 0));
            };

            layers.push_back(temp);
        };

        file.close();
    };

    void write(std::string JSON_FileName)
    {
        std::ofstream file("savedNeuralNetworks\\" + JSON_FileName); // o for out

        json jsonCode;
        
        jsonCode.push_back({});

        for (int i = 0; i < layers.size(); i++)
        {
            layer layerL = layers[i];
            json layerJ = jsonCode[i];

            layerJ.push_back(layerL.bias);
            layerJ.push_back({});

            for (int j = 0; j < layers[i].neurons.size(); j++)
            {
                layerJ[1].push_back({});

                std::vector<float> weightsV = layerL.neurons[j].weights;
                json weightsJ = layerJ[1][j];

                weightsJ.push_back(weightsV);
            }

            jsonCode.push_back(layerJ);
        };

        file << jsonCode.dump() << std::endl;
        file.close();
    };

    float ReLU(float x) // Heard it was better than sigmoid
    {
        return std::max(0.0f, x);
    };

    void propagateForward(std::vector<float> _input)
    {
        // https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
        // Formula = ReLU(Wa+b) or o(Wa+b)

        for (int i = 0; i < _input.size(); i++) // Initialize input activations
        {
            layers[0].neurons[i].activation = _input[i];
        };

        for (int i = 1; i < layers.size(); i++) // i = 1 to skip the input layer
        {
            layer prevLayer = layers[i - 1];
            xt::xarray<float> a;
            xt::xarray<float> w;

            for (int j = 0; j < prevLayer.neurons.size(); j++)
            {
                a.fill(prevLayer.neurons[j].activation);

                for (int k = 0; k < layers[i].neurons.size(); k++)
                {
                    w.fill(prevLayer.neurons[k].weights[j]);
                }
            };
        }
    };

    void mutate(int mutationAmount)
    {
        // use std::rand for rand ints
    }
};