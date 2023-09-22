#include <random>
#include "neuralNetwork.hpp"
#include "grenade.hpp"

using namespace SirHoog;

namespace SirHoog
{
    std::vector<AI> AI_List = {};

    float WalkSpeed = 10;
    float JumpHeight = 5;

    class AI : public Entity
    {
        int Generation = 0;
        int Fitness = 0;
        NeuralNetwork brain("", 5, 2, 4, 4); // Input: X, Y, Enemy X, Enemy Y, Closest Grenade Distance // Output: Horizontal Movement, Jump
        
        float AimAngle = 0;
        float Power = 0;
        std::vector<Grenade> GrenadeList = {};
        
        public:
            float Health = 100;
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};

            void Update(sf::RenderWindow &window)
            {
                // Find input

                std::vector<float> input = {};

                input.push_back(Position.x); // X
                input.push_back(Position.y); // Y

                for (AI ai : AI_List)
                {
                    input.push_back();
                };

                Layer output = brain.Update(input);

                for (Grenade grenade : GrenadeList)
                {
                    grenade.Update(window, this, AI_List); // Intellisense bug on `this` and `AI_List`
                };

                // Move

                float x = output.neurons[0].activation * WalkSpeed; // < 0 = Left // > 0 = Right
                float jump = (output.neurons[1].activation > 0) * JumpHeight; // > 0 = Decides to jump
                
                this->Velocity -= {x, jump};
            };

            void LaunchGrenade()
            {
                GrenadeList.push_back(Grenade(Position, sf::Vector2f(std::sin(AimAngle), std::cos(AimAngle)) * Power, true));
            };
    };
}