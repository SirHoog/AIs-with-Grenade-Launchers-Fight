#pragma once

#include <memory>
#include <stack>
#include "state.hpp"

namespace SirHoog
{
    typedef std::shared_ptr<State> StateRef;

    class StateMachine
    {
        std::stack<StateRef> states;
        StateRef newState;
        
        bool isRemoving;
        bool isAdding;
        bool isReplacing;
        
        public:
            StateMachine() {};
            ~StateMachine() {};

            void AddState(StateRef newState, bool _isReplacing = true);
            void RemoveState();
            
            void ProcessStateChanges();

            StateRef &GetActiveState();
    };
}