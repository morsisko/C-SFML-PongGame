#include "SlowPlayer.h"


SlowPlayer::SlowPlayer()
{
	target = PLAYER_O;
}

void SlowPlayer::onBuffStart(GameObject *object)
{
	if (object->isType(PLAYER)) object->currentSpeed.verticalSpeed -= 100.0f;
	std::cout << "someone got slow" << std::endl;
}

void SlowPlayer::onBuffEnd(GameObject *object)
{
	object->currentSpeed.verticalSpeed += 100.0f;
}


SlowPlayer::~SlowPlayer()
{
}
