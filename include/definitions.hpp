#include <SFML/Graphics.hpp>
#include <array>
#include <string>

const int ScreenWidth = 1280;
const int ScreenHeight = 720;
const sf::Vector2f Center(ScreenWidth / 2, ScreenHeight / 2);

const std::string assetsPath = "assets/";

// Main Menu

bool MainMenuOpen = true;

const std::string MainMenuPath = assetsPath + "StatesUI/MainMenu/";
const std::string MainMenuBackground = MainMenuPath + "Background.png";
const std::string TitlePath = MainMenuPath + "BeautifulTitleScreen.png";
const std::string PlayButtonPath = MainMenuPath + "PlayButton.png";
const std::string SettingsButtonPath = MainMenuPath + "SettingsButton.png";
const std::string QuitButtonPath = MainMenuPath + "QuitButton.png";

const std::array<int, 8> saveGenerationChampions = {0, 5, 10, 50, 100, 200, 500, 1000}; // Adds a txt file to `../SavedNeuralNetworks` for these generations

// Simulation // May add more buttons / images

const std::string SimulationPath = assetsPath + "StatesUI/SimulationPath/";
const std::string ToMainMenuButtonPath = SimulationPath + "ToMainMenuButton.png";

// Make these not `const` if u wanna be able to customize them in the actual game in the future

const int DefaultTPS = 30;
int TPS = 50; // Never make this const

const float GravitationalConstant = 20; // I know, it sounds very fancy

const bool Impact = false; // false = frag, true = impact
const bool Knockback = false;
const bool SelfDamage = false;
const int BlastRadius = 100;
const int MaxDamage = 35; // Idk why, but why not?
const float MaxLifeTime = 5; // Seconds
const float GrenadeCooldown = 2;

const float WalkSpeed = 10;
const float JumpHeight = 5;