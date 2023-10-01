#include "neuralNetwork.hpp"

namespace SirHoog
{
    NeuralNetwork::NeuralNetwork(std::string fileName, int inputSize, int hiddenLayerCount, int hiddenLayerSize, int outputSize)
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
                input.push_back(Neuron(0 + (i == inputSize), {}, hiddenLayerSize)); // I did `0 + (i == inputSize)` instead of doing an if statement. It's to check if it's the last neuron (bias neuron / term) and set it's value to 1
            };

            Layers.push_back(input);

            for (int i = 0; i < hiddenLayerCount; i++)
            {
                Layer hidden;

                for (int j = 0; j < hiddenLayerSize + 1; j++)  // + 1 because of the bias neuron
                {
                    hidden.push_back(Neuron(0 + (i == hiddenLayerSize), {}, outputSize)); // Same as the input layer pretty much
                };
                
                Layers.push_back(hidden);
            };

            for (int i = 0; i < outputSize; i++) // No `+ 1`, because output doesn't have bias neuron ofc
            {
                output.push_back(Neuron(0, {}, 0));
            };

            Layers.push_back(output);
        }
    };

    Layer NeuralNetwork::Update(Layer _input) // Forward Propagation
    {
        // https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
        // Formula: layer = tanh(weights * activations + bias) // tanh means hyperbolic tangent and it's sorta like a sigmoid, but instead of ranging from 0 to 1, it ranges from -1 to 1

        nc::NdArray<float> a; // Activations
        nc::NdArray<float> w; // Weights
        nc::NdArray<float> b; // Biases

        for (int i = 0; i < _input.size(); i++) // Do not subtract 1, because `_input` doesn't include the bias neuron / bias term ofc
        {
            Layers[0][i].activation = tanh(_input[i].activation); // normalize input
        };

        std::vector<Neuron> temp = Layers[0];

        nc::append(b, static_cast<nc::NdArray<float>>(temp[temp.size()].weights)); // im not sure if the `b` vector is filled with bias activations or bias weights, but bias weights makes the most sense

        for (int i = 1; i < Layers.size(); i++) // For every layer // i = 1 to skip the input layer
        {
            Layer previousLayer = Layers[i - 1];
            Layer currentLayer = Layers[i];

            for (int j = 0; j < previousLayer.size() - 1; j++) // For every neuron in previousLayer // Subtract 1 to not include bias neuron / bias term
            {
                nc::NdArray<float> rowOfWeights; 

                a.fill(previousLayer[j].activation); // a

                for (int k = 0; k < currentLayer.size(); k++)
                {
                    rowOfWeights.fill(previousLayer[j].weights[k]);
                };

                nc::append(w, rowOfWeights); // w
            };

            nc::NdArray<float> layerActivations = ((w.dot(a)) + b); // not done yet, gotta chuck it in the tanh function

            for (int j = 0; j < layerActivations.shape().rows; j++) // tanh loop
            {
                layerActivations[j] = tanh(layerActivations[j]);
            }
        };

        return Layers.back();
    };

    void NeuralNetwork::ReadFromFile(std::string fileName)
    {
        std::string line;
        std::ifstream file("SavedNeuralNetworks\\" + fileName); // `i` stands for in

        if (file.is_open())
        {
            int inputSize = 0;
            int hiddenLayerCount = 0;
            int hiddenLayerSize = 0;
            int outputSize = 0;
            std::string binary;

            std::getline(file, line);
            inputSize = std::stoi(line);

            std::getline(file, line);
            hiddenLayerCount = std::stoi(line);

            std::getline(file, line);
            hiddenLayerSize = std::stoi(line);

            std::getline(file, line);
            outputSize = std::stoi(line);

            std::getline(file, line);
            binary = line;

            FromBinary(inputSize = 0, hiddenLayerCount = 0, hiddenLayerSize = 0, outputSize = 0, binary);
        }
        else
        {
            std::cout << "Unable to open file";
        };

        file.close();
    };
    void NeuralNetwork::WriteToFile(std::string fileName = "", int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "")
    {
        std::ofstream file("SavedNeuralNetworks\\" + fileName); // `o` stands for out
        
        if (file.is_open())
        {
            file << std::to_string(inputSize);
            file << std::to_string(hiddenLayerCount);
            file << std::to_string(hiddenLayerSize);
            file << std::to_string(outputSize);
            file << binary;
        }
        else
        {
            std::cout << "Unable to open file";  
        };

        file.close();
    };
    void NeuralNetwork::FromBinary(int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "")
    {
        Layers = {};

        Layer input;
        Layer output;

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

            input.push_back(Neuron(0 + (i == inputSize), weights)); // I did `0 + (i == inputSize)` instead of doing an if statement. It's to check if it's the last neuron (bias neuron / term) and set it's value to 1
        };

        Layers.push_back(input);

        for (int i = 0; i < hiddenLayerCount; i++)
        {
            Layer hidden;

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

                hidden.push_back(Neuron(0 + (i == hiddenLayerSize), weights)); // Same as the input layer pretty much
            };

            Layers.push_back(hidden);
        };

        for (int i = 0; i < outputSize; i++) // No + 1, because output doesn't have bias neuron ofc
        {
            output.push_back(Neuron(0, {}, 0));
        };

        Layers.push_back(output);
    };
    std::string NeuralNetwork::ToBinary()
    {
        std::string binary = "";

        for (int i = 0; i < Layers.size(); i++) // For every layer
        {
            for (int j = 0; j < Layers[i].size(); j++) // For every neuron
            {
                for (int k = 0; k < Layers[i][j].weights.size(); k++) // For every weight
                {
                    std::bitset<32> weight = Layers[i][j].weights[k];

                    binary.append(weight.to_string());
                }
            }
        };

        return binary;
    };
}