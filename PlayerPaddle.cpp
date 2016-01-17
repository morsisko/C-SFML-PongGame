#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(std::string name, int x, int y, playerNumber number) : GameObject(name, x, y, "player" + std::to_string((int)number) + ".png")
{
	type = PLAYER;
	position.y -= (collider.height / 2);
	updateCollider(false);
	setSpeed(0.0f, 450.0f);
	this->number = number;

}

PlayerPaddle* PlayerPaddle::getEnemy()
{
	return enemy;
}

void PlayerPaddle::move(float deltaTime, direction dir)
{
	if (position.y < 10) position.y = 10;
	else if (position.y + bounds.y > 790) position.y = 790 - bounds.y;
	GameObject::move(deltaTime, dir);
}

int PlayerPaddle::getPlayerNumber()
{
	return (int)number;
}

void PlayerPaddle::setEnemy(PlayerPaddle *enemy)
{
	this->enemy = enemy;
}

PlayerPaddle::~PlayerPaddle()
{
}
