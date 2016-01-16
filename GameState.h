#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerPaddle.h"
#include "Ball.h"
#include "State.h"
#include "Wall.h"
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "TextureManager.h"
#include "BonusManager.h"
class GameState :
	public State
{
private:
	GameObject *player1;
	GameObject *player2;
	Ball *ball;
	GameObject *topWall;
	GameObject *bottomWall;
	sf::Sprite *background;
	sf::Texture backgroundTexture;
	BonusManager *bmanager;
public:
	GameState(sf::RenderWindow *window, GameStateManager *gsm);
	virtual void render() override;
	virtual void update(float deltaTime) override;
	virtual void destroy() override;
	~GameState();
};

#endif

