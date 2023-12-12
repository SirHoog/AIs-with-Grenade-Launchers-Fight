#include "States/simulationState.hpp"
#include "mainMenuState.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data)
    {
        cameraView = sf::View(sf::FloatRect(0, 0, GridSize.x, GridSize.y));
        UI_View = sf::View(sf::FloatRect(0, 0, WindowWidth, WindowHeight));
        
        WindowResize(cameraView, sf::Vector2f(WindowWidth, WindowHeight));
        
        data->assetManager.reset_cd("assets/StatesUI/Simulation/");

        data->assetManager.LoadTexture("Main Menu Button", "MainMenuButton.png");

        mainMenuButton.setTexture(data->assetManager.GetTexture("Main Menu Button"));
    };
    void SimulationState::Init()
    {
        for (int row = 0; row < std::round(GridSize.x / (float)GridTileSize.x); row++)
        {
            for (int col = 0; col < std::round(GridSize.y / (float)GridTileSize.y); col++)
            {
                sf::RectangleShape GridTile(GridTileSize - sf::Vector2f(GridOutlineThickness * 2, GridOutlineThickness * 2));

                GridTile.setPosition(sf::Vector2f(row * GridTileSize.x + GridOutlineThickness, col * GridTileSize.y + GridOutlineThickness));
                GridTile.setFillColor(CameraViewColor);
                GridTile.setOutlineColor(GridOutlineColor);
                GridTile.setOutlineThickness(GridOutlineThickness);

                Grid.push_back(GridTile);
            };
        };

        for (int i = 0; i < 50; i++)
        {
            AI *ai = new AI(data, Animation(), NeuralNetwork("", 6, 3, 8, 4), generation, sf::Vector2f(WindowWidth / 2, WindowHeight / 2));

            AI_List.push_back(ai);
        }
    };

    void SimulationState::HandleInput()
    {
        sf::Event event;

        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                data->window.close();
            };
            if (data->inputManager.IsSpriteClicked(mainMenuButton, sf::Mouse::Left, data->window))
            {
                data->stateMachine.AddState(StateRef(new MainMenuState(data)));
            };
            for (AI* ai : AI_List)
            {
                if (data->inputManager.IsSpriteClicked(ai->sprite, sf::Mouse::Left, data->window))
                {
                    // TODO: Display AI's neural network and other stats
                }
            };
            // ADD: Player movement control here
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
            {
                Fullscreen = !Fullscreen;

                if (Fullscreen)
                {
                    data->window.create(sf::VideoMode(WindowWidth, WindowHeight), "Boom Bots", sf::Style::Fullscreen);
                }
                else
                {
                    data->window.create(sf::VideoMode(WindowWidth, WindowHeight), "Boom Bots", sf::Style::Default);
                };

                WindowResize(cameraView, sf::Vector2f(event.size.width, event.size.height));
                
                UI_View = sf::View(sf::FloatRect(0, 0, WindowWidth, WindowHeight));
            };
            if (event.type == sf::Event::Resized)
            {
                WindowHeight = data->window.getSize().x;
                WindowWidth = data->window.getSize().y;

                WindowResize(cameraView, sf::Vector2f(event.size.width, event.size.height));
                
                UI_View = sf::View(sf::FloatRect(0, 0, WindowWidth, WindowHeight));
            };
        }
    };
    void SimulationState::Update(float dt)
    {
        for (Entity* entity : EntityList)
        {
            entity->Update(dt);
        }
    };
    void SimulationState::Render(float interpolation)
    {
        data->window.clear(UI_ViewColor);

        data->window.setView(cameraView);
        
        for (sf::RectangleShape GridTile : Grid)
        {
            data->window.draw(GridTile);
        };

        for (Entity* entity : EntityList)
        {
            entity->Render(interpolation);
        };

        data->window.setView(UI_View);

        data->window.draw(mainMenuButton);

        data->window.display();
    };

    void SimulationState::Pause() {};
}