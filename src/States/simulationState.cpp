#include "States/simulationState.hpp"
#include "mainMenuState.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data)
    {
        cameraView = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
        UI_View = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
        
        data->assetManager.reset_cd("assets/StatesUI/Simulation/");

        data->assetManager.LoadTexture("Main Menu Button", "MainMenuButton.png");

        mainMenuButton.setTexture(data->assetManager.GetTexture("Main Menu Button"));
    };
    void SimulationState::Init()
    {
        // TODO: Draw grid

        for (int i = 0; i < 50; i++)
        {
            AI *ai = new AI(data, Animation(), NeuralNetwork("", 6, 3, 8, 4), generation, sf::Vector2f(data->window.getSize().x / 2, data->window.getSize().y / 2));

            AI_List.push_back(*ai);
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
            for (AI ai : AI_List)
            {
                if (data->inputManager.IsSpriteClicked(ai.sprite, sf::Mouse::Left, data->window))
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
                    data->window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Boom Bots", sf::Style::Fullscreen);
                }
                else
                {
                    data->window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Boom Bots", sf::Style::Default);
                }
            };
            if (event.type == sf::Event::Resized)
            {
                float windowRatio = event.size.width / (float)event.size.height;
                float viewRatio = cameraView.getSize().x / (float)cameraView.getSize().y;
                
                float sizeX = 1;
                float sizeY = 1;

                float posX = 0;
                float posY = 0;

                if (viewRatio < windowRatio)
                {
                    sizeX = viewRatio / windowRatio;
                    posX = (1 - sizeX) / 2;
                }
                else
                {
                    sizeY = windowRatio / viewRatio;
                    posY = (1 - sizeY) / 2;
                };

                cameraView.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
                UI_View = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
            };
        }
    };
    void SimulationState::Update(float dt)
    {
        for (Character character : CharacterList)
        {
            character.Update(dt);
        }
    };
    void SimulationState::Render(float interpolation)
    {
        data->window.clear();

        data->window.setView(UI_View);

        data->window.draw(mainMenuButton);

        data->window.setView(cameraView);

        data->window.draw(grid);

        for (Character character : CharacterList)
        {
            character.Render(interpolation);
        };

        data->window.display();
    };

    void SimulationState::GameSpeed(int _TPS) {};
}