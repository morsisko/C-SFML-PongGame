#include "Bonus.h"


Bonus::Bonus(float x, float y, sf::Texture texture, Buff *buff) : GameObject("Bonus", x, y, texture)
{
	this->buff = buff;
	type = BONUS;
}

Buff* Bonus::getBuff()
{
	return buff;
}

Bonus::~Bonus()
{
}
