#include "assetManager.hpp"

namespace SirHoog
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture texture;

        if (texture.loadFromFile(fileName))
        {
            _textures[name] = texture;
        };
    };
    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        if (font.loadFromFile(fileName))
        {
            _fonts[name] = font;
        };
    };
    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return _textures.at(name);
    };
    sf::Font &AssetManager::GetFont(std::string name)
    {
        return _fonts.at(name);
    };
}