#include "GameState.h"


GameState::GameState(GameStateManager *gsm) : State(gsm)
{
	player1 = new PlayerPaddle(50.0f, 50.0f, FIRST);
	player2 = new PlayerPaddle(700.0f, 50.0f, SECOND);
}

void GameState::render(sf::RenderWindow* window)
{
	window->draw(*player1);
	window->draw(*player2);
}

void GameState::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player1->move(deltaTime, UP);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player1->move(deltaTime, DOWN);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player2->move(deltaTime, UP);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player2->move(deltaTime, DOWN);
}

void GameState::destroy()
{
	delete player1;
	delete player2;
}


GameState::~GameState()
{
}
