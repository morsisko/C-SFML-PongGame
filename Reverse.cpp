#include "Reverse.h"


Reverse::Reverse()
{
	target = PLAYER_O;
}

void Reverse::onBuffStart(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		GameObject *enemy = ((PlayerPaddle*)object)->getEnemy();
		enemy->reserved = !enemy->reserved;
	}
}
void Reverse::onBuffEnd(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		GameObject *enemy = ((PlayerPaddle*)object)->getEnemy();
		enemy->reserved = !enemy->reserved;
	}
}


Reverse::~Reverse()
{
}
