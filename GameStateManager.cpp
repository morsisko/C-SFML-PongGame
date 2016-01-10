#include "GameStateManager.h"


GameStateManager::GameStateManager(State* state)
{
	currentState = state;
}


void GameStateManager::render(sf::RenderWindow *window)
{
	currentState->render(window);
}

void GameStateManager::update(float deltaTime)
{
	currentState->update(deltaTime);
}


GameStateManager::~GameStateManager()
{
}
