#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
class GameStateManager
{
private:
	State* currentState;
public:
	GameStateManager();
	void init(State* currentState);
	void setState(State* state);
	void update(float deltaTime);
	void render(sf::RenderWindow *window);
	~GameStateManager();
};

#endif

