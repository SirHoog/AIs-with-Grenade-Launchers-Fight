#include "animation.hpp"

namespace SirHoog
{
    Animation::Animation
    (
        GameDataRef data,
        sf::Sprite sprite,
        sf::IntRect startFrame,
        sf::IntRect endFrame,
        float duration,
        bool loop,
        bool Playing,
        bool horizontal
    ) :
    data(data),
    sprite(sprite),
    startFrame(startFrame),
    endFrame(endFrame),
    duration(duration),
    loop(loop),
    Playing(Playing),
    horizontal(horizontal)
    {
        currentFrame = startFrame;
    };
    void Animation::Update(float dt)
    {
        if (Playing) {
            float UpdateSpeed = TPS / DefaultTPS;

            int animationLength;
            sf::Vector2i framePosition;

            if (horizontal)
            {
                animationLength = endFrame.getPosition().x - startFrame.getPosition().x;

                framePosition = sf::Vector2i((elapsedTime / duration) * animationLength, startFrame.getPosition().y);
            }
            else
            {
                animationLength = endFrame.getPosition().y - startFrame.getPosition().y;

                framePosition = sf::Vector2i(startFrame.getPosition().x, (elapsedTime / duration) * animationLength);
            };
            
            currentFrame = sf::IntRect(framePosition, startFrame.getSize());

            elapsedTime += dt * UpdateSpeed;
        }
    };
    void Animation::Render(float interpolation)
    {
        if (elapsedTime > duration && loop)
        {
            elapsedTime = 0;

            currentFrame = startFrame;
        };

        sprite.setTextureRect(currentFrame);
    };
}