#include "GameState.h"


GameState::GameState(sf::RenderWindow *window, GameStateManager *gsm) : State(window, gsm)
{
	player1 = new PlayerPaddle(50.0f, window->getSize().y / 2, FIRST);
	player2 = new PlayerPaddle(1180.0f, window->getSize().y / 2, SECOND);
	ball = new Ball(window->getSize().x / 2, window->getSize().y / 2);
	topWall = new Wall(0.0f, 0.0f);
	bottomWall = new Wall(0, window->getSize().y - 5.0f);
	background = new sf::Sprite();
	backgroundTexture.loadFromFile("assets/background.png");
	background->setTexture(backgroundTexture);
	background->setPosition(0, 0);
}

void GameState::render()
{
	window->draw(*background);
	window->draw(*player1);
	window->draw(*player2);
	window->draw(*ball);
	window->draw(*topWall);
	window->draw(*bottomWall);
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

	if (player1->checkCollision(ball) || player2->checkCollision(ball))
		((Ball*)(ball))->onCollisionWithPaddle();

	if (topWall->checkCollision(ball) || bottomWall->checkCollision(ball))
		((Ball*)(ball))->onCollisionWithWall();

	((Ball*)(ball))->move(deltaTime);
}

void GameState::destroy()
{
	delete player1;
	delete player2;
	delete background;
	delete ball;
}


GameState::~GameState()
{
}
