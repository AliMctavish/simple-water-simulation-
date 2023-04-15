#pragma once
#include "SFML/Graphics.hpp"
#include <random>


class Sand {
public :
	//SAND CTOR
	Sand(float posX , float posY);

	//INIT VARIALBES
	float velocity;
	sf::RectangleShape sandTexutre;
	sf::Vector2f sandPos;
	void init();

	void ground(std::vector<Sand> sands);

	//UPDATE SAND POSITION 
	void update();

};
