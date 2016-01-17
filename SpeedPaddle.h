#pragma once
#include "Buff.h"
class SpeedPaddle :
	public Buff
{
public:
	SpeedPaddle();
	virtual void onBuffStart(GameObject *object);
	virtual void onBuffEnd(GameObject *object);
	~SpeedPaddle();
};

