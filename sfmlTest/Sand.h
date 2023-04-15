#pragma once
#include "SFML/Graphics.hpp"


class Sand {
public :
	//SAND CTOR
	Sand(float posX , float posY);

	//INIT VARIALBES
	sf::RectangleShape sandTexutre;
	sf::Vector2f sandPos;
	void init();

	void ground();

	//UPDATE SAND POSITION 
	void update();

};
