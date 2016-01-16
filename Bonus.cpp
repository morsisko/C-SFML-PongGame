#include "Bonus.h"


Bonus::Bonus(float x, float y, sf::Texture texture, Buff *buff) : GameObject(x, y, texture)
{
	this->buff = buff;
	type = BONUS;
}

void Bonus::onCollision(GameObject *object)
{
	if (object->isType(BALL)) {};
}

Buff* Bonus::getBuff()
{
	return buff;
}

Bonus::~Bonus()
{
}
