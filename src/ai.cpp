#include "ai.hpp"

namespace SirHoog
{
    AI::AI(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, NeuralNetwork neuralNetwork = NeuralNetwork("", 6, 3, 8, 4), GameDataRef data) : Entity(), data(data)
    {
        data->assetManager.LoadTexture("AI Frame 1", assetsPath + "AI/Frame1.png");
        data->assetManager.LoadTexture("AI Frame 2", assetsPath + "AI/Frame2.png");
        data->assetManager.LoadTexture("AI Frame 3", assetsPath + "AI/Frame3.png");
        data->assetManager.LoadTexture("AI Frame 4", assetsPath + "AI/Frame4.png");
    };
    void AI::Update()
    {
        // Find input

        Layer input = {};

        input.push_back(Position.x); // X
        input.push_back(Position.y); // Y

        float closestAI_Distance;
        AI closestAI;

        for (AI ai : AI_List)
        {
            float distance = std::sqrt(std::pow(Position.x - ai.Position.x, 2) + std::pow(Position.y - ai.Position.y, 2));

            if (distance < closestAI_Distance)
            {
                closestAI_Distance = distance;
                closestAI = ai;
            };
        };

        input.push_back(closestAI.Position.x); // Enemy X
        input.push_back(closestAI.Position.y); // Enemy Y

        float closestGrenadeDistance;
        Grenade closestGrenade;

        for (AI ai : AI_List)
        {
            for (Grenade grenade : ai.grenadeList)
            {
                float distance = std::sqrt(std::pow(grenade.Position.x - Position.x, 2) + std::pow(grenade.Position.y - Position.y, 2));

                if (distance < closestGrenadeDistance)
                {
                    closestGrenadeDistance = distance;
                    closestGrenade = grenade;
                }
            }
        };

        input.push_back(closestGrenade.Position.x); // Grenade X
        input.push_back(closestGrenade.Position.y); // Grenade Y

        // Update attributes

        Layer output = brain.Update(input);

        for (Grenade grenade : grenadeList)
        {
            grenade.Update();
        };

        // Move

        float x = output[0].activation * WalkSpeed; // < 0 = Left // > 0 = Right
        float jump = (output[1].activation > 0) * JumpHeight; // > 0 = Decides to jump
        
        Velocity -= {x, jump};

        for (Grenade grenade : grenadeList)
        {
            grenade.Update();
        };

        // Launch

        if (output[2].activation > 0 && grenadeCooldown.getElapsedTime().asSeconds() > GrenadeCooldown) // Decides to launch grenade
        {
            grenadeCooldown.restart();

            LaunchGrenade(output[3].activation, output[4].activation);
        };
    };
    void AI::Render(float Interpolation)
    {
        if (Interpolation > 0.75)
        {
            frame = 4;
        }
        else if (Interpolation > 0.5)
        {
            frame = 3;
        }
        else if (Interpolation > 0.25)
        {
            frame = 2;
        }
        else
        {
            frame = 1;
        };

        sf::Sprite sprite;

        sprite.setTexture(data->assetManager.GetTexture("AI Frame " + std::to_string(frame)));
        sprite.setScale(0.5, 0.5);
        sprite.setOrigin((sf::Vector2f)sprite.getTexture()->getSize() / 2.f);
    };
    // Genetic Algorithm Finally
    // Do it in this order: https://www.researchgate.net/profile/Rakesh-Phanden-2/publication/258477641/figure/fig1/AS:297476348235779@1447935296512/Flow-chart-of-working-of-Genetic-Algorithm.png

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
            int chance = std::rand() % binary.size(); // 1 in length of `binary`

            if (chance == 1)
            {
                binary[i] = ((binary[i] == '0') ? '1' : '0');
            }
        };

        brain.FromBinary(brain.Layers[0].size(), brain.Layers.size() - 2, brain.Layers[1].size(), brain.Layers[brain.Layers.size()].size(), binary);
    };
}