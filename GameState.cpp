#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"


GameState::GameState(sf::RenderWindow *window, GameStateManager *gsm, int redPoints, int bluePoints) : State(window, gsm)
{
	player1 = new PlayerPaddle("Red player", 50.0f, window->getSize().y / 2, FIRST);
	player2 = new PlayerPaddle("Blue player", 1180.0f, window->getSize().y / 2, SECOND);
	ball = new Ball(window->getSize().x / 2, window->getSize().y / 2);
	topWall = new Wall("Top wall", 0.0f, 0.0f);
	bottomWall = new Wall("Bottom wall", 0, window->getSize().y - 10.0f);
	bmanager = new BonusManager(window->getSize());
	background = new sf::Sprite();
	font = new sf::Font();
	font->loadFromFile("assets/TransformersMovie.ttf");
	backgroundTexture.loadFromFile("assets/background.png");
	background->setTexture(backgroundTexture);
	background->setPosition(0, 0);

	((PlayerPaddle*)(player1))->setEnemy((PlayerPaddle*)(player2));
	((PlayerPaddle*)(player2))->setEnemy((PlayerPaddle*)(player1));
	this->redPoints = redPoints;
	this->bluePoints = bluePoints;

}

void GameState::render()
{
	window->draw(*background);
	window->draw(*player1);
	window->draw(*player2);
	window->draw(*ball);
	window->draw(*topWall);
	window->draw(*bottomWall);
	bmanager->render(window);

	if (pause)
	{
		window->draw(scoreText);
		window->draw(winText);
		window->draw(bumpText);
		window->draw(pressEscText);
		window->draw(bumps);
	}
}

void GameState::update(float deltaTime)
{
	if (!pause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player1->move(deltaTime, UP);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player1->move(deltaTime, DOWN);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			player2->move(deltaTime, UP);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			player2->move(deltaTime, DOWN);

		player1->updateBuffs(deltaTime);
		player2->updateBuffs(deltaTime);
		ball->updateBuffs(deltaTime);
		bmanager->checkColision(ball);
		bmanager->update(deltaTime);

		if (player1->checkCollision(ball) || player2->checkCollision(ball))
			ball->onCollisionWithPaddle();

		else if (topWall->checkCollision(ball) || bottomWall->checkCollision(ball))
			ball->onCollisionWithWall();

		if (isGameEnd())
		{
			pauseGame();
		}
		else ball->move(deltaTime);

	}

	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) gsm->setState(new GameState(window, gsm, redPoints, bluePoints));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) gsm->setState(new MenuState(window, gsm));
	}

}

GameObject* GameState::addPointsForWinner()
{
	GameObject *winner = nullptr;
	if (ball->getPosition().x < window->getSize().x / 2 && player1->getPosition().x < window->getSize().x / 2)
	{
		bluePoints++; //blue won
		winner = player2;
	}

	else if (ball->getPosition().x < window->getSize().x / 2 && player1->getPosition().x > window->getSize().x / 2)
	{
		redPoints++; // red won
		winner = player1;
	}

	else if (ball->getPosition().x > window->getSize().x / 2 && player1->getPosition().x < window->getSize().x / 2)
	{
		redPoints++;
		winner = player1;
	}

	else if (ball->getPosition().x > window->getSize().x / 2 && player1->getPosition().x > window->getSize().x / 2)
	{
		bluePoints++; //blue won
		winner = player2;
	}


	return winner;

}

void GameState::pauseGame()
{
	pause = true;

	GameObject *winner = addPointsForWinner();

	scoreText.setFont(*font);
	scoreText.setString(std::to_string(redPoints) + " : " + std::to_string(bluePoints));
	scoreText.setCharacterSize(80);
	scoreText.setPosition(window->getSize().x / 2 - scoreText.getGlobalBounds().width / 2, window->getSize().y / 2 - scoreText.getGlobalBounds().height / 2);

	if (winner != nullptr)
	{
		winText.setFont(*font);
		winText.setString("Winner: " + winner->getName());
		winText.setCharacterSize(40);
		winText.setPosition(window->getSize().x / 2 - winText.getGlobalBounds().width / 2, scoreText.getPosition().y + scoreText.getGlobalBounds().height + 50);
	}
	else std::cout << "woops" << std::endl;

	bumpText.setFont(*font);
	bumpText.setString("If you want play again press ENTER");
	bumpText.setCharacterSize(40);
	bumpText.setPosition(window->getSize().x / 2 - bumpText.getGlobalBounds().width / 2, scoreText.getPosition().y + scoreText.getGlobalBounds().height + winText.getGlobalBounds().height + 100);

	pressEscText.setFont(*font);
	pressEscText.setString("Otherwise press ESC");
	pressEscText.setCharacterSize(40);
	pressEscText.setPosition(window->getSize().x / 2 - pressEscText.getGlobalBounds().width / 2, bumpText.getPosition().y + bumpText.getGlobalBounds().height);

	bumps.setFont(*font);
	
	if (player1->getBumps() > player2->getBumps()) bumps.setString(player1->getName() + " bounced ball " + std::to_string(player1->getBumps()) + " times.");
	else if (player2->getBumps() > player1->getBumps()) bumps.setString(player2->getName() + " bounced ball " + std::to_string(player2->getBumps()) + " times.");
	else bumps.setString(player1->getName() + " and " + player2->getName() + " bounced ball " + std::to_string(player1->getBumps()) + " times.");

	bumps.setCharacterSize(40);
	bumps.setPosition(window->getSize().x / 2 - bumps.getGlobalBounds().width / 2, pressEscText.getPosition().y + pressEscText.getGlobalBounds().height);
}

bool GameState::isGameEnd()
{
	return (ball->getPosition().x <= 0 || ball->getPosition().x + ball->getCollider().width >= window->getSize().x);
}

void GameState::destroy()
{
	delete player1;
	delete player2;
	delete background;
	delete ball;
	delete topWall;
	delete bottomWall;
	delete bmanager;
	delete font;
}


GameState::~GameState()
{
}
