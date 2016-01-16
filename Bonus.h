#ifndef BONUS_H
#define BONUS_H
#include "GameObject.h"
#include "Buff.h"
class Bonus :
	public GameObject
{
private:
	Buff *buff;
public:
	Bonus(float x, float y, sf::Texture texture, Buff *buff);
	Buff* getBuff();
	void onCollision(GameObject *object);
	~Bonus();
};

#endif

