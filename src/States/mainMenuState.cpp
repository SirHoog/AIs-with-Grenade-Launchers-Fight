#include "States/mainMenuState.hpp"
#include "States/simulationState.hpp"

namespace SirHoog
{
    MainMenuState::MainMenuState(GameDataRef data) : data(data) {};
    void MainMenuState::Init()
    {
        const int distance = 50; // ANOTHER NAME: Distance between buttons

        view = sf::View(sf::FloatRect(0, 0, data->window.getSize().x, data->window.getSize().y));

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

        title.setPosition(view.getCenter().x, view.getCenter().y - 150);
        playButton.setPosition(view.getCenter().x, title.getPosition().y + title.getLocalBounds().height / 2 + distance);
        settingsButton.setPosition(view.getCenter().x, playButton.getPosition().y + playButton.getLocalBounds().height / 2 + distance);
        quitButton.setPosition(view.getCenter().x, settingsButton.getPosition().y + settingsButton.getLocalBounds().height / 2 + distance);
    };
    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                sf::Vector2f prevViewSize = view.getSize();

                view.setSize(event.size.width, event.size.height);

                if (data->window.getSize().x > data->window.getSize().y)
                {
                    view.zoom(prevViewSize.y / view.getSize().y);
                }
                else
                {
                    view.zoom(prevViewSize.x / view.getSize().x);
                }
            };
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
        sf::RectangleShape testBackground;

        testBackground.setSize(view.getSize());
        testBackground.setFillColor(sf::Color::Green);

        data->window.clear();

        data->window.setView(view);

        data->window.draw(testBackground);
        data->window.draw(title);
        data->window.draw(playButton);
        data->window.draw(settingsButton);
        data->window.draw(quitButton);

        data->window.display();
    };

    void MainMenuState::GameSpeed(int _TPS) {};
}