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
	;
}

void GameState::destroy()
{
	;
}


GameState::~GameState()
{
}
