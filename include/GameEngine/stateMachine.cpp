#include "stateMachine.hpp"

namespace SirHoog
{
    void StateMachine::AddState(StateRef newState, bool isReplacing)
    {
        _isAdding = true;
        _isReplacing = isReplacing;

        _newState = std::move(newState);
    };
    void StateMachine::RemoveState()
    {
        _isRemoving = true;
    };
    void StateMachine::ProcessStateChanges()
    {
        if (_isRemoving && !_states.empty())
        {
            if (_isReplacing)
            {
                _states.pop();
            }
            else
            {
                _states.top()->GameSpeed(0);
            }
        };

        _states.push(std::move(_newState));
        _states.top()->Init();
        _isAdding = false;
    }

    StateRef &StateMachine::GetActiveState()
    {
        return _states.top();
    }
}