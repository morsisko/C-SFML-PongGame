#include "Ball.h"


Ball::Ball(float x, float y) : GameObject(x, y, "ball.png")
{
	type = BALL;
	position.x -= (collider.width / 2);
	position.y -= (collider.height / 2);
	updateCollider(false);
	dir = LEFT;
	currentSpeed.verticalSpeed = 0.0f;
	currentSpeed.horizonSpeed = 800.0f;
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
	lastPlayer = lastColliderObject;
	currentSpeed.verticalSpeed = 3 * (lastColliderObject->getCollider().top + (lastColliderObject->getCollider().height / 2) - (this->position.y + (this->collider.height / 2)));
}

void Ball::onCollisionWithWall()
{
	currentSpeed.verticalSpeed *= -1;
}

GameObject* Ball::getLastPlayer()
{
	return lastPlayer;
}


Ball::~Ball()
{
}
