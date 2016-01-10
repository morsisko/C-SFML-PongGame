#pragma once
#include "State.h"
class GameStateManager
{
private:
	State* currentState;
public:
	GameStateManager(State* state);
	void setState(State* state);
	void update(float deltaTime);
	void render(sf::RenderWindow *window);
	~GameStateManager();
};

