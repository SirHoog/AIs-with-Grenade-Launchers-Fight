#include <random>
#include "neuralNetwork.hpp"
#include "grenade.hpp"

namespace SirHoog
{
    bool RocketJumping = false;

    std::vector<AI> AI_List = {};

    class AI : public Entity
    {
        int Generation = 0;
        int Fitness = 0;
        NeuralNetwork brain;
        
        float AimAngle = 0;
        float Power = 0;
        std::vector<Grenade> GrenadeList = {};
        
        public:
            float Health = 100;
            sf::Color Color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);

            AI(sf::Vector2f Position = {0, 0}, sf::Vector2f Velocity = {0, 0}, bool affectedByGravity = true) : Entity() {};

            void Update(std::vector<float> input, sf::RenderWindow &window)
            {
                Layer output = brain.Update(input);

                for (Grenade grenade : GrenadeList)
                {
                    grenade.Update(window, AI_List);
                }
            };

            void TakeDamage(float damage, Grenade &grenade)
            {
                for (Grenade _grenade : GrenadeList)
                {
                    if (&_grenade != &grenade)
                    {
                        Health -= damage;
                    }
                }
            }

            void LaunchGrenade()
            {
                GrenadeList.push_back(Grenade(Position, sf::Vector2f(std::sin(AimAngle), std::cos(AimAngle)) * Power, true));
            };
    };
}