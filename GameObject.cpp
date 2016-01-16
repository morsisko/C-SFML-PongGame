#include "GameObject.h"
#include "BuffManager.h"

GameObject::GameObject(float x, float y, sf::Texture texture)
{
	position.x = x;
	position.y = y;
	this->texture = texture;
	drawableSprite.setTexture(this->texture);
	bounds.x = this->texture.getSize().x;
	bounds.y = this->texture.getSize().y;
	updateCollider(true);
	manager = new BuffManager();
}

GameObject::GameObject(float x, float y, std::string filename)
{
	position.x = x;
	position.y = y;
	loadTexture(filename);
	bounds.x = texture.getSize().x;
	bounds.y = texture.getSize().y;
	updateCollider(true);
	manager = new BuffManager();

}

GameObject::GameObject(float x, float y, float width, float height)
{
	position.x = x;
	position.y = y;
	bounds.x = width;
	bounds.y = height;
	updateCollider(true);
	manager = new BuffManager();
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
		position.y -= (currentSpeed.verticalSpeed * deltaTime);
	}
	
	else if (dir == DOWN)
	{
		position.y += (currentSpeed.verticalSpeed * deltaTime);
	}

	else if (dir == LEFT)
	{
		position.x -= (currentSpeed.horizonSpeed * deltaTime);
		position.y -= (currentSpeed.verticalSpeed * deltaTime);
	}

	else if (dir == RIGHT)
	{
		position.x += (currentSpeed.horizonSpeed * deltaTime);
		position.y -= (currentSpeed.verticalSpeed * deltaTime);
	}

	updateCollider(false);
}

void GameObject::setSpeed(float horizonSpeed, float verticalSpeed)
{
	this->currentSpeed.horizonSpeed = horizonSpeed;
	this->currentSpeed.verticalSpeed = verticalSpeed;
}

void GameObject::setVerticalSpeed(float verticalSpeed)
{
	this->currentSpeed.verticalSpeed = verticalSpeed;
}

void GameObject::reverseVerticalSpeed()
{
	this->currentSpeed.verticalSpeed *= -1;
}

bool GameObject::checkCollision(GameObject *object)
{
	if (object == nullptr) return false;

	if (object->lastColliderObject == nullptr)
	{
		if (collider.intersects(object->collider))
		{
			this->lastColliderObject = object;
			object->lastColliderObject = this;
			return true;
		}
	}

	else if (this->collider.intersects(object->collider) && this != object->lastColliderObject)
	{
		this->lastColliderObject = object;
		object->lastColliderObject = this;
		return true;
	}

	return false;
}

bool GameObject::isType(objectType type)
{
	return this->type == type;
}

sf::FloatRect GameObject::getCollider()
{
	return collider;
}

void GameObject::updateBuffs(float deltaTime)
{
	manager->update(deltaTime, this);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(drawableSprite, states);
}


GameObject::~GameObject()
{
	delete manager;
}
