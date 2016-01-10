#ifndef MENUSTATE_H
#define MENUSTATE_H
#pragma once
#include "SFML\Graphics.hpp"
#include "GameState.h"
#include "GameStateManager.h"
class MenuState : public State
{
private:
	sf::Text* mainText;
	sf::Text* startGame;
	sf::Text* quitGame;
	sf::Font* font;
	sf::Vector2i mouse;
public:
	MenuState(sf::RenderWindow* window, GameStateManager *gsm);
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(float deltaTime) override;
	virtual void destroy() override;
	~MenuState();
};

#endif

