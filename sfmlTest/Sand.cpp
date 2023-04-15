#include "Sand.h"

void Sand::init()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(-5, 5);
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
	this->sandTexutre.setPosition(this->sandPos.x, this->sandPos.y++);
}

void Sand::ground(std::vector<Sand> sands)
{
	for (int i = 0; i < sands.size(); i++)
	{
		if (this->sandTexutre.getGlobalBounds().contains(sands[i].sandTexutre.getPosition()))
		{
			this->sandTexutre.setPosition(this->sandPos.x, this->sandPos.y--);
		}
	}
	//this->sandTexutre.setPosition(this->sandPos.x, this->sandPos.y--);
}