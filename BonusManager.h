#ifndef BONUSMANAGER_H
#define BONUSMANAGER_H
#include "Bonus.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "BuffManager.h"
#include "Ball.h"
#include <vector>
enum BonusType {INSTANT_BALL_SPEED, REVERSE_PLAYER_MOVEMENT, SLOW_PLAYER, SWAP_PADDLES, SPEED_PADDLE};
class BonusManager
{
private:
	std::vector<Bonus*> bonusArray;
	TextureManager *manager;
	int minX, minY, maxX, maxY;
	float elapsedTime = 0.0f;
	float bonusTimeResp = 1.0f;
	int bonusCounter = 5;
public:
	BonusManager(sf::Vector2u windowSize);
	void checkColision(Ball *object);
	void addRandomBonus();
	void addBonusById(int id); // only for debug
	void update(float deltaTime);
	void render(sf::RenderWindow *window);
	~BonusManager();
};

#endif

