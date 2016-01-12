#pragma once
#include <SFML\Graphics.hpp>

enum direction {LEFT, RIGHT, UP, DOWN};
class GameObject : public sf::Drawable
{
private:
	sf::Texture texture;
protected:
	GameObject *lastColliderObject;
	sf::Sprite drawableSprite;
	sf::Vector2f position;
	sf::FloatRect collider;
	sf::Vector2f bounds;
	float horizonSpeed = 1.0f;
	float verticalSpeed = 0.0f;
public:
	GameObject(float x, float y, std::string filename);
	GameObject(float x, float y, float width, float height);
	void loadTexture(std::string filename);
	void setColliderBounds(float width, float height);
	void updateCollider(bool includeBounds);
	void move(float deltaTime, direction dir);
	void setSpeed(float horizonSpeed, float verticalSpeed);
	void setVerticalSpeed(float verticalSpeed);
	void reverseVerticalSpeed();
	bool checkCollision(GameObject *object);
	sf::FloatRect getCollider();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;// override;
	~GameObject();
};

