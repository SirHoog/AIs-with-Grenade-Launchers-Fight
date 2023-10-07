#include "States/simulationState.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data) {};
    void SimulationState::Init()
    {
        // TODO: Draw grid

        for (int i = 0; i < 50; i++)
        {
            AI *ai = new AI(data, NeuralNetwork("", 6, 3, 8, 4), generation, Center);

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
                if (data->inputManager.IsSpriteClicked(ai.Sprite, sf::Mouse::Left, data->window))
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

        data->window.draw(background);
        data->window.draw(mainMenuButton);

        // REMOVING TEMPORARILY: data->window.setView(view);

        for (AI ai : AI_List)
        {
            ai.Render(interpolation);
        };

        data->window.display();
    };

    void GameSpeed(int _TPS) {};
}