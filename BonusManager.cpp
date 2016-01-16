#include "BonusManager.h"


BonusManager::BonusManager()
{
	manager = new TextureManager();
	bonusArray.push_back(new Bonus(400.0f, 400.0f, manager->getSpeedBonus(), new SlowPlayer()));
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
			bonusArray.erase(bonusArray.begin() + i);
			break;
		}
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
