#include "game.hpp"
#include "States/simulationState.hpp"

namespace SirHoog
{
    Game::Game(int width, int height, std::string title)
    {
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Default);

        data->stateMachine.AddState(StateRef(new MainMenuState(data)));

        Run();
    };
    void Game::Run()
    {
        float dt, interpolation, UpdateSpeed, accumulatorR, accumulatorU = 0;

        while (data->window.isOpen()) // Game loop
        {
            data->stateMachine.ProcessStateChanges();

            UpdateSpeed = TPS / DefaultTPS;
            dt = _clock.restart().asSeconds() * UpdateSpeed;

            accumulatorR += dt;
            accumulatorU += dt * UpdateSpeed;

            interpolation = accumulatorU / UpdateSpeed;

            if (accumulatorR >= RenderSpeed)
            {
                data->stateMachine.GetActiveState()->HandleInput();
                data->stateMachine.GetActiveState()->Render(interpolation);

                accumulatorR -= RenderSpeed; // Not `accumulatorR = 0` to correct missed time
            };
            if (accumulatorU >= UpdateSpeed)
            {
                data->stateMachine.GetActiveState()->Update(dt);

                accumulatorU -= UpdateSpeed; // Not `accumulatorU = 0` to correct missed time
            };
        }
    }
}