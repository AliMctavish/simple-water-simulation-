#pragma once
#include <vector>
#include "SFML/Graphics.hpp"



class Enemy {
public :
	sf::Vector2f enemyPosition;
	sf::RectangleShape enemyTexture;
	


	void CreateEnemy()
	{

	}

	void Update();

	void Render(sf::Vector2f position, float size);
};






