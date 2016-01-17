#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <iostream>
enum playerNumber{FIRST, SECOND};

class PlayerPaddle :
	public GameObject
{
private:
	PlayerPaddle *enemy;
	playerNumber number;
public:
	PlayerPaddle(std::string name, int x, int y, playerNumber number);
	PlayerPaddle *getEnemy();
	void move(float deltaTime, direction dir);
	void setEnemy(PlayerPaddle* enemy);
	int getPlayerNumber();
	~PlayerPaddle();
};

#endif
