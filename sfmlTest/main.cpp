#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "first sfml :D" , sf::Style::Titlebar | sf::Style::Close);
	sf::Event e;


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