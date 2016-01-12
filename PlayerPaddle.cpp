#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(int x, int y, playerNumber number) : GameObject(x, y, "player" + std::to_string((int)number) + ".png")
{
	position.y -= (collider.height / 2);
	updateCollider(false);
	verticalSpeed = 450.0f;
}


PlayerPaddle::~PlayerPaddle()
{
}
