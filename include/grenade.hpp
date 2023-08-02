#include <SFML/System.hpp>
#include <vector>

int explosionRadius = 200;

struct grenade
{
    sf::Vector2f pos = {0, 0};
    sf::Vector2f accel = {0, 0};
    sf::Vector2f vel = {0, 0};
};

std::vector<grenade> grenadeList;