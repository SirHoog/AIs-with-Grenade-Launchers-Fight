#pragma once

#include "neuralNetwork.hpp"
#include "character.hpp"

namespace SirHoog
{
    class AI : public Character
    {
        int generation = 0;
        int fitness = 0;
        NeuralNetwork brain = NeuralNetwork("", 6, 3, 8, 5);
        // NAMES: Input: X, Y, Closest Character X, Closest Character Y, Closest Grenade X, Closest Grenade Y // NAMES: Output: Horizontal Movement, Jump, Launch grenade, Aim Angle, Power
        
        public:
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI
            (
                GameDataRef data,
                Animation animation = Animation(),
                NeuralNetwork neuralNetwork = NeuralNetwork("", 6, 3, 8, 5),
                int generation = 0,
                sf::Vector2f Position = {0, 0},
                sf::Vector2f Velocity = {0, 0},
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~AI() {};

            void Update(float dt) override;
            void Render(float interpolation) override;

            void CrossOver(AI with);
            void Mutate();
    };

    static std::vector<AI> AI_List;
}