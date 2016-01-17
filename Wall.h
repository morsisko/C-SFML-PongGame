#ifndef WALL_H
#define WALL_H
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	Wall(std::string name, float x, float y);
	~Wall();
};

#endif

