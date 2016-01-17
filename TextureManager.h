#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML\Graphics.hpp>
class TextureManager
{
private:
	sf::Texture speedBonus;
	sf::Texture reverseBonus;
	sf::Texture slowBonus;
	sf::Texture swapBonus;
	sf::Texture speedPaddleBonus;
public:
	TextureManager();
	sf::Texture getSpeedBonus();
	sf::Texture getReverseBonus();
	sf::Texture getSlowBonus();
	sf::Texture getSwapBonus();
	sf::Texture getSpeedPaddleBonus();
	~TextureManager();
};

#endif
