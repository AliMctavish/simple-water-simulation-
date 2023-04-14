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

	void initObjects();

	//Game Objects

	sf::RectangleShape enemy;
	float enemyPosX = 20;
	float enemyPosY = 20;
	float size = 1;



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

	void Controllers();

	void Update();

	void render();

};

