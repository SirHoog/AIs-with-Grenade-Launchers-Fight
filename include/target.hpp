#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "map.hpp"

struct target
{
    int health = 100;
    sf::Vector2 pos = {rand() % int(map.size.x), rand() % int(map.size.y)};
    sf::Vector2 hitbox
};