#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ai.hpp"
#include "map.hpp"
#include "handleEvents.hpp"

const int defaultTPS = 50;
int TPS = 50;
float FPS = 0;
sf::Clock runTime;

int main()
{
    float simTimeMS;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "AI with Grenade Launchers Fight");

    while (window.isOpen())
    {
        sf::Clock clock;
        sf::Time dt = clock.getElapsedTime();

        simTimeMS += dt.asMilliseconds() * (TPS / defaultTPS);

        handleEvents(window, defaultTPS, TPS, FPS, simTimeMS, dt, runTime, (simTimeMS / (TPS / defaultTPS * 1000) > 1));

        if (simTimeMS / (TPS / defaultTPS * 1000) > 1)
        {
            simTimeMS = 0;
        };

        window.clear();
        window.display();

        clock.restart().asMilliseconds();
    }
};