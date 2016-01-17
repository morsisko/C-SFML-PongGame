#include "GameObject.h"
#include "BuffManager.h"

GameObject::GameObject(std::string name, float x, float y, sf::Texture texture)
{
	position.x = x;
	position.y = y;
	this->texture = texture;
	drawableSprite.setTexture(this->texture);
	bounds.x = this->texture.getSize().x;
	bounds.y = this->texture.getSize().y;
	updateCollider(true);
	manager = new BuffManager();
	this->name = name;
}

GameObject::GameObject(std::string name, float x, float y, std::string filename)
{
	position.x = x;
	position.y = y;
	loadTexture(filename);
	bounds.x = texture.getSize().x;
	bounds.y = texture.getSize().y;
	updateCollider(true);
	manager = new BuffManager();
	this->name = name;

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
	if (reserved)
	{
		if (dir == UP) dir = DOWN;
		else if (dir == DOWN) dir = UP;
		else if (dir == LEFT) dir = RIGHT;
		else if (dir == RIGHT) dir = LEFT;
	}

	if (isSpeeding)
	{
		if (speedingSpeed.horizonSpeed > currentSpeed.horizonSpeed) currentSpeed.horizonSpeed += (speeding * deltaTime);
		else if (speedingSpeed.horizonSpeed < currentSpeed.horizonSpeed) currentSpeed.horizonSpeed -= (speeding * deltaTime);
		else if (speedingSpeed.verticalSpeed > currentSpeed.verticalSpeed) currentSpeed.verticalSpeed += (speeding * deltaTime);
		else if (speedingSpeed.verticalSpeed < currentSpeed.verticalSpeed) currentSpeed.verticalSpeed -= (speeding * deltaTime);

		std::cout << currentSpeed.verticalSpeed << std::endl;
	}

	else currentSpeed = originalSpeed;

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
	originalSpeed = currentSpeed;
}

void GameObject::setVerticalSpeed(float verticalSpeed)
{
	this->currentSpeed.verticalSpeed = verticalSpeed;
}

void GameObject::reverseVerticalSpeed()
{
	this->currentSpeed.verticalSpeed *= -1;
	this->originalSpeed.verticalSpeed = this->currentSpeed.verticalSpeed;
}

bool GameObject::checkCollision(GameObject *object)
{
	if (object == nullptr) return false;

	if (object->lastColliderObject == nullptr)
	{
		if (collider.intersects(object->collider))
		{
			this->lastColliderObject = object;
			this->bumps++;
			object->lastColliderObject = this;
			object->bumps++;
			return true;
		}
	}

	else if (this->collider.intersects(object->collider) && (this != object->lastColliderObject))
	{
		this->lastColliderObject = object;
		this->bumps++;
		object->lastColliderObject = this;
		object->bumps++;
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

sf::Vector2f& GameObject::getPosition()
{
	return position;
}

void GameObject::updateBuffs(float deltaTime)
{
	manager->update(deltaTime, this);
}

void GameObject::setLastCollider(GameObject *object) //ues only if you know that's it little "cheat"
{
	lastColliderObject = object;
}

GameObject* GameObject::getLastCollider()
{
	return lastColliderObject;
}

std::string GameObject::getName()
{
	return name;
}

int GameObject::getBumps()
{
	return bumps;
}

void GameObject::setSpeeding(float horizonSpeed, float verticalSpeed, float speeding, bool isSpeeding)
{
	speedingSpeed.horizonSpeed = horizonSpeed;
	speedingSpeed.verticalSpeed = verticalSpeed;
	this->speeding = speeding;
	this->isSpeeding = isSpeeding;
}

Speed GameObject::getOriginalSpeed()
{
	return originalSpeed;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(drawableSprite, states);
}


GameObject::~GameObject()
{
	delete manager;
}
