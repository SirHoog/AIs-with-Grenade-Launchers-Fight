#include "GameEngine/game.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "definitions.hpp"

namespace SirHoog
{
    class Entity
    {
        GameDataRef data;
        sf::Sprite sprite;

        public:
            sf::Vector2f Position = {0, 0};
            sf::Vector2f Velocity = {0, 0};
            bool affectedByGravity = true;

            Entity(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, GameDataRef data): Position(Position), Velocity(Velocity), affectedByGravity(affectedByGravity), data(data) {};
            ~Entity() {};

            void Update() {};
            void Render(float interpolation, sf::Texture spriteTexture) {};
    };
}