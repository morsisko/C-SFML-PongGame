#include "Ball.h"


Ball::Ball(float x, float y) : GameObject("Ball", x, y, "ball.png")
{
	type = BALL;
	position.x -= (collider.width / 2);
	position.y -= (collider.height / 2);
	updateCollider(false);
	dir = LEFT;
	setSpeed(800.0f, 0.0f);
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
	setSpeed(this->getOriginalSpeed().horizonSpeed, 3 * (lastColliderObject->getCollider().top + (lastColliderObject->getCollider().height / 2) - (this->position.y + (this->collider.height / 2))));
}

void Ball::onCollisionWithWall()
{
	reverseVerticalSpeed();
}

GameObject* Ball::getLastPlayer()
{
	return lastPlayer;
}


Ball::~Ball()
{
}
