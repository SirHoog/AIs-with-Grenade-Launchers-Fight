#include <SFML/Graphics.hpp>

struct view
{
    float zoom = 0.95;
    float zoomIncrement = 0.05;
    sf::Vector2f pos = {0, 0};
};

struct _map
{
    sf::Vector2i size = {1920, 1080};
    int gridSubdivision = 20;
    int gridLineThickness = 3;
};

_map map;