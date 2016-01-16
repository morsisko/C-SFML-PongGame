#ifndef BONUSMANAGER_H
#define BONUSMANAGER_H
#include "Bonus.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "BuffManager.h"
#include "Ball.h"
#include <vector>
class BonusManager
{
private:
	std::vector<Bonus*> bonusArray;
	TextureManager *manager;
public:
	BonusManager();
	void checkColision(Ball *object);
	void render(sf::RenderWindow *window);
	~BonusManager();
};

#endif

