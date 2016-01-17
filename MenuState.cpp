#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, GameStateManager *gsm) : State(window, gsm)
{
	font = new sf::Font();
	font->loadFromFile("assets/TransformersMovie.ttf");

	mainText = new sf::Text("PingPong Game", *font, 71);
	mainText->setPosition(window->getSize().x / 2 - mainText->getGlobalBounds().width / 2, window->getSize().y / 2 - mainText->getGlobalBounds().height / 2 - 200);
	startGame = new sf::Text("Start", *font, 50);
	startGame->setPosition(window->getSize().x / 2 - startGame->getGlobalBounds().width / 2, window->getSize().y / 2 - startGame->getGlobalBounds().height / 2);
	quitGame = new sf::Text("Quit", *font, 50);
	quitGame->setPosition(window->getSize().x / 2 - quitGame->getGlobalBounds().width / 2, window->getSize().y / 2 - quitGame->getGlobalBounds().height / 2 + 100);

}

void MenuState::render()
{
	mouse = sf::Mouse::getPosition(*window);
	window->draw(*mainText);
	window->draw(*startGame);
	window->draw(*quitGame);
}

void MenuState::update(float deltaTime)
{
	if (quitGame->getGlobalBounds().contains(mouse.x, mouse.y))
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			window->close();
		else
		quitGame->setColor(sf::Color::Blue);
	else
		quitGame->setColor(sf::Color::White);

	if (startGame->getGlobalBounds().contains(mouse.x, mouse.y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			gsm->setState(new GameState(window, gsm));
		}
		else
			startGame->setColor(sf::Color::Blue);
	}
	else
		startGame->setColor(sf::Color::White);
}

void MenuState::destroy()
{
	delete mainText;
	delete startGame;
	delete quitGame;
	delete font;
}


MenuState::~MenuState()
{
	delete mainText;
	delete startGame;
	delete quitGame;
	delete font;
}
