#ifndef INSTANTBALLSPEED_H
#define INSTANTBALLSPEED_H
#include "Buff.h"
class InstantBallSpeed :
	public Buff
{
public:
	InstantBallSpeed();
	virtual void onBuffStart(GameObject *object);
	virtual void onBuffEnd(GameObject *object);
	~InstantBallSpeed();
};

#endif

