#include "stateMachine.hpp"

namespace SirHoog
{
    void StateMachine::AddState(std::unique_ptr<State> _newState, bool _isReplacing)
    {
        isAdding = true;
        isReplacing = _isReplacing;

        newState = std::move(_newState);
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
                states.top()->GameSpeed(0);
            }
        };

        states.push(std::move(newState));
        states.top()->Init();
        isAdding = false;
    };
    std::unique_ptr<State> &StateMachine::GetActiveState()
    {
        return states.top();
    }
}