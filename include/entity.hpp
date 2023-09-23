#include <SFML/Graphics.hpp>
#include <algorithm>
#include "definitions.hpp"

namespace SirHoog
{
    class Entity
    {
        public:
            sf::Vector2f Position = {0, 0};
            sf::Vector2f Velocity = {0, 0};
            bool affectedByGravity = true;

            Entity(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true): Position(Position), Velocity(Velocity), affectedByGravity(affectedByGravity) {};
            virtual ~Entity() {};

            void Update(sf::RenderWindow &window)
            {
                Position += Velocity;
                Velocity = {0, 0};

                if (affectedByGravity)
                {
                    Velocity -= {0, gravitationalConstant}; // Not negative since SFML Y axis is flipped
                };

                Position.x = std::clamp(Position.x, (float)0, (float)window.getSize().x);
                Position.y = std::clamp(Position.y, (float)0, (float)window.getSize().y);
            }
    };
}