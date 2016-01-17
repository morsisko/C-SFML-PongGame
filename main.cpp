#include "GameStateManager.h"
#include "MenuState.h"
int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 800), "SFML works!");
	window.setFramerateLimit(60);
	sf::Clock frameClock;
	GameStateManager *gsm = new GameStateManager();
	gsm->init(new MenuState(&window, gsm));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		gsm->update(frameClock.restart().asSeconds());
		gsm->render();

		window.display();
	}

	return 0;
}