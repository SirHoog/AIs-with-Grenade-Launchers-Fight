#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <string>

static int WindowWidth = 1280;
static int WindowHeight = 720;

static void WindowResize(sf::View &view, sf::Vector2f WindowSize)
{
    float windowRatio = WindowSize.x / (float)WindowSize.y;
    float viewRatio = view.getSize().x / (float)view.getSize().y;
    
    float sizeX = 1;
    float sizeY = 1;

    float posX = 0;
    float posY = 0;

    if (viewRatio < windowRatio)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2;
    }
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2;
    };

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
};

static bool Fullscreen = false;

const std::array<int, 8> saveGenerationChampions = {0, 5, 10, 50, 100, 200, 500, 1000}; // PURPOSE: To add a txt file to `../SavedNeuralNetworks` for these generations

// TODO: Make these not `const` if you wanna be able to change them in-game in the future

const int DefaultTPS = 30;
static int TPS = 50; // NAME: Ticks Per Second // WARNING: Never make this const

const sf::Color UI_ViewColor = sf::Color(50, 135, 200);
const sf::Color CameraViewColor = sf::Color::Magenta;
const sf::Color GridOutlineColor = sf::Color::Yellow;
const int GridOutlineThickness = 1;
const sf::Vector2f GridTileSize = sf::Vector2f(10, 10);
const sf::Vector2f GridSize = sf::Vector2f(100, 100);

const float Gravity = 20; // I know, it sounds very fancy

const bool Impact = false; // STATES: false = frag, true = impact
const bool GrenadeKnockback = false;
const bool SelfDamage = false;
const int BlastRadius = 100;
const int MaxDamage = 35;
const float MaxLifeTime = 5;
const float GrenadeCooldown = 2;

const float WalkSpeed = 10;
const float JumpPower = 5;