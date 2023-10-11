#pragma once

#include "neuralNetwork.hpp"
#include "character.hpp"

namespace SirHoog
{
    class AI : public Character
    {
        GameDataRef data;

        int generation = 0;
        int fitness = 0;
        NeuralNetwork brain = NeuralNetwork("", 6, 3, 8, 5);
        // NAMES: Input: X, Y, Closest Character X, Closest Character Y, Closest Grenade X, Closest Grenade Y // NAMES: Output: Horizontal Movement, Jump, Launch grenade, Aim Angle, Power
        
        public:
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI
            (
                GameDataRef data,
                NeuralNetwork neuralNetwork = NeuralNetwork("", 6, 3, 8, 5),
                int generation = 0,
                Animation animation,
                sf::Texture spriteTexture = sf::Texture(),
                sf::Vector2f Position = {0, 0},
                sf::Vector2f Velocity = {0, 0},
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~AI() {};

            void Update(float dt);
            void Render(float interpolation);

            void CrossOver(AI with);
            void Mutate();
    };

    static std::vector<AI> AI_List;
}