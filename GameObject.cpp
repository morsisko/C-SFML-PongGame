#include "GameObject.h"
GameObject::GameObject(float x, float y, std::string filename)
{
	position.x = x;
	position.y = y;
	updateCollider(false);
	loadTexture(filename);

}

GameObject::GameObject(float x, float y, float width, float height)
{
	position.x = x;
	position.y = y;
	bounds.x = width;
	bounds.y = height;
	updateCollider(true);
}

void GameObject::loadTexture(std::string filename)
{
	texture.loadFromFile("assets/" + filename);
	drawableSprite.setTexture(texture);
}

void GameObject::updateCollider(bool includeBounds)
{
	collider.left = position.x;
	collider.top = position.y;

	if (includeBounds)
	{
		collider.width = bounds.x;
		collider.height = bounds.y;
	}

	drawableSprite.setPosition(position);
}

void GameObject::setColliderBounds(float width, float height)
{
	collider.width = width;
	collider.height = height;
}

void GameObject::move(float deltaTime, direction dir)
{
	if (dir == UP)
	{
		position.y -= (speed * deltaTime);
	}
	
	else if (dir == DOWN)
	{
		position.y += (speed * deltaTime);
	}

	else if (dir == LEFT)
	{
		position.x -= (speed * deltaTime);
	}

	else if (dir == RIGHT)
	{
		position.x += (speed * deltaTime);
	}

	else if (dir == LEFTUP)
	{
		position.x -= (speed * deltaTime);
		position.y -= (speed * deltaTime);
	}

	else if (dir == RIGHTUP)
	{
		position.x += (speed * deltaTime);
		position.y -= (speed * deltaTime);
	}

	else if (dir == LEFTDOWN)
	{
		position.x -= (speed * deltaTime);
		position.y += (speed * deltaTime);
	}

	else if (dir == RIGHTDOWN)
	{
		position.x += (speed * deltaTime);
		position.y += (speed * deltaTime);
	}

	updateCollider(false);
}

void GameObject::setSpeed(float speed)
{
	this->speed = speed;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(drawableSprite, states);
}


GameObject::~GameObject()
{
}
