#ifndef BUFF_H
#define BUFF_H
#include "GameObject.h"
enum BuffTarget {ALL, BALL_O, PLAYER_O};
class Buff
{
private:
	float buffDuration = 5.0f;
	float elapsedTime = 0.0f;
public:
	Buff();
	BuffTarget target;
	void update(float deltaTime);
	bool isOverTime();
	virtual void onBuffStart(GameObject *ball) = 0;
	virtual void onBuffEnd(GameObject *ball) = 0;
	~Buff();
};

#endif

