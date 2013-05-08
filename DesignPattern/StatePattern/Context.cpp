#include "Context.h"
#include "State.h"

#include <iostream>

Context::Context()
{

}

Context::Context(State *state)
{
  this->_state = state;
}

Context::~Context()
{
  delete _state;
}

Context::OperationInterface()
{
  _state->OperationState(this);
}

bool Context::ChangeState(State *state)
{
  this->_state = state;
  return true;
}

void OperationChangeState(State *state)
{
  _state->OperationChangeState(this);
}
