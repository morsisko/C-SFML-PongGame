#pragma once
#include "Buff.h"
class SlowPlayer :
	public Buff
{
public:
	SlowPlayer();
	virtual void onBuffStart(GameObject *object);
	virtual void onBuffEnd(GameObject *object);
	~SlowPlayer();
};

