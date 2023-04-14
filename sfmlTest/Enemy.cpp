#include "Enemy.h"

Enemy::Enemy()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(-5,5);
	this->velocity = dist(rd);
}

void Enemy::Render(sf::Vector2f position, float size)
{
	this->enemyTexture.setPosition(position.x, position.y);
	this->enemyTexture.setSize(sf::Vector2f(size,size));
	this->enemyTexture.setFillColor(sf::Color::Blue);
	this->enemyTexture.setOutlineColor(sf::Color::White);
	this->enemyTexture.setOutlineThickness(.5f);
	this->size = size;
	this->enemyPosition.x = position.x;
	this->enemyPosition.y = position.y;
}

void Enemy::Update()
{
	this->enemyTexture.setPosition(this->enemyPosition.x, this->enemyPosition.y++);
	//this->velocity += 0.1;
}

void Enemy::ground()
{
	std::cout << this->velocity;
	this->enemyTexture.setPosition(this->enemyPosition.x = this->enemyPosition.x  + this->velocity, this->enemyPosition.y--);
}

void Enemy::Collide(sf::Vector2f pos)
{
	pos.x = this->enemyTexture.getPosition().x;
	pos.y = this->enemyTexture.getPosition().y;
	this->enemyTexture.setPosition(pos.x,pos.y);
}







