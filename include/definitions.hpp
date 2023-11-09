#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <string>

const int ScreenWidth = 1280;
const int ScreenHeight = 720;

const std::array<int, 8> saveGenerationChampions = {0, 5, 10, 50, 100, 200, 500, 1000}; // PURPOSE: To add a txt file to `../SavedNeuralNetworks` for these generations

// TODO: Make these not `const` if you wanna be able to change them in-game in the future

const int DefaultTPS = 30;
static int TPS = 50; // NAME: Ticks Per Second // WARNING: Never make this const

const float Gravity = 20; // I know, it sounds very fancy

const bool Impact = false; // STATES: false = frag, true = impact
const bool Knockback = false;
const bool SelfDamage = false;
const int BlastRadius = 100;
const int MaxDamage = 35;
const float MaxLifeTime = 5;
const float GrenadeCooldown = 2;

const float WalkSpeed = 10;
const float JumpPower = 5;