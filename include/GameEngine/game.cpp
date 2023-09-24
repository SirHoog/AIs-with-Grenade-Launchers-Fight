#include "game.hpp"
#include "ai.hpp"

namespace SirHoog
{
    Game::Game(int width, int height, std::string title)
    {
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Default);

        Run();
    };
    void Game::Run()
    {
        float newTime, frameTime, interpolation;
        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.f;

        while (data->window.isOpen()) // Game loop
        {
            data->stateMachine.ProcessStateChanges();

            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f)
            {
                frameTime = 0.25f;
            };

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                data->stateMachine.GetActiveState()->HandleInput();
                data->stateMachine.GetActiveState()->Update(dt);

                accumulator -= dt;
            };

            interpolation = accumulator / dt;
            data->stateMachine.GetActiveState()->Render(interpolation);
        }
    }
}