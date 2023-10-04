#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <NC/NumCpp/NdArray.hpp>
#include <NC/NumCpp/Functions/append.hpp>
#include "neuron.hpp"

namespace SirHoog
{
    typedef std::vector<Neuron> Layer; 

    class NeuralNetwork
    {
        public:
            std::vector<Layer> Layers;

            NeuralNetwork(std::string fileName, int inputSize, int hiddenLayerCount, int hiddenLayerSize, int outputSize) {};
            
            virtual Layer Update(Layer _input); // Forward Propagation
            
            virtual void ReadFromFile(std::string fileName);
            virtual void WriteToFile(std::string fileName = "", int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "");

            virtual void FromBinary(int inputSize = 0, int hiddenLayerCount = 0, int hiddenLayerSize = 0, int outputSize = 0, std::string binary = "");
            virtual std::string ToBinary();
    };
}