#ifndef STATE_H
#define STATE_H
#pragma once
#include <SFML\Graphics.hpp>
class GameStateManager;
class State
{
protected:
	GameStateManager* gsm;
public:
	State(GameStateManager* gsm);
	State();
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
	virtual void destroy() = 0;
	virtual ~State();
};

#endif

