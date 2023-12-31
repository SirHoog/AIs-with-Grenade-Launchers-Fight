#include "GameEngine/stateMachine.hpp"

namespace SirHoog
{
    void StateMachine::AddState(StateRef _newState, bool _isReplacing)
    {
        isAdding = true;
        isReplacing = _isReplacing;

        newState = _newState;
    };
    void StateMachine::RemoveState()
    {
        isRemoving = true;
    };
    void StateMachine::ProcessStateChanges()
    {
        if (isRemoving && !states.empty())
        {
            if (isReplacing)
            {
                states.pop();
            }
            else
            {
                states.top()->Pause();
            }
        };

        states.push(newState);
        
        if (isAdding)
        {
            states.top()->Init();
        };

        isAdding = false;
    };
    StateRef &StateMachine::GetActiveState()
    {
        return states.top();
    }
}