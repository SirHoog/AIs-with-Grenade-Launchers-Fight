#include "mainMenuState.hpp"

#include <sstream>
#include <iostream>
#include "mainMenuState.hpp"
#include "definitions.hpp"

namespace SirHoog
{
    MainMenuState::MainMenuState(GameDataRef data) : data(data) {};
    void MainMenuState::Init()
    {
        const int distance = 100;

        data->assetManager.LoadTexture("Background", MainMenuBackground);
        data->assetManager.LoadTexture("Title", TitlePath);
        data->assetManager.LoadTexture("Play Button", PlayButtonPath);
        data->assetManager.LoadTexture("Settings Button", SettingsButtonPath);
        data->assetManager.LoadTexture("Quit Button", QuitButtonPath);

        background.setTexture(data->assetManager.GetTexture("Background"));
        title.setTexture(data->assetManager.GetTexture("Title"));
        playButton.setTexture(data->assetManager.GetTexture("Play Button"));
        settingsButton.setTexture(data->assetManager.GetTexture("Settings Button"));
        quitButton.setTexture(data->assetManager.GetTexture("Quit Button"));

        title.setOrigin((sf::Vector2f)data->assetManager.GetTexture("Title").getSize() / 2.f);
        playButton.setOrigin((sf::Vector2f)data->assetManager.GetTexture("Play Button").getSize() / 2.f);
        settingsButton.setOrigin((sf::Vector2f)data->assetManager.GetTexture("Settings Button").getSize() / 2.f);
        quitButton.setOrigin((sf::Vector2f)data->assetManager.GetTexture("Quit Button").getSize() / 2.f);

        title.setScale(0.35, 0.35);
        playButton.setScale(0.35, 0.35);
        settingsButton.setScale(0.35, 0.35);
        quitButton.setScale(0.35, 0.35);

        title.setPosition(Center.x, Center.y - 150);
        playButton.setPosition(Center.x, title.getPosition().y + title.getGlobalBounds().height / 2 + distance);
        settingsButton.setPosition(Center.x, playButton.getPosition().y + playButton.getGlobalBounds().height / 2 + distance);
        quitButton.setPosition(Center.x, settingsButton.getPosition().y + settingsButton.getGlobalBounds().height / 2 + distance);
    };
    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || data->inputManager.IsSpriteClicked(quitButton, sf::Mouse::Left, data->window))
            {
                data->window.close();
            };

            if (data->inputManager.IsSpriteClicked(playButton, sf::Mouse::Left, data->window))
            {
                std::cout << "Start simulation";
            };

            if (data->inputManager.IsSpriteClicked(settingsButton, sf::Mouse::Left, data->window))
            {
                std::cout << "Open settings list";
            };
        }
    };
    void MainMenuState::Update(float UpdateSpeed) {};
    void MainMenuState::Render(float RenderSpeed)
    {
        data->window.clear();

        data->window.draw(background);
        data->window.draw(title);
        data->window.draw(playButton);
        data->window.draw(settingsButton);
        data->window.draw(quitButton);

        data->window.display();
    }
}