#include "GameEngine/inputManager.hpp"

namespace SirHoog
{
    sf::Vector2f getMousePosition(sf::RenderWindow &window)
    {
        return window.mapPixelToCoords(sf::Mouse::getPosition(window));
    };
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button) && object.getGlobalBounds().contains(getMousePosition(window)))
        {
            return true;
        };

        return false;
    }
}