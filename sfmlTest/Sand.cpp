#include "Sand.h"

void Sand::init()
{

}


Sand::Sand(float posX, float posY)
{
	this->sandTexutre.setPosition(posX, posY);
	this->sandTexutre.setFillColor(sf::Color::Green);
	this->sandTexutre.setSize(sf::Vector2f(4,4));
	this->sandTexutre.setOutlineColor(sf::Color::White);
	this->sandTexutre.setOutlineThickness(1.f);
	this->sandPos = sf::Vector2f(posX, posY);

}

void Sand::update()
{
	this->sandTexutre.setPosition(this->sandPos.x, this->sandPos.y++);
}

void Sand::ground()
{

}