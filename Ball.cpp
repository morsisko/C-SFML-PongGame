#include "Ball.h"


Ball::Ball(float x, float y) : GameObject(x, y, "ball.png")
{
	position.x -= (collider.width / 2);
	position.y -= (collider.height / 2);
	updateCollider(false);
	dir = LEFT;
	verticalSpeed = 0.0f;
	horizonSpeed = 450.0f;
}

void Ball::changeDirection()
{
	if (dir == LEFT) dir = RIGHT;
	else dir = LEFT;
}

void Ball::move(float deltaTime)
{
	GameObject::move(deltaTime, dir);
}

void Ball::onCollisionWithPaddle()
{
	changeDirection();
	verticalSpeed = 2 * (lastColliderObject->getCollider().top + (lastColliderObject->getCollider().height / 2) - (this->position.y + (this->collider.height / 2)));
	std::cout << "Roznica od srodka: " << verticalSpeed << std::endl;
}

void Ball::onCollisionWithWall()
{
	verticalSpeed *= -1;
}


Ball::~Ball()
{
}
