#pragma once

#include <memory>
#include <stack>
#include "state.hpp"

namespace SirHoog
{
    // typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
        public:
            StateMachine() {};
            ~StateMachine() {};

            void AddState(std::unique_ptr<State> newState, bool _isReplacing = true);
            void RemoveState();
            
            void ProcessStateChanges();

            std::unique_ptr<State> &GetActiveState();
        private:
            std::stack<std::unique_ptr<State>> states;
            std::unique_ptr<State> newState;
            
            bool isRemoving;
            bool isAdding;
            bool isReplacing;
    };
}