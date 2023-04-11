#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>


class Game
{
private:

	void initVariables();
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev; 

	void initWindow();

	void initEnemies();

	//Game Object

	sf::RectangleShape enemy;
	float enemyPosX = 20;
	float enemyPosY = 20;



public :
	//construct
	Game();
	//destruct
	virtual ~Game();
	

	//Accessors

	const bool running() const {
		return this->window->isOpen();
	};


	//functions
	void pollEvents();

	void Update();

	void render();

};

