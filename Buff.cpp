#include "Buff.h"


Buff::Buff()
{
	;
}

bool Buff::isOverTime()
{
	return elapsedTime > buffDuration;
}

void Buff::update(float deltaTime)
{
	elapsedTime += deltaTime;
}


Buff::~Buff()
{
}
