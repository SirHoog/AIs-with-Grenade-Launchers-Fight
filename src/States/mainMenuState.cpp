#include "States/mainMenuState.hpp"
#include "States/simulationState.hpp"

namespace SirHoog
{
    MainMenuState::MainMenuState(GameDataRef data) : data(data) {};
    void MainMenuState::Init()
    {
        const int distance = 50; // ANOTHER NAME: Distance between buttons

        cameraView = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
        UI_View = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));

        data->assetManager.reset_cd("assets/StatesUI/MainMenu/");

        data->assetManager.LoadTexture("Background", "Background.png");
        data->assetManager.LoadTexture("Title", "BeautifulTitleScreen.png");
        data->assetManager.LoadTexture("Play Button", "PlayButton.png");
        data->assetManager.LoadTexture("Settings Button", "SettingsButton.png");
        data->assetManager.LoadTexture("Quit Button", "QuitButton.png");

        title.setTexture(data->assetManager.GetTexture("Title"));
        playButton.setTexture(data->assetManager.GetTexture("Play Button"));
        settingsButton.setTexture(data->assetManager.GetTexture("Settings Button"));
        quitButton.setTexture(data->assetManager.GetTexture("Quit Button"));

        title.setOrigin(title.getLocalBounds().getSize() / 2.f);
        playButton.setOrigin(playButton.getLocalBounds().getSize() / 2.f);
        settingsButton.setOrigin(settingsButton.getLocalBounds().getSize() / 2.f);
        quitButton.setOrigin(quitButton.getLocalBounds().getSize() / 2.f);

        title.setScale(0.35, 0.35);
        playButton.setScale(0.35, 0.35);
        settingsButton.setScale(0.35, 0.35);
        quitButton.setScale(0.35, 0.35);

        title.setPosition(cameraView.getCenter().x, cameraView.getCenter().y - 150);
        playButton.setPosition(cameraView.getCenter().x, title.getPosition().y + title.getLocalBounds().height / 2 + distance);
        settingsButton.setPosition(cameraView.getCenter().x, playButton.getPosition().y + playButton.getLocalBounds().height / 2 + distance);
        quitButton.setPosition(cameraView.getCenter().x, settingsButton.getPosition().y + settingsButton.getLocalBounds().height / 2 + distance);
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
            {
                Fullscreen = !Fullscreen;

                if (Fullscreen)
                {
                    data->window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Boom Bots", sf::Style::Fullscreen);
                }
                else
                {
                    data->window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Boom Bots", sf::Style::Default);
                }
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
            };
            if (event.type == sf::Event::Resized)
            {
                float windowRatio = event.size.width / (float)event.size.height;
                float cameraViewRatio = cameraView.getSize().x / (float)cameraView.getSize().y;
                
                float sizeX = 1;
                float sizeY = 1;

                float posX = 0;
                float posY = 0;

                if (cameraViewRatio < windowRatio)
                {
                    sizeX = cameraViewRatio / windowRatio;
                    posX = (1 - sizeX) / 2;
                }
                else
                {
                    sizeY = windowRatio / cameraViewRatio;
                    posY = (1 - sizeY) / 2;
                };

                cameraView.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
        UI_View = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));
            }
        }
    };
    void MainMenuState::Update(float dt) {};
    void MainMenuState::Render(float Interpolation)
    {
        data->window.clear();

        data->window.draw(background);

        data->window.setView(cameraView);

        data->window.draw(title);
        data->window.draw(playButton);
        data->window.draw(settingsButton);
        data->window.draw(quitButton);

        data->window.display();
    };

    void MainMenuState::GameSpeed(int _TPS) {};
}