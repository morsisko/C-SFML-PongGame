#pragma once
#include <SFML\Graphics.hpp>
class State
{
public:
	State();
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
	virtual ~State();
};

