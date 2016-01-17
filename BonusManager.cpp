#include "BonusManager.h"


BonusManager::BonusManager(sf::Vector2u windowSize)
{
	manager = new TextureManager();
	minX = 100;
	maxX = windowSize.x - 150;
	minY = 5;
	maxY = windowSize.y - 60;

	addRandomBonus();
}

void BonusManager::checkColision(Ball *ball)
{
	if (ball == nullptr) return;
	if (ball->getLastPlayer() == nullptr) return;

	for (int i = 0; i != bonusArray.size(); i++)
	{
		if (bonusArray[i]->getCollider().intersects(ball->getCollider()))
		{
			if (bonusArray[i]->getBuff()->target == BALL_O) ball->manager->addBuff(bonusArray[i]->getBuff(), ball);
			else if (bonusArray[i]->getBuff()->target == PLAYER_O) ball->getLastPlayer()->manager->addBuff(bonusArray[i]->getBuff(), ball->getLastPlayer());
			delete bonusArray[i];
			bonusArray.erase(bonusArray.begin() + i);
			break;
		}
	}
}

void BonusManager::addRandomBonus()
{
	int xPos = (std::rand() % (maxX - minX)) + minX;
	int yPos = (std::rand() % (maxY - minY)) + minY;

	int bonusType = std::rand() % (bonusCounter * 2);

	if (bonusType == INSTANT_BALL_SPEED) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSpeedBonus(), new InstantBallSpeed()));
	else if (bonusType == REVERSE_PLAYER_MOVEMENT) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getReverseBonus(), new Reverse()));
	else if (bonusType == SLOW_PLAYER) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSlowBonus(), new SlowPlayer()));
	else if (bonusType == SWAP_PADDLES) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSwapBonus(), new SwapPaddles()));
	else if (bonusType == SPEED_PADDLE) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSpeedPaddleBonus(), new SpeedPaddle()));

	std::cout << "Bonus type: " << bonusType << " xPos: " << xPos << " yPos: " << yPos << "\n";
}

void BonusManager::addBonusById(int id)
{
	int xPos = (std::rand() % (maxX - minX)) + minX;
	int yPos = (std::rand() % (maxY - minY)) + minY;

	if (id == INSTANT_BALL_SPEED) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSpeedBonus(), new InstantBallSpeed()));
	else if (id == REVERSE_PLAYER_MOVEMENT) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getReverseBonus(), new Reverse()));
	else if (id == SLOW_PLAYER) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSlowBonus(), new SlowPlayer()));
	else if (id == SWAP_PADDLES) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSwapBonus(), new SwapPaddles()));
	else if (id == SPEED_PADDLE) bonusArray.push_back(new Bonus((float)xPos, (float)yPos, manager->getSpeedPaddleBonus(), new SpeedPaddle()));
}

void BonusManager::update(float deltaTime)
{
	elapsedTime += deltaTime;
	if (elapsedTime >= bonusTimeResp)
	{
		elapsedTime = 0.0f;
		//addBonusById(SPEED_PADDLE);
		addRandomBonus();
	}
}

void BonusManager::render(sf::RenderWindow *window)
{
	for (int i = 0; i != bonusArray.size(); i++)
	{
		window->draw(*bonusArray[i]);
	}

}


BonusManager::~BonusManager()
{
	delete manager;
}
