#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace SirHoog
{
    class AssetManager
    {
        std::string cdPath = "assets/";

        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;

        public:
            AssetManager() {};
            ~AssetManager() {};

            void cd(std::string path);
            void reset_cd(std::string to = "assets/");

            void LoadTexture(std::string name, std::string fileName);
            sf::Texture& GetTexture(std::string name);

            void LoadFont(std::string name, std::string fileName);
            sf::Font& GetFont(std::string name);
    };
}