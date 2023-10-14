#include "States/mainMenuState.hpp"
#include "States/simulationState.hpp"

namespace SirHoog
{
    MainMenuState::MainMenuState(GameDataRef data) : data(data) {};
    void MainMenuState::Init()
    {
        const int distance = 100; // ANOTHER NAME: Distance between buttons

        data->assetManager.reset_cd("assets/StatesUI/MainMenu/");

        data->assetManager.LoadTexture("Background", "Background.png");
        data->assetManager.LoadTexture("Title", "BeautifulTitleScreen.png");
        data->assetManager.LoadTexture("Play Button", "PlayButton.png");
        data->assetManager.LoadTexture("Settings Button", "SettingsButton.png");
        data->assetManager.LoadTexture("Quit Button", "QuitButton.png");

        background.setTexture(data->assetManager.GetTexture("Background"));
        title.setTexture(data->assetManager.GetTexture("Title"));
        playButton.setTexture(data->assetManager.GetTexture("Play Button"));
        settingsButton.setTexture(data->assetManager.GetTexture("Settings Button"));
        quitButton.setTexture(data->assetManager.GetTexture("Quit Button"));

        title.setOrigin(title.getGlobalBounds().getSize());
        playButton.setOrigin(playButton.getGlobalBounds().getSize());
        settingsButton.setOrigin(settingsButton.getGlobalBounds().getSize());
        quitButton.setOrigin(quitButton.getGlobalBounds().getSize());

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
                data->stateMachine.AddState(StateRef(new SimulationState(data))); // WARNING: // ERROR: (may cause circular dependency)
            
                break;
            };
            if (data->inputManager.IsSpriteClicked(settingsButton, sf::Mouse::Left, data->window))
            {
                std::cout << "Settings";

                // CREATE: Settings list state
            }
        }
    };
    void MainMenuState::Update(float dt) {};
    void MainMenuState::Render(float Interpolation)
    {
        data->window.clear();

        data->window.draw(background);
        data->window.draw(title);
        data->window.draw(playButton);
        data->window.draw(settingsButton);
        data->window.draw(quitButton);

        data->window.display();
    };

    void MainMenuState::GameSpeed(int _TPS) {};
}