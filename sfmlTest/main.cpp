#include <iostream>
#include "SFML/Graphics.hpp"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 800), "first sfml :D");
	Event e;


	while (window.isOpen())
	{
		window.clear(Color::Black);
		window.display();
		VertexBuffer vertix;
		vertix.create(30);
		window.draw(vertix);

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
	}


}