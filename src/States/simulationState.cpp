#include "States/simulationState.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data) {};
    void SimulationState::Init()
    {
        // Draw grid

        for (int i = 0; i < 50; i++)
        {
            AI *ai = new AI({0, 0}, {0, 0}, true, false, true, 0, 0.75, generation, NeuralNetwork("", 6, 3, 8, 4), data);

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

        data->window.setView(view);

        for (AI ai : AI_List)
        {
            ai.Render(interpolation);
        };

        data->window.display();
    }
}