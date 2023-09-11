#include <iostream>
#include <vector>
// #include <Kairos/Timestep.hpp>
#include "ai.hpp"

const int defaultTPS = 5;
int TPS = 5;
int TPR = 0; // Ticks Per Render // How many ticks are not rendered // So you when you increase the TPS, you don't have to render as much
float FPS = 0;
bool fullscreened = false;
bool statsOpen = false;
sf::Clock runTime;
sf::Clock cu; // Clock Update
sf::Time sinceLastUpdate;
sf::Time simTime;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "AI with Grenade Launchers Fight", sf::Style::Default);
    sf::View view(sf::FloatRect(0, 0, size.x, size.y));
    sf::Vector2i mousePosScreen, lastMousePosScreen;
    sf::Vector2i mousePosWindow, lastMousePosWindow;
    sf::Vector2f mousePosView, lastMousePosView;
    sf::Vector2u mousePosGrid, lastMousePosGrid;

    view.setSize(size);
    view.setCenter(size.x / 2, size.y / 2);

    for (int i = 0; i < AI_Count; i++)
    {
        AI_List.push_back(ai(0, neuralNetwork("", 5, 2, 4, 6)));
    };

    sf::Texture AI_Image;

    if (!AI_Image.loadFromFile("assets/AI/AI_Frame4.png"))
    {
        std::cout << "Error when trying to load png 'assets/AI/AI_Frame4.png'";
    };

    sf::Font font;

    if (!font.loadFromFile("assets/ARLRDBD.TTF"))
    {
        std::cout << "Error when trying to load ttf 'assets/ARLRDBD.TTF'" << std::endl;
    };

    float gridSize = size.y / gridSubdivisions;
    sf::RenderTexture gridRenderTexture;
    sf::RectangleShape gridTile({gridSize, gridSize});
    sf::IntRect gridTileIntRect(0, 0, view.getSize().x, view.getSize().y);

    gridTile.setFillColor(sf::Color(50, 50, 50, 255));
    gridTile.setOutlineColor(sf::Color(100, 100, 100, 255));
    gridTile.setOutlineThickness(gridLineThickness);

    if (!gridRenderTexture.create(gridSize + gridLineThickness, gridSize + gridLineThickness))
    {
        std::cout << "Error when trying to create sf::RenderTexture 'gridRenderTexture'";
    };

    gridRenderTexture.clear();
    gridRenderTexture.setRepeated(true);
    gridRenderTexture.draw(gridTile);
    gridRenderTexture.display();

    sf::Texture gridTexture = gridRenderTexture.getTexture();

    sf::RectangleShape viewColor(view.getSize());

    viewColor.setTexture(&gridTexture);
    viewColor.setTextureRect(gridTileIntRect);
    viewColor.setOutlineThickness(gridLineThickness);
    viewColor.setOutlineColor(sf::Color::White);

    view.setSize(view.getSize() * 1.5f);

    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Time dt = cu.getElapsedTime();
        sf::Event event;

        FPS = 1.0f / dt.asSeconds();

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

        window.setView(view);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            };
            if (event.type == sf::Event::MouseWheelMoved)
            {
                view.setSize(((event.mouseWheel.delta == 1) ? 0.8875f : 1.125f) * view.getSize());
            };
            if (event.type == sf::Event::Resized)
            {
                sf::Vector2f prevViewSize = view.getSize();

                view.setSize(event.size.width, event.size.height);

                view.zoom(prevViewSize.y / view.getSize().y);
            };
            if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                view.move(lastMousePosView - mousePosView);
            };
            if (event.type == sf::Event::EventType::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    TPS = defaultTPS * (TPS == 0);
                    
                    std::cout << "TPS: "  << TPS << std::endl;
                };
                if (event.key.code == sf::Keyboard::Tab)
                {
                    statsOpen = !statsOpen;

                    std::cout << "Statistics Open: " << statsOpen << std::endl;
                };
                if (event.key.code == sf::Keyboard::F11)
                {
                    window.create(sf::VideoMode(1280, 700), "AI with Grenade Launchers Fight", ((fullscreened) ? sf::Style::Default : sf::Style::Fullscreen));

                    fullscreened = !fullscreened;

                    std::cout << "Fullscreen: " << fullscreened << std::endl;
                };
                if (event.key.code == sf::Keyboard::Up)
                {
                    TPS++;
                    
                    std::cout << "TPS: "  << TPS << std::endl;
                };
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (TPS != 0)
                    {
                        TPS--;
                    
                        std::cout << "TPS: "  << TPS << std::endl;
                    }
                };
                if (event.key.code == sf::Keyboard::Num0)
                {
                    TPS = defaultTPS;
                    
                    std::cout << "TPS: "  << TPS << std::endl;
                }
            }
        };

        window.clear(sf::Color::Black);
        window.draw(viewColor); // Basically the background

        // std::cout << (TPS / defaultTPS) << std::endl;
        // std::cout << dt.asSeconds() << std::endl;

        sinceLastUpdate += dt * ((float)TPS / (float)defaultTPS);
        simTime += dt * ((float)TPS / (float)defaultTPS);

        // std::cout << sinceLastUpdate.asSeconds() << std::endl;

        if (sinceLastUpdate.asSeconds() > 1 / TPS)
        {
            std::cout << "Tick" << std::endl;

            for (int i = 0; i < AI_List.size(); i++)
            {
                // ai AI = AI_List[i];
                // sf::Vector2f closestPos;
                // float closest = 1000;

                // for (int j = 0; j < AI_List.size(); j++)
                // {
                //     if (j == i) // If the AI is itself, break the loop
                //     {
                //         break;
                //     };
                    
                //     float distance = sqrt(pow(AI.pos.x - AI_List[j].pos.x, 2) + pow(AI.pos.y - AI_List[j].pos.y, 2));

                //     if (distance > closest)
                //     {
                //         closestPos = AI_List[j].pos;
                //         closest = distance;
                //     }
                // };

                // AI.nn.propagateForward({
                //     AI.pos.x,
                //     AI.pos.y,
                //     closestPos.x,
                //     closestPos.y,
                //     100 // Distance from grenade
                // });

                // std::vector<sf::Sprite> grenadeSprites;
                // std::vector<neuron> output = AI.nn.layers.back().neurons;

                // AI.vel.x += output[1].activation - output[0].activation; // Right - Left
                // AI.vel.y -= (output[2].activation > 0.5) * (AI.pos.y > size.y - 5) + 0.001f; // `-=` because SFML has a flipped Y axis // Jump * Touching Ground + Gravity
                // AI.aimAngle = output[3].activation * 360;

                // for (int j = 0; j < AI.grenadeList.size(); j++)
                // {
                //     AI.grenadeList[j].vel.y += 5; // SFML flipped Y axis
                // };

                // if (output[4].activation > 0.5 && AI.lastGrenade.getElapsedTime().asSeconds() > 5)
                // {
                //     AI.grenadeList.push_back(grenade(AI.pos, sf::Vector2f(std::sin(AI.aimAngle), -std::cos(AI.aimAngle)) * output[5].activation));
                //     AI.lastGrenade.restart().asMilliseconds();
                // };
            };

            sinceLastUpdate.Zero;
        };

        if (statsOpen)
        {
            sf::Text text;

            text.setFont(font);
            text.setString(
                "FPS: " + std::to_string(FPS) + "\n"
                "TPS: " + std::to_string(TPS) + "\n"
                "dt: " + std::to_string(dt.asSeconds()) + "s" + "\n"
                "Sim. Time: " + std::to_string(simTime.asSeconds()) + "s" + "\n"
                "Run Time: " + std::to_string(runTime.getElapsedTime().asSeconds()) + "s" + "\n"
                "AI's left: " + std::to_string(AI_List.size())
            );
            text.setCharacterSize(40);
            text.setFillColor(sf::Color::White);

            window.draw(text);
        };
        for (int i = 0; i < AI_List.size(); i++)
        {
            ai AI = AI_List[i];
            sf::Sprite AI_Sprite;

            AI_Sprite.setTexture(AI_Image);
            AI_Sprite.setOrigin(12.5, 40); // Bottom middle
            AI_Sprite.setScale(3, 3);

            AI_Sprite.setPosition(AI.pos);

            window.draw(AI_Sprite);
        };
        window.display();

        lastMousePosScreen = sf::Mouse::getPosition();
        lastMousePosWindow = sf::Mouse::getPosition(window);
        lastMousePosView = window.mapPixelToCoords(mousePosWindow);

        if (lastMousePosView.x >= 0)
        {
            lastMousePosGrid.x = mousePosView.x / gridSize;
        };
        if (lastMousePosView.y >= 0)
        {
            lastMousePosGrid.y = mousePosView.y / gridSize;
        };

        cu.restart().asSeconds();
    };

    std::cout
    << "Run time: "              << runTime.getElapsedTime().asSeconds() << 's' << '\n'
    << "Sim time: "              << simTime.asSeconds() << 's' << '\n'
    << "Generations: "           << AI_List[0].gen << '\n'
    << "Final results:"          << '\n'
    << "Highest fitness: "       << '\n'
    << "Average fitness: "       << '\n'
    << "Highest kill count: "    << '\n'
    << "Average kill count: "    << '\n'
    << "Longest survival time: " << '\n'
    << "Average survival time: ";
};