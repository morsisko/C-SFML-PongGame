#include "InstantBallSpeed.h"


InstantBallSpeed::InstantBallSpeed()
{
	target = BALL_O;
}

void InstantBallSpeed::onBuffStart(GameObject *object)
{
	if (object->isType(BALL)) object->currentSpeed.horizonSpeed += 200.0f;
}

void InstantBallSpeed::onBuffEnd(GameObject *object)
{
	object->currentSpeed.horizonSpeed -= 200.0f;
}


InstantBallSpeed::~InstantBallSpeed()
{
}
