#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(int x, int y, playerNumber number) : GameObject(x, y, "player" + std::to_string((int)number) + ".png")
{
	type = PLAYER;
	position.y -= (collider.height / 2);
	updateCollider(false);
	currentSpeed.verticalSpeed = 450.0f;
}


PlayerPaddle::~PlayerPaddle()
{
}
