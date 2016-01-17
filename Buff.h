#ifndef BUFF_H
#define BUFF_H
#include "PlayerPaddle.h"
enum BuffTarget {ALL, BALL_O, PLAYER_O};
class Buff
{
protected:
	float buffDuration = 5.0f;
	float elapsedTime = 0.0f;
public:
	Buff();
	BuffTarget target;
	void update(float deltaTime);
	bool isOverTime();
	virtual void onBuffStart(GameObject *object) = 0;
	virtual void onBuffEnd(GameObject *object) = 0;
	~Buff();
};

#endif

