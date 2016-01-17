#include "SpeedPaddle.h"


SpeedPaddle::SpeedPaddle()
{
	buffDuration = 2.5f;
	target = PLAYER_O;
}

void SpeedPaddle::onBuffStart(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		Speed currentObjectSpeed = object->currentSpeed;
		object->setSpeeding(currentObjectSpeed.horizonSpeed, currentObjectSpeed.verticalSpeed + 350.0f, 200.0f, true);
	}
}

void SpeedPaddle::onBuffEnd(GameObject *object)
{
	if (object->isType(PLAYER))
	{
		Speed originalSpeed = object->getOriginalSpeed();
		object->setSpeeding(originalSpeed.horizonSpeed, originalSpeed.verticalSpeed, 200.0f, false);
	}
}


SpeedPaddle::~SpeedPaddle()
{
}
