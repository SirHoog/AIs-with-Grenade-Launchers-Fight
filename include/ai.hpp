#include <random>
#include "neuralNetwork.hpp"
#include "grenade.hpp"

using namespace SirHoog;

namespace SirHoog
{
    class AI : public Entity
    {
        int Generation = 0;
        int Fitness = 0;
        NeuralNetwork brain = NeuralNetwork("", 6, 3, 8, 4); // Input: X, Y, Closest Enemy X, Closest Enemy Y, Closest Grenade X, Closest Grenade Y // Output: Horizontal Movement, Jump
        
        float AimAngle = 0;
        float Power = 0;
        std::vector<Grenade> GrenadeList = {};
        
        public:
            std::vector<AI> AI_List = {};

            float Health = 100;
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true, NeuralNetwork neuralNetwork = NeuralNetwork("", 6, 3, 8, 4)) : Entity() {};
            ~AI() {};

            void Update(sf::RenderWindow &window)
            {
                // Find input

                Layer input = {};

                input.neurons.push_back(Position.x); // X
                input.neurons.push_back(Position.y); // Y

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

                input.neurons.push_back(closestAI.Position.x); // Enemy X
                input.neurons.push_back(closestAI.Position.y); // Enemy Y

                float closestGrenadeDistance;
                Grenade closestGrenade;

                for (AI ai : AI_List)
                {
                    for (Grenade grenade : ai.GrenadeList)
                    {
                        float distance = std::sqrt(std::pow(grenade.Position.x - Position.x, 2) + std::pow(grenade.Position.y - Position.y, 2));

                        if (distance < closestGrenadeDistance)
                        {
                            closestGrenadeDistance = distance;
                            closestGrenade = grenade;
                        }
                    }
                };

                input.neurons.push_back(closestGrenade.Position.x); // Grenade X
                input.neurons.push_back(closestGrenade.Position.y); // Grenade Y

                // Update attributes

                Layer output = brain.Update(input);

                for (Grenade grenade : GrenadeList)
                {
                    grenade.Update(window);
                };

                // Move

                float x = output.neurons[0].activation * WalkSpeed; // < 0 = Left // > 0 = Right
                float jump = (output.neurons[1].activation > 0) * JumpHeight; // > 0 = Decides to jump
                
                this->Velocity -= {x, jump};
            };
                
            // Genetic Algorithm Finally
            // Do it in this order: https://www.researchgate.net/profile/Rakesh-Phanden-2/publication/258477641/figure/fig1/AS:297476348235779@1447935296512/Flow-chart-of-working-of-Genetic-Algorithm.png

            // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=15
            void crossOver(AI with)
            {
                int n = std::rand() % (brain.ToBinary().length() - 2) + 1;

                brain.FromBinary(6, 3, 8, 4, brain.ToBinary().substr(0, n) + with.brain.ToBinary().substr(n));
            };

            // https://web.stanford.edu/group/sisl/k12/optimization/MO-unit2-pdfs/2.15stochastic2annealing,genetic.pdf#page=17
            void mutate()
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

                brain.FromBinary(brain.Layers[0].neurons.size(), brain.Layers.size() - 2, brain.Layers[1].neurons.size(), brain.Layers[brain.Layers.size()].neurons.size(), binary);
            };

            void LaunchGrenade()
            {
                GrenadeList.push_back(Grenade(Position, sf::Vector2f(std::sin(AimAngle), std::cos(AimAngle)) * Power, true));
            };

            void ExplodeGrenade()
            {
                for (Grenade grenade : GrenadeList)
                {
                    if (grenade.isExploding())
                    {
                        for (AI ai : AI_List)
                        {
                            if (this == &ai && !SelfDamage)
                            {
                                return;
                            };
                            
                            float distance = std::sqrt(std::pow(grenade.Position.x - ai.Position.x, 2) + std::pow(grenade.Position.y - ai.Position.y, 2));

                            if (distance < BlastRadius)
                            {
                                float damage = (BlastRadius - distance) / BlastRadius;

                                ai.Health -= damage;

                                if (RocketJumping)
                                {
                                    ai.Velocity -= (ai.Position - Position) * damage;
                                }
                            }
                        }
                    }
                    
                }
            }
    };
}