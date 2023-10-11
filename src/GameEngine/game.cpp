#include "GameEngine/game.hpp"
#include "States/mainMenuState.hpp"

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

        while (data->window.isOpen()) // PIN: Game loop
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

                accumulatorR -= RenderSpeed; // WARNING: Do not change to `accumulatorR = 0`. It's this way to correct missed time
            };
            if (accumulatorU >= UpdateSpeed)
            {
                data->stateMachine.GetActiveState()->Update(dt);

                accumulatorU -= UpdateSpeed; // WARNING: Do not change to `accumulatorU = 0`. It's this way to correct missed time
            };
        }
    }
}