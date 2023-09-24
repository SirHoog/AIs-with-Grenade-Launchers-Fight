#include "assetManager.hpp"

namespace SirHoog
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture texture;

        if (texture.loadFromFile(fileName))
        {
            textures[name] = texture;
        };
    };
    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        if (font.loadFromFile(fileName))
        {
            fonts[name] = font;
        };
    };
    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return textures.at(name);
    };
    sf::Font &AssetManager::GetFont(std::string name)
    {
        return fonts.at(name);
    };
}