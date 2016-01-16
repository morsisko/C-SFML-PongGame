#ifndef WALL_H
#define WALL_H
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	Wall(float x, float y);
	~Wall();
};

#endif

