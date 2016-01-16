#include "TextureManager.h"


TextureManager::TextureManager()
{
	speedBonus.loadFromFile("assets/speed.png");
}

sf::Texture TextureManager::getSpeedBonus()
{
	return speedBonus;
}


TextureManager::~TextureManager()
{
}
