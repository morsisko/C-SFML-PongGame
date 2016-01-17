#ifndef STATE_H
#define STATE_H
#pragma once
#include <SFML\Graphics.hpp>
//#include "GameStateManager.h"
class GameStateManager;
class State
{
protected:
	GameStateManager* gsm;
	sf::RenderWindow *window;
public:
	State(sf::RenderWindow *window, GameStateManager* gsm);
	State();
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
	virtual void destroy() = 0;
	virtual ~State();
};

#endif

