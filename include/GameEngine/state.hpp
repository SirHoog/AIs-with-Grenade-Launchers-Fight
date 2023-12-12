#pragma once

namespace SirHoog
{
    class State
    {
        public:
            virtual void Init() = 0;

            virtual void HandleInput() = 0;
            virtual void Update(float dt) = 0;
            virtual void Render(float Interpolation) = 0;

            virtual void Pause() = 0;
    };
}