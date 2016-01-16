#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
enum playerNumber{FIRST, SECOND};

class PlayerPaddle :
	public GameObject
{
public:
	PlayerPaddle(int x, int y, playerNumber number);
	~PlayerPaddle();
};

#endif
