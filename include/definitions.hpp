#include <vector>

float GravitationalConstant = 20; // I know, it sounds very fancy
bool Impact = false; // false = frag, true = impact
bool RocketJumping = false;
bool SelfDamage = false;
int BlastRadius = 100;
int MaxDamage = 35; // Idk why, but why not?
float MaxLifeTime = 5; // Seconds
float WalkSpeed = 10;
float JumpHeight = 5;
std::vector<int> saveGenerationChampions = {}; // Adds a txt file to `../savedNeuralNetworks`