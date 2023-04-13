#include "Enemy.h"



Enemy::Enemy(sf::Vector2f position , int size)
{
	
	this->enemyPosition = position;
	this->enemyTexture.setFillColor(sf::Color::Green);
	this->enemyTexture.setPosition(this->enemyPosition.x, this->enemyPosition.y);
	this->enemyTexture.setOutlineColor(sf::Color::Yellow);
	this->enemyTexture.setOutlineThickness(size);
}





void Enemy::Update()
{

}




