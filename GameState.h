#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerPaddle.h"
#include "State.h"
class GameState :
	public State
{
private:
	GameObject *player1;
	GameObject *player2;
public:
	GameState(GameStateManager *gsm);
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(float deltaTime) override;
	virtual void destroy() override;
	~GameState();
};

