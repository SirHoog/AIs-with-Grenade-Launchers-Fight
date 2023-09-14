#include "game.hpp"

namespace SirHoog
{
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Default);

        Run();
    };
    void Game::Run()
    {
        float newTime, frameTime, interpolation;
        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.f;

        while (_data->window.isOpen()) // Game loop
        {
            _data->stateMachine.ProcessStateChanges();

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
                _data->stateMachine.GetActiveState()->HandleInput();
                _data->stateMachine.GetActiveState()->Update(dt);

                accumulator -= dt;
            };

            interpolation = accumulator / dt;
            _data->stateMachine.GetActiveState()->Render(interpolation);
        }
    }
}