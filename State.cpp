#include "State.h"


State::State(sf::RenderWindow *window, GameStateManager* gsm)
{
	this->gsm = gsm;
	this->window = window;
}

State::State()
{
	;
}

State::~State()
{
}
