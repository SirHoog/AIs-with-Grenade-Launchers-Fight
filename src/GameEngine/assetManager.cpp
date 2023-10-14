#include "GameEngine/assetManager.hpp"

namespace SirHoog
{
    void AssetManager::cd(std::string path)
    {
        cdPath += path;
    };
    void AssetManager::reset_cd(std::string to)
    {
        cdPath = to;
    };

    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture texture;

        if (texture.loadFromFile(cdPath + fileName))
        {
            textures[name] = texture;
        };
    };
    sf::Texture& AssetManager::GetTexture(std::string name)
    {
        return textures.at(name);
    };

    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        if (font.loadFromFile(cdPath + fileName))
        {
            fonts[name] = font;
        };
    };
    sf::Font& AssetManager::GetFont(std::string name)
    {
        return fonts.at(name);
    };
}