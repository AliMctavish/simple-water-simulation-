#include "Object.h"


void Object::inIt(float posX, float posY)
{
	this->objectTexture.setPosition(posX,posY);
	this->objectTexture.setSize(sf::Vector2f(50, 30));
	this->objectTexture.setFillColor(sf::Color::Red);
	this->objectTexture.setOutlineColor(sf::Color::White);
	this->objectTexture.setOutlineThickness(1);
	this->position.x = posX;
	this->position.y = posY;
}


void Object::render()
{

}











