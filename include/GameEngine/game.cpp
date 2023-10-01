#include "game.hpp"
#include "definitions.hpp"
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
        float newTime, dt, interpolation, UpdateSpeed;
        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulatorR, accumulatorU = 0;

        while (data->window.isOpen()) // Game loop
        {
            if (MainMenuOpen == true)
            {
                data->stateMachine.AddState(StateRef(new MainMenuState(data)));

                MainMenuOpen = false;
            };

            data->stateMachine.ProcessStateChanges();

            newTime = _clock.getElapsedTime().asSeconds();
            dt = newTime - currentTime;
            UpdateSpeed = TPS / DefaultTPS;

            if (dt > 0.25f)
            {
                dt = 0.25f;
            };

            currentTime = newTime;
            accumulatorR += dt;
            accumulatorU += dt;

            interpolation = accumulatorR / RenderSpeed;

            while (accumulatorR >= RenderSpeed)
            {
                data->stateMachine.GetActiveState()->HandleInput();
                data->stateMachine.GetActiveState()->Render(interpolation);

                accumulatorR -= RenderSpeed; // Not `accumulatorR = 0` to correct missed time
            };

            while (accumulatorU >= UpdateSpeed)
            {
                data->stateMachine.GetActiveState()->Update();

                accumulatorU -= UpdateSpeed; // Not `accumulatorR = 0` to correct missed time
            };
        }
    }
}