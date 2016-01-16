#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML\Graphics.hpp>

class BuffManager;
enum direction {LEFT, RIGHT, UP, DOWN};
enum objectType {PLAYER, BALL, WALL, BONUS};
struct Speed
{
	float horizonSpeed = 1.0f;
	float verticalSpeed = 0.0f;
};
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
	objectType type;
	Speed originalSpeed;
public:
	BuffManager *manager;
	Speed currentSpeed;
	float speeding = 0.0f;
	float speedToHorizion = 0.0f;
	GameObject(float x, float y, sf::Texture texture);
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
	bool isType(objectType type);
	void updateBuffs(float deltaTime);
	sf::FloatRect getCollider();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;// override;
	~GameObject();
};

#endif

