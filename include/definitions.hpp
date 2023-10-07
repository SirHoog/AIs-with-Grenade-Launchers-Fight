#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <string>

const int ScreenWidth = 1280;
const int ScreenHeight = 720;
const sf::Vector2f Center(ScreenWidth / 2, ScreenHeight / 2);

const std::string assetsPath = "assets/";

// NAME: Main Menu

const std::string MainMenuPath = assetsPath + "StatesUI/MainMenu/";
const std::string MainMenuBackground = MainMenuPath + "Background.png";
const std::string TitlePath = MainMenuPath + "BeautifulTitleScreen.png";
const std::string PlayButtonPath = MainMenuPath + "PlayButton.png";
const std::string SettingsButtonPath = MainMenuPath + "SettingsButton.png";
const std::string QuitButtonPath = MainMenuPath + "QuitButton.png";

const std::array<int, 8> saveGenerationChampions = {0, 5, 10, 50, 100, 200, 500, 1000}; // PURPOSE: To add a txt file to `../SavedNeuralNetworks` for these generations

// NAME: Simulation
// CONSIDER: Adding more buttons / images

const std::string SimulationPath = assetsPath + "StatesUI/SimulationPath/";
const std::string ToMainMenuButtonPath = SimulationPath + "ToMainMenuButton.png";

// TODO: Make these not `const` if you wanna be able to change them in-game in the future

const int DefaultTPS = 30;
static int TPS = 50; // NAME: Ticks Per Second // WARNING: Never make this const

const float GravitationalConstant = 20; // I know, it sounds very fancy

const bool Impact = false; // STATES: false = frag, true = impact
const bool Knockback = false;
const bool SelfDamage = false;
const int BlastRadius = 100;
const int MaxDamage = 35;
const float MaxLifeTime = 5;
const float GrenadeCooldown = 2;

const float WalkSpeed = 10;
const float JumpHeight = 5;