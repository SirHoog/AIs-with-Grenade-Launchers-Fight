#include <random>
#include "neuralNetwork.hpp"
#include "character.hpp"

using namespace SirHoog;

namespace SirHoog
{
    class AI : public Character
    {
        GameDataRef data;

        int frame = 0;

        int generation = 0;
        int fitness = 0;
        NeuralNetwork brain = NeuralNetwork("", 6, 3, 8, 5); // Input: X, Y, Closest Enemy X, Closest Enemy Y, Closest Grenade X, Closest Grenade Y // Output: Horizontal Movement, Jump, Launch grenade, Aim Angle, Power
        
        public:
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, NeuralNetwork neuralNetwork = NeuralNetwork("", 6, 3, 8, 4), GameDataRef data) : Character(), data(data) {};
            ~AI() {};

            void Update() {};
            void Render(float Interpolation) {};

            void CrossOver(AI with) {};
            void Mutate() {};
    };

    std::vector<AI> AI_List = {};
}