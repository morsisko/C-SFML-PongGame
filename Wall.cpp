#include "Wall.h"


Wall::Wall(std::string name, float x, float y) : GameObject(name, x, y, "wall.png")
{
	type = WALL;
}


Wall::~Wall()
{
}
