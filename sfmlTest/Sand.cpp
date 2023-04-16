#include "Sand.h"

void Sand::init()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(-1.f,1.f);
	this->velocity = dist(rd);
}


Sand::Sand(float posX, float posY)
{
	this->sandTexutre.setPosition(posX, posY);
	this->sandTexutre.setFillColor(sf::Color::Green);
	this->sandTexutre.setSize(sf::Vector2f(4,4));
	this->sandTexutre.setOutlineColor(sf::Color::White);
	this->sandTexutre.setOutlineThickness(0.f);
	this->sandPos = sf::Vector2f(posX, posY);

}

void Sand::update()
{
	this->sandTexutre.move(0.f, 3.f);
}

void Sand::ground(std::vector<Sand> sands)
{
	for (int i = 0; i < sands.size(); i++)
	{
		if (this->sandTexutre.getPosition().y > sands[i].sandTexutre.getPosition().y)
		{
			this->sandTexutre.move(0,this->velocity);
		}
	}
	//this->sandTexutre.setPosition(this->sandPos.x, this->sandPos.y--);
}