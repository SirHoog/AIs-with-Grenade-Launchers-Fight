#include "GameEngine/inputManager.hpp"

namespace SirHoog
{
    sf::Vector2i getMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    };
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect tempRect(object.getPosition().x + object.getOrigin().x, object.getPosition().y + object.getOrigin().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if (tempRect.contains(getMousePosition(window)))
            {
                return true;
            }
        };

        return false;
    }
}