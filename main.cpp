#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "include/ai.hpp"

const int defaultTPS = 50;
int TPS = 50;
int TPR = 1; // Ticks Per Render // How many ticks to wait every render // So you when you increase the TPS, you don't have to render as much
float FPS = 0;
bool fullscreened = false;
sf::Clock runTime;

int main()
{
    float simTimeMS;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "AI with Grenade Launchers Fight");
    sf::View view;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;

    view.setSize(size.x, size.y);
    view.setCenter(window.getSize().x / 2, window.getSize().y / 2);

    for (int i = 0; i < AI_Count; i++)
    {
        AI_List.push_back(ai());
    };

    while (window.isOpen())
    {
        sf::Clock clock;
        sf::Time dt = clock.getElapsedTime();

        simTimeMS += dt.asMilliseconds() * (TPS / defaultTPS);

        sf::Event event;

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
                        std::cout << "Error when trying to load TTF 'ARLRDBD.TTF'";
                    };

                    sf::Text text;

                    text.setFont(font);
                    text.setString(
                        "FPS: " + std::to_string(FPS) + "\n"
                        "TPS: " + std::to_string(TPS) + "\n"
                        "dt: " + std::to_string(dt.asSeconds()) + "s" + "\n"
                        "Sim. Time: " + std::to_string(std::round(simTimeMS / 1000)) + "s" + "\n"
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

                    fullscreened = !fullscreened;
                };
                if (event.key.code == sf::Keyboard::Up)
                {
                    TPS++;
                };
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
                };
            case sf::Event::MouseButtonPressed:
            {
                break;
            }
        };

        if (simTimeMS / (1000 / (TPS / defaultTPS)) > 1)
        {
            for (int i = 0; i < AI_List.size(); i++)
            {
                ai AI = AI_List[i];
                sf::Vector2f closestPos;
                float closest = 1000;

                for (int j = 0; j < AI_List.size(); j++)
                {
                    if (j == i)
                    {
                        break;
                    };
                    
                    float distance = sqrt(pow(AI.pos.x - AI_List[j].pos.x, 2) + pow(AI.pos.y - AI_List[j].pos.y, 2));

                    if (distance > closest)
                    {
                        closestPos = AI_List[j].pos;
                        closest = distance;
                    }
                };

                AI.nn.propagateForward({
                    AI.pos.x,
                    AI.pos.y,
                    closestPos.x,
                    closestPos.y,
                    100
                });
            };

            simTimeMS = 0;
        };

        window.setView(view);

        mousePosScreen = sf::Mouse::getPosition();
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);

        if (mousePosView.x >= 0)
        {
            mousePosGrid.x = mousePosView.x / gridSize;
        };
        if (mousePosView.y >= 0)
        {
            mousePosGrid.y = mousePosView.y / gridSize;
        };

        window.clear();

        // Uncomment this when you figure out how to create a gridTexture

        // sf::Texture gridTexture;
        // sf::Uint8* pixels = new sf::Uint8[gridSize * gridSize * 4];

        // if (gridTexture.create(gridSize, gridSize))
        // {
        //     std::cout << "Error when trying to create sf::Texture 'gridTexture'";
        // };

        // gridTexture.update(pixels);
        // gridTexture.setRepeated(true);

        sf::RectangleShape viewColor(view.getSize());

        std::vector<sf::RectangleShape> gridCells;

        // viewColor.setTexture(&gridTexture);
        viewColor.setOutlineThickness(5);
        viewColor.setOutlineColor(sf::Color::White);

        // Remove this when you figure out how to create a gridTexture
        for (int i = 0; i < view.getSize().x / gridSize; i++) // For column
        {
            for (int j = 0; j < view.getSize().y / gridSize; j++) // For row
            {
                sf::RectangleShape rect({gridSize, gridSize});

                rect.setFillColor(sf::Color::Transparent);
                rect.setOutlineThickness(gridLineThickness);
                rect.setOutlineColor(sf::Color(100));
                rect.setPosition({i * gridSize, j * gridSize});

                gridCells.push_back(rect);
            }
        };

        for (int i = 0; i < AI_List.size(); i++)
        {
            sf::Texture AI_Image;
            ai AI = AI_List[i];

            if (!AI_Image.loadFromFile("assets/AI/AI_Frame4.png"))
            {
                std::cout << "Error when trying to load png 'assets/AI/AI_Frame4.png'";
            };

            sf::Sprite AI_Sprite;

            AI_Sprite.setTexture(AI_Image);
            AI_Sprite.setOrigin({12.5, 40}); // Bottom middle
            AI_Sprite.setScale({3, 3});
            AI_Sprite.setPosition(AI.pos);
            AI_Sprite.move(AI.vel + AI.accel);

            AI.vel = AI.accel;
            AI.accel = {0, 0};
            AI.pos = AI_Sprite.getPosition();
        };

        window.draw(viewColor);
        for (int i = 0; i < gridCells.size(); i++)
        {
            window.draw(gridCells[i]);
        };
        window.display();

        clock.restart().asMilliseconds();
    };

    std::cout
    << "Run time: "              << runTime.getElapsedTime().asSeconds() << " seconds" << '\n'
    << "Sim time: "              << std::round(simTimeMS / 1000) << " seconds" << '\n'
    << "Generations: "           << AI_List[0].gen << "\n\n"
    << "Final results:"
    << "Highest fitness: "       << "" << '\n'
    << "Average fitness: "       << "" << '\n'
    << "Highest kill count: "    << "" << '\n'
    << "Average kill count: "    << "" << '\n'
    << "Longest survival time: " << "" << '\n'
    << "Average survival time: " << "";
};