#include "TextureManager.h"


TextureManager::TextureManager()
{
	speedBonus.loadFromFile("assets/speed.png");
	reverseBonus.loadFromFile("assets/reverse.png");
	slowBonus.loadFromFile("assets/slow.png");
	swapBonus.loadFromFile("assets/swap.png");
	speedPaddleBonus.loadFromFile("assets/speedpaddle.png");
}

sf::Texture TextureManager::getSpeedBonus()
{
	return speedBonus;
}

sf::Texture TextureManager::getReverseBonus()
{
	return reverseBonus;
}

sf::Texture TextureManager::getSlowBonus()
{
	return slowBonus;
}

sf::Texture TextureManager::getSwapBonus()
{
	return swapBonus;
}

sf::Texture TextureManager::getSpeedPaddleBonus()
{
	return speedPaddleBonus;
}

TextureManager::~TextureManager()
{
}
