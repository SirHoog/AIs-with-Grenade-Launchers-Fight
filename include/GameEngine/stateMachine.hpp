#pragma once

#include <memory>
#include <stack>
#include "state.hpp"

namespace SirHoog
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
        public:
            StateMachine() {};
            ~StateMachine() {};

            void AddState(StateRef newState, bool _isReplacing = true);
            void RemoveState();
            
            void ProcessStateChanges();

            StateRef &GetActiveState();
        private:
            std::stack<StateRef> states;
            StateRef newState;
            
            bool isRemoving;
            bool isAdding;
            bool isReplacing;
    };
}