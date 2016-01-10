#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(int x, int y, playerNumber number) : GameObject(x, y)
{
	paddleTexture.loadFromFile("assets/player" + std::to_string((int)number) + ".png");
	drawableSprite.setTexture(paddleTexture);
}


PlayerPaddle::~PlayerPaddle()
{
}
