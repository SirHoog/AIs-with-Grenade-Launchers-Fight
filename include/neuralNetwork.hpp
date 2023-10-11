#pragma once

#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <bitset>
#include <NC/NumCpp/NdArray.hpp>
#include <NC/NumCpp/Functions/append.hpp>
#include "neuron.hpp"

// PIN: // CONSIDER: Using an ML Library like TensorFlow or PyTorch
// PIN: // TODO: If you don't use an ML library // OPTIMIZE: THIS... EVERYTHING

namespace SirHoog
{
    typedef std::vector<Neuron> Layer;

    class NeuralNetwork
    {
        public:
            std::vector<Layer> Layers;

            NeuralNetwork(std::string fileName, int inputSize, int hiddenLayerCount, int hiddenLayerSize, int outputSize);
            
            Layer Update(Layer _input); // ANOTHER NAME: Forward Propagation
            
            void ReadFromFile(std::string fileName);
            void WriteToFile(std::string fileName = "", int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "");
            
            void FromBinary(int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "");
            std::string ToBinary();
    };
}