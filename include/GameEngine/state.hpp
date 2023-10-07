#pragma once

namespace SirHoog
{
    class State
    {
        public:
            virtual void Init() = 0;

            virtual void HandleInput();
            virtual void Update(float dt);
            virtual void Render(float Interpolation);

            virtual void GameSpeed(int _TPS);
    };
}