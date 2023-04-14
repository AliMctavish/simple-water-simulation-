#include "Enemy.h"




void Enemy::Render(sf::Vector2f position, float size)
{
	this->enemyTexture.setPosition(position.x, position.y);
	this->enemyTexture.setSize(sf::Vector2f(size,size));
	this->enemyTexture.setFillColor(sf::Color::Red);
	this->enemyTexture.setOutlineColor(sf::Color::White);
	this->enemyTexture.setOutlineThickness(1.f);
}




//void Enemy::Update()
//{
//	this->enemyPosition.x += 0.1f;
//	this->enemyTexture.setRotation(this->enemyPosition.y);
//}







