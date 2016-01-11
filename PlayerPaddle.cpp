#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(int x, int y, playerNumber number) : GameObject(x, y, "player" + std::to_string((int)number) + ".png")
{
	speed = 150.0f;
}


PlayerPaddle::~PlayerPaddle()
{
}
