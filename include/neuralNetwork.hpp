#include <vector>
#include <string>
#include <random>
#include <fstream>
#include "neuron.hpp"
#include <xtensor/xjson.hpp>
#include <xtensor/xarray.hpp>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct neuralNetwork
{
    xt::xarray<neuron> input;
    xt::xarray<neuron> hidden;
    xt::xarray<neuron> output;

    neuralNetwork(std::string fileName = "", std::vector<auto&> linkOutputWith, int is = 0, int hs = 0, int os = 0)
    {
        if (fileName != "")
        {
            read(fileName);
        }
        else
        {
            for (int i = 0; i < is; i++)
            {
                input.fill(neuron(0, {}, is));
            };

            for (int i = 0; i < hs; i++)
            {
                input.fill(neuron(0, {}, hs));
            };

            for (int i = 0; i < os; i++)
            {
                input.fill(neuron(0, {}, os));
            }
        }
    };

    void propagateForward()
    {
        
    };

    void mutate(json nn, int mutationAmount)
    {

    };

    void read(std::string JSON_FileName)
    {
        std::ifstream file(JSON_FileName);

        json parsedFile = json::parse(file);
        
        xt::from_json(parsedFile, input);
    };

    void write(std::string JSON_FileName, std::string jsonCode)
    {
        std::ofstream file(JSON_FileName);

        file << jsonCode << std::endl;
        file.close();
    }
};