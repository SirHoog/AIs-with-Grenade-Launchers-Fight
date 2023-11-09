#include "States/simulationState.hpp"
#include "mainMenuState.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data)
    {
        view = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
        
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
            if (event.type == sf::Event::Resized)
            {
                // Bro why isn't it working
            };
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

        data->window.setView(view);

        data->window.draw(background);
        data->window.draw(mainMenuButton);

        // REMOVING TEMPORARILY: data->window.setView(view);

        for (AI ai : AI_List)
        {
            ai.Render(interpolation);
        };

        data->window.display();
    };

    void SimulationState::GameSpeed(int _TPS) {};
}