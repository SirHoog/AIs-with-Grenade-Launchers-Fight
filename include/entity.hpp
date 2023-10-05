#include "GameEngine/game.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "definitions.hpp"

namespace SirHoog
{
    class Entity
    {
        GameDataRef data;

        bool affectedByGravity = true;
        bool bounces = false;
        bool friction = false;

        float bounceAmount = 0.5; // 1 = Transfer all velocity in direction of bounce
        float frictionAmount = 0.25; // 1 = Instant stop
        
        public:
            sf::Sprite sprite;
            sf::Vector2f Position = {0, 0};
            sf::Vector2f Velocity = {0, 0};

            Entity
            (
                GameDataRef data,
                sf::Vector2f Position = {0, 0},
                sf::Vector2f Velocity = {0, 0},
                bool affectedByGravity = true,
                bool bounces = false,
                bool friction = true,
                float bounceAmount = 0.5,
                float frictionAmount = 0.75
            );
            ~Entity() {};

            void Update(float dt);
            void Render(float interpolation, sf::Texture spriteTexture);
    };
}