#include "Enemy.h"




void Enemy::Render(sf::Vector2f position, float size)
{
	this->enemyPosition = position;
	this->enemyTexture.setFillColor(sf::Color::Green);
	this->enemyTexture.setPosition(this->enemyPosition.x, this->enemyPosition.y);
	this->enemyTexture.setOutlineColor(sf::Color::Yellow);
	this->enemyTexture.setOutlineThickness(size);
}


//void Enemy::Update()
//{
//	this->enemyPosition.x += 0.1f;
//	this->enemyTexture.setRotation(this->enemyPosition.y);
//}







