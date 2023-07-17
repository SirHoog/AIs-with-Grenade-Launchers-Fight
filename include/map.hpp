#include <SDL2/SDL.h>
#include "vector2d.hpp"

struct view
{
    float zoom = 0.95;
    float zoomIncrement = 0.05;
    vector2 pos = {0, 0};
};

struct map
{
    const vector2 size = {1920, 1080};
    const int gridSubdivision = 20;
    const int gridLineThickness = 3;
};