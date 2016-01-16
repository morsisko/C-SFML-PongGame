#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML\Graphics.hpp>
class TextureManager
{
private:
	sf::Texture speedBonus;
public:
	TextureManager();
	sf::Texture getSpeedBonus();
	~TextureManager();
};

#endif
