#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Enemy {

	sf::Vector2f enemyPosition;
	sf::RectangleShape enemyTexture;
	Enemy(sf::Vector2f position , int size);
	
	~Enemy();


	void CreateEnemy()
	{

	}

	void Update();

	void Draw();
};






