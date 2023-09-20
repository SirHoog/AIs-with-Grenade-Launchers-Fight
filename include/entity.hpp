#include <SFML/Graphics.hpp>
#include <algorithm>

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

            void Accelerate(sf::Vector2f Velocity2)
            {
                Velocity += Velocity2;
            };

            void Update(float gravity = 0, sf::RenderWindow &window)
            {
                Position += Velocity;
                Velocity = {0, 0};

                if (affectedByGravity)
                {
                    Accelerate({0, gravity}); // Not negative since SFML Y axis is flipped
                };

                Position.x = std::clamp(Position.x, (float)0, (float)window.getSize().x);
                Position.y = std::clamp(Position.y, (float)0, (float)window.getSize().y);
            }
    };
}