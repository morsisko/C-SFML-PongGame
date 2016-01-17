#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML\Graphics.hpp>

class BuffManager;
enum direction {LEFT, RIGHT, UP, DOWN};
enum objectType {PLAYER, BALL, WALL, BONUS};
struct Speed
{
	float horizonSpeed = 0.0f;
	float verticalSpeed = 0.0f;
};
class GameObject : public sf::Drawable
{
private:
	sf::Texture texture;
	sf::Sprite drawableSprite;
protected:
	GameObject *lastColliderObject;
	sf::Vector2f position;
	sf::FloatRect collider;
	sf::Vector2f bounds;
	objectType type;
	Speed originalSpeed;
	std::string name;
	int bumps = 0;
	bool isSpeeding = false;
	Speed speedingSpeed;
public:
	bool reserved = false;
	BuffManager *manager;
	Speed currentSpeed;
	float speeding = 0.0f;
	float speedToHorizion = 0.0f;
	GameObject(std::string name, float x, float y, sf::Texture texture);
	GameObject(std::string name, float x, float y, std::string filename);
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
	void setLastCollider(GameObject *object);
	GameObject* getLastCollider();
	sf::FloatRect getCollider();
	sf::Vector2f &getPosition();
	std::string getName();
	int getBumps();
	void setSpeeding(float horizonSpeed, float verticalSpeed, float speeding, bool isSpeeding);
	Speed getOriginalSpeed();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;// override;
	~GameObject();
};

#endif

