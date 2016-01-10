#include "MenuState.h"


MenuState::MenuState(sf::RenderWindow* window)
{
	font = new sf::Font();
	font->loadFromFile("assets/TransformersMovie.ttf");

	mainText = new sf::Text("PingPong Game", *font, 50);
	mainText->setPosition(window->getSize().x / 2 - mainText->getGlobalBounds().width / 2, window->getSize().y / 2 - mainText->getGlobalBounds().height / 2 - 200);
	startGame = new sf::Text("Start", *font);
	quitGame = new sf::Text("Quit", *font);
}

void MenuState::render(sf::RenderWindow* window)
{
	window->draw(*mainText);
}

void MenuState::update(float deltaTime)
{

}


MenuState::~MenuState()
{
	delete mainText;
	delete startGame;
	delete quitGame;
	delete font;
}
