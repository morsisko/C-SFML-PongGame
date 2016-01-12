#include "GameStateManager.h"


GameStateManager::GameStateManager()
{
	;
}

void GameStateManager::init(State* currentState)
{
	this->currentState = currentState;
}

void GameStateManager::render()
{
	currentState->render();
}

void GameStateManager::update(float deltaTime)
{
	currentState->update(deltaTime);
}

void GameStateManager::setState(State* state)
{
	currentState->destroy();
	currentState = state;
}


GameStateManager::~GameStateManager()
{
}
