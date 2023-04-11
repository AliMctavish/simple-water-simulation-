#pragma once
#include "SFML/Graphics.hpp"


class Game
{
private:

	void initVariables();
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev; 

	void initWindow();

public :
	Game();

	virtual ~Game();

	void Update();


	void render();

};

