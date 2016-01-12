#include "GameObject.h"
GameObject::GameObject(float x, float y, std::string filename)
{
	position.x = x;
	position.y = y;
	loadTexture(filename);
	bounds.x = texture.getSize().x;
	bounds.y = texture.getSize().y;
	updateCollider(true);

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
		position.y -= (verticalSpeed * deltaTime);
	}
	
	else if (dir == DOWN)
	{
		position.y += (verticalSpeed * deltaTime);
	}

	else if (dir == LEFT)
	{
		position.x -= (horizonSpeed * deltaTime);
		position.y -= (verticalSpeed * deltaTime);
	}

	else if (dir == RIGHT)
	{
		position.x += (horizonSpeed * deltaTime);
		position.y -= (verticalSpeed * deltaTime);
	}

	updateCollider(false);
}

void GameObject::setSpeed(float horizonSpeed, float verticalSpeed)
{
	this->horizonSpeed = horizonSpeed;
	this->verticalSpeed = verticalSpeed;
}

void GameObject::setVerticalSpeed(float verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}

void GameObject::reverseVerticalSpeed()
{
	this->verticalSpeed *= -1;
}

bool GameObject::checkCollision(GameObject *object)
{
	if (this->collider.intersects(object->collider) && this != object->lastColliderObject)
	{
		this->lastColliderObject = object;
		object->lastColliderObject = this;
		return true;
	}

	else return false;
}

sf::FloatRect GameObject::getCollider()
{
	return collider;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(drawableSprite, states);
}




GameObject::~GameObject()
{
}
