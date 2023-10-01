#include <sstream>
#include <iostream>
#include "simulationState.hpp"
#include "definitions.hpp"

namespace SirHoog
{
    SimulationState::SimulationState(GameDataRef data) : data(data) {};
    void SimulationState::Init()
    {
        // Draw grid

        // Create AIs
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
    void SimulationState::Update()
    {
        // Update all the cool parts
    };
    void SimulationState::Render(float Interpolation)
    {
        data->window.clear();

        data->window.draw(background);
        data->window.draw(mainMenuButton);

        data->window.setView(view);

        for (AI ai : AI_List)
        {
            ai.Render(Interpolation);
        };

        data->window.display();
    }
}