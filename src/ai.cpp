#include "ai.hpp"

namespace SirHoog
{
    AI::AI
    (
        GameDataRef data,
        NeuralNetwork neuralNetwork,
        int generation,
        sf::Vector2f Position,
        sf::Vector2f Velocity,
        bool affectedByGravity,
        bool bounces,
        bool friction,
        float bounceAmount,
        float frictionAmount
    ) :
    Character
    (
        data,
        Position,
        Velocity,
        affectedByGravity,
        bounces,
        friction,
        bounceAmount,
        frictionAmount
    ),
    brain(neuralNetwork),
    generation(generation)
    {
        // TODO: Make a spritesheet instead of doing this

        data->assetManager.LoadTexture("AI Frame 1", assetsPath + "AI/Frame1.png");
        data->assetManager.LoadTexture("AI Frame 2", assetsPath + "AI/Frame2.png");
        data->assetManager.LoadTexture("AI Frame 3", assetsPath + "AI/Frame3.png");
        data->assetManager.LoadTexture("AI Frame 4", assetsPath + "AI/Frame4.png");
    
        CharacterList.push_back(*this);
    };
    void AI::Update(float dt)
    {
        Character::Update(dt);

        // PURPOSE: Find input

        Layer input = {};

        input.push_back(Position.x); // NAME: X
        input.push_back(Position.y); // NAME: Y

        float closestCharacterDistance;
        Character closestCharacter(data);

        for (Character character : CharacterList)
        {
            float distance = std::sqrt(std::pow(Position.x - character.Position.x, 2) + std::pow(Position.y - character.Position.y, 2));

            if (distance < closestCharacterDistance)
            {
                closestCharacterDistance = distance;
                closestCharacter = character;
            };
        };

        input.push_back(closestCharacter.Position.x); // NAME: Enemy X
        input.push_back(closestCharacter.Position.y); // NAME: Enemy Y

        float closestGrenadeDistance;
        Grenade closestGrenade(data);

        for (Grenade grenade : grenadeList)
        {
            float distance = std::sqrt(std::pow(grenade.Position.x - Position.x, 2) + std::pow(grenade.Position.y - Position.y, 2));

            if (distance < closestGrenadeDistance)
            {
                closestGrenadeDistance = distance;
                closestGrenade = grenade;
            }
        };

        input.push_back(closestGrenade.Position.x); // NAME: Grenade X
        input.push_back(closestGrenade.Position.y); // NAME: Grenade Y

        // PURPOSE: Update attributes

        Layer output = brain.Update(input);

        for (Grenade grenade : grenadeList)
        {
            grenade.Update(*this, dt);
        };

        // MAKES: AI move

        float x = output[0].activation * WalkSpeed; // STATES: < 0 = Left // STATES: > 0 = Right
        float jump = (output[1].activation > 0) * JumpHeight; // STATES: > 0 = Decides to jump
        
        Velocity -= {x, jump};

        // MAKES: AI launch grenade

        if (output[2].activation > 0 && grenadeCooldown.getElapsedTime().asSeconds() > GrenadeCooldown) // PURPOSE: Decides to launch grenade
        {
            grenadeCooldown.restart();

            LaunchGrenade(output[3].activation, output[4].activation);
        };
    };
    void AI::Render(float interpolation)
    {
        int frame = 0;

        if (interpolation > 0.75)
        {
            frame = 4;
        }
        else if (interpolation > 0.5)
        {
            frame = 3;
        }
        else if (interpolation > 0.25)
        {
            frame = 2;
        }
        else
        {
            frame = 1;
        };

       Character::Render(interpolation, data->assetManager.GetTexture("AI Frame " + std::to_string(frame)));
    };
    // NAME: Genetic Algorithm Finally
    // Call the functions it in this order: https://www.researchgate.net/profile/Rakesh-Phanden-2/publication/258477641/figure/fig1/AS:297476348235779@1447935296512/Flow-chart-of-working-of-Genetic-Algorithm.png

    // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=15
    void AI::CrossOver(AI with)
    {
        int n = std::rand() % (brain.ToBinary().length() - 2) + 1;

        brain.FromBinary(6, 3, 8, 4, brain.ToBinary().substr(0, n) + with.brain.ToBinary().substr(n));
    };
    // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=17
    void AI::Mutate()
    {
        std::string binary = brain.ToBinary();

        for (int i = 0; i < binary.size(); i++)
        {
            int chance = std::rand() % binary.size();

            if (chance == 1)
            {
                binary[i] = ((binary[i] == '0') ? '1' : '0');
            }
        };

        brain.FromBinary(brain.Layers[0].size(), brain.Layers.size() - 2, brain.Layers[1].size(), brain.Layers[brain.Layers.size()].size(), binary);
    };
}