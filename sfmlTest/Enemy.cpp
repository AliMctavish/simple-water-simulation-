#include "Enemy.h"

Enemy::Enemy()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(-5.f,5.f);
	this->velocity = dist(rd);
}

void Enemy::Render(float posX , float posY, float size)
{
	this->enemyTexture.setPosition(posX,posY);
	this->enemyTexture.setSize(sf::Vector2f(size,size));
	this->enemyTexture.setFillColor(sf::Color::Blue);
	this->enemyTexture.setOutlineColor(sf::Color::White);
	this->enemyTexture.setOutlineThickness(.5f);
	this->size = size;
	this->enemyPosition.x = posX;
	this->enemyPosition.y = posY;
}

void Enemy::Update()
{
	this->enemyTexture.move(0.f,2.f);
	//this->velocity += 0.1;
}

void Enemy::ground()
{
	this->enemyTexture.move(this->velocity, -1.f);
}

void Enemy::Collide(sf::Vector2f pos)
{
	pos.x = this->enemyTexture.getPosition().x;
	pos.y = this->enemyTexture.getPosition().y;
	this->enemyTexture.setPosition(pos.x,pos.y);
}







