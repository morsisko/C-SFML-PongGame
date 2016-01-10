#include "GameStateManager.h"
#include "MenuState.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	GameStateManager *gsm = new GameStateManager(new MenuState(&window));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		gsm->render(&window);

		window.display();
	}

	return 0;
}