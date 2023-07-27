#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ai.hpp"

bool fullscreened = false;

void handleEvents(sf::RenderWindow& window, int defaultTPS, int& TPS, float FPS, float simTime, sf::Time dt, sf::Clock runTime, bool update)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();

                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                {
                    TPS = defaultTPS * (TPS == 0);
                };
                if (event.key.code == sf::Keyboard::Tab)
                {
                    sf::Font font;

                    if (!font.loadFromFile("ARLRDBD.TTF"))
                    {
                        std::cout << "Error when trying to load sf::Font 'ARLRDBD.TTF'";
                    };

                    sf::Text text;

                    text.setFont(font);
                    text.setString(
                        "FPS: " + std::to_string(FPS) + "\n"
                        "TPS: " + std::to_string(TPS) + "\n"
                        "dt: " + std::to_string(dt.asSeconds()) + "s" + "\n"
                        "Sim. Time: " + std::to_string(simTime) + "s" + "\n"
                        "Run Time: " + std::to_string(runTime.getElapsedTime().asSeconds()) + "s" + "\n"
                        "AI's left: " + std::to_string(AI_List.size())
                    );
                    text.setCharacterSize(14);
                    text.setFillColor(sf::Color::White);
                    window.draw(text);
                };
                if (event.key.code == sf::Keyboard::F11)
                {
                    window.create(sf::VideoMode(1280, 700), "AI with Grenade Launchers Fight", ((fullscreened) ? sf::Style::None : sf::Style::Fullscreen));
                };
                if (event.key.code == sf::Keyboard::Up)
                {
                    TPS++;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (TPS != 0)
                    {
                        TPS--;
                    }
                };
                if (event.key.code == sf::Keyboard::Num0)
                {
                    TPS = defaultTPS;
                }
        }
    }
}