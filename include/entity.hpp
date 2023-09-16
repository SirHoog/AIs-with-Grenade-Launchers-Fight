#include <SFML/Graphics.hpp>
#include <algorithm>

namespace SirHoog
{
    class Entity
    {
        public:
            sf::Vector2f pos = {0, 0};
            sf::Vector2f vel = {0, 0};
            bool affectedByGravity = true;

            Entity(sf::Vector2f pos = {0, 0}, sf::Vector2f vel = {0, 0}, bool affectedByGravity = true): pos(pos), vel(vel), affectedByGravity(affectedByGravity) {};
            ~Entity() {};

            void Accelerate(sf::Vector2f vel2)
            {
                vel += vel2;
            };

            void Update(float gravity = 0, sf::RenderWindow &window)
            {
                pos += vel;
                vel = {0, 0};

                if (affectedByGravity)
                {
                    Accelerate({0, gravity}); // Not negative since SFML Y axis is flipped
                };

                pos.x = std::clamp(pos.x, (float)0, (float)window.getSize().x);
                pos.y = std::clamp(pos.y, (float)0, (float)window.getSize().y);
            }
    };
}