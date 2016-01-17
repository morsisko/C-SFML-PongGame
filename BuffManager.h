#ifndef BUFFMANAGER_H
#define BUFFMANAGER_H
#include <vector>
#include "InstantBallSpeed.h"
#include "SlowPlayer.h"
#include "SwapPaddles.h"
#include "Reverse.h"
#include "SpeedPaddle.h"
#include <iostream>
class BuffManager
{
private:
	std::vector<Buff*> buffsArray;
public:
	BuffManager();
	void addBuff(Buff* buff, GameObject *owner);
	void update(float deltaTime, GameObject *owner);
	~BuffManager();
};

#endif

