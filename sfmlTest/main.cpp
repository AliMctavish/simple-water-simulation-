#include <iostream>
#include "Game.h"



int main()
{

	Game game;


	while (window.isOpen())
	{

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
				window.close();
			break;
		}

		window.clear(sf::Color::Black);
		window.display();

	}

	return 0;
}