#pragma once
#include "Buff.h"
#include "PlayerPaddle.h"
class Reverse :
	public Buff
{
public:
	Reverse();
	virtual void onBuffStart(GameObject *object);
	virtual void onBuffEnd(GameObject *object);
	~Reverse();
};

