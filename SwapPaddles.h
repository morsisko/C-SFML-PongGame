#pragma once
#include "Buff.h"
class SwapPaddles :
	public Buff
{
public:
	SwapPaddles();
	virtual void onBuffStart(GameObject *object);
	virtual void onBuffEnd(GameObject *object);
	~SwapPaddles();
};

