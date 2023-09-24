#include <array>
#include <string>

const int ScreenWidth = 1280;
const int ScreenHeight = 720;

const float GravitationalConstant = 20; // I know, it sounds very fancy
const bool Impact = false; // false = frag, true = impact
const bool RocketJumping = false;
const bool SelfDamage = false;
const int BlastRadius = 100;
const int MaxDamage = 35; // Idk why, but why not?
const float MaxLifeTime = 5; // Seconds
const float WalkSpeed = 10;
const float JumpHeight = 5;
const std::array<int, 8> saveGenerationChampions = {0, 5, 10, 50, 100, 200, 500, 1000}; // Adds a txt file to `../SavedNeuralNetworks` for these generations