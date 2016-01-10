#pragma once
#include <SFML\Graphics.hpp>

enum direction {LEFT, RIGHT, UP, DOWN, LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN};
class GameObject : public sf::Drawable
{
protected:
	sf::Vector2f position;
	sf::Vector2f bounds;
	sf::FloatRect collider;
	sf::Sprite drawableSprite;
	float speed = 1.0f;
public:
	GameObject(float x, float y);
	GameObject(float x, float y, float width, float height);
	void setColliderBounds(float width, float height);
	void updateCollider(bool includeBounds);
	void move(float deltaTime, direction dir);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;// override;
	~GameObject();
};

