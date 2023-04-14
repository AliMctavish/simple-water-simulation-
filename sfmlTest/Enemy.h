#pragma once
#include <vector>
#include "SFML/Graphics.hpp"



class Enemy {
public :
	sf::Vector2f enemyPosition;
	sf::RectangleShape enemyTexture;
	float size = 1;
	float velocity = 1;

	void CreateEnemy()
	{

	}

	void Collide(sf::Vector2f pos);

	void Update();

	void Render(sf::Vector2f position , float size);
};






