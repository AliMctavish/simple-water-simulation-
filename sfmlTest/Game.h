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

	//Game Objects

	sf::RectangleShape enemy;
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;
	sf::Font font; 
	sf::Text myText;
	float enemyPosX;
	float enemyPosY;
	float size;



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

	void initGrid();

	void Controllers();

	void EnemyUpdate();

	void UpdateMousePosition();

	void Update();


	void render();

};

