#include "SwapPaddles.h"


SwapPaddles::SwapPaddles()
{
	target = PLAYER_O;
}

void SwapPaddles::onBuffStart(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		sf::Vector2f tempPosition = ((PlayerPaddle*)object)->getEnemy()->getPosition();
		((PlayerPaddle*)object)->getEnemy()->getPosition() = object->getPosition();
		object->getPosition() = tempPosition;

		object->updateCollider(false);
		((PlayerPaddle*)object)->getEnemy()->updateCollider(false);

		object->getLastCollider()->setLastCollider(nullptr); // so firstly we get the ball, next set the last collider to nullptr
	}
}
void SwapPaddles::onBuffEnd(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		sf::Vector2f tempPosition = ((PlayerPaddle*)object)->getEnemy()->getPosition();
		((PlayerPaddle*)object)->getEnemy()->getPosition() = object->getPosition();
		object->getPosition() = tempPosition;

		object->updateCollider(false);
		((PlayerPaddle*)object)->getEnemy()->updateCollider(false);

		object->getLastCollider()->setLastCollider(nullptr); // after the buff we again set the last ball collider to nullptr
	}
}


SwapPaddles::~SwapPaddles()
{
}
