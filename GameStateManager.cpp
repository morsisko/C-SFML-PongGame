#include "GameStateManager.h"


GameStateManager::GameStateManager()
{
	;
}

void GameStateManager::init(State* currentState)
{
	this->currentState = currentState;
}

void GameStateManager::render(sf::RenderWindow *window)
{
	currentState->render(window);
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
