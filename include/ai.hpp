#include <SFML/System.hpp>
#include <array>
#include <random>
#include "map.hpp"
#include "neuralNetwork.hpp"
#include "nlohmann/json.hpp"

struct ai
{
    float health = 100;
    int fitness = 0; // 20 per 20 sec of survival and 15 per kill, but deduct 15 points if survived 30 seconds without a kill
    sf::Color color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
    sf::Vector2f pos = {rand() % map.size.x, rand() % map.size.y};
    sf::Vector2f accel = {0, 0};
    float aimAngle = 0;

    neuralNetwork nn;
    int gen;

    ai(int _gen, neuralNetwork _nn)
    {
        gen = _gen;
        nn = _nn;
    };

    // Do it in this order: https://www.researchgate.net/profile/Rakesh-Phanden-2/publication/258477641/figure/fig1/AS:297476348235779@1447935296512/Flow-chart-of-working-of-Genetic-Algorithm.png

    // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=15
    void crossOver(ai with)
    {
        int n = std::rand() % (nn.toBinary().length() - 2) + 1;

        nn.fromBinary(nn.toBinary().substr(0, n) + with.nn.toBinary().substr(n));
    };

    // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=17
    void mutate()
    {
        std::string binaryString = nn.toBinary();

        for (int i = 0; i < binaryString.size(); i++)
        {
            int chance = std::rand() % binaryString.size(); // 1 in length of binaryString

            if (chance == 1)
            {
                binaryString[i] = ((binaryString[i] == '0') ? '1' : '0');
            }
        };

        nn.fromBinary(binaryString, nn.layers[0].neurons.size(), nn.layers.size() - 2, nn.layers[1].neurons.size(), nn.layers[nn.layers.size()].neurons.size());
    }
};

std::vector<int> saveGenChampion = {0, 1, 2, 3, 4, 5, 10, 25, 50, 75, 100, 150, 200, 300, 400, 500, 750, 1000, 1250, 1500, 2000};
const int AI_Count = 50;
std::vector<ai> AI_List;