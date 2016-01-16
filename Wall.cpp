#include "Wall.h"


Wall::Wall(float x, float y) : GameObject(x, y, "wall.png")
{
	type = WALL;
}


Wall::~Wall()
{
}
