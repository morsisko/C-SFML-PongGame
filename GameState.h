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
class MenuState;
class GameState :
	public State
{
private:
	PlayerPaddle *player1;
	PlayerPaddle *player2;
	Ball *ball;
	GameObject *topWall;
	GameObject *bottomWall;
	sf::Sprite *background;
	sf::Texture backgroundTexture;
	BonusManager *bmanager;
	bool pause = false;
	int redPoints = 0;
	int bluePoints = 0;
	sf::Font *font;
	sf::Text scoreText;
	sf::Text winText;
	sf::Text bumpText;
	sf::Text pressEscText;
	sf::Text bumps;
	void pauseGame();
	GameObject* addPointsForWinner();
	bool isGameEnd();
public:
	GameState(sf::RenderWindow *window, GameStateManager *gsm, int redPoints = 0, int bluePoints = 0);
	virtual void render() override;
	virtual void update(float deltaTime) override;
	virtual void destroy() override;
	~GameState();
};

#endif

