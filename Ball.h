#pragma once
#include "GameObject.h"
#include <iostream>
class Ball :
	public GameObject
{
private:
	GameObject *lastPlayer;
	direction dir;
public:
	Ball(float x, float y);
	void changeDirection();
	void move(float deltaTime);
	void onCollisionWithPaddle();
	void onCollisionWithWall();
	~Ball();
};

