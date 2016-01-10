#pragma once
#include "State.h"
#include "SFML\Graphics.hpp"
class MenuState : public State
{
private:
	sf::Text* mainText;
	sf::Text* startGame;
	sf::Text* quitGame;
	sf::Font* font;
public:
	MenuState(sf::RenderWindow* window);
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(float deltaTime) override;
	~MenuState();
};

