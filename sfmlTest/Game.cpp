#include "Game.h"
#include "Enemy.h"
#include "Object.h"

std::vector<Enemy> enemies;
std::vector<Object> objects;

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initEnemies()
{
	this->enemy.setPosition(this->enemyPosX, this->enemyPosY);
	this->enemy.setSize(sf::Vector2f(150.f, 50.f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(1.f);
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "doing weird stuff", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->window->close();
			break;
		}
	}
}

void Game::Controllers()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX--, this->enemyPosY));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX++, this->enemyPosY));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX, this->enemyPosY--));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX, this->enemyPosY++));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Enemy enemy;
		enemy.Render(sf::Vector2f(
			sf::Mouse::getPosition(*this->window).x,
			sf::Mouse::getPosition(*this->window).y),
			5);
		enemies.push_back(enemy);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Object platform;
		platform.inIt(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
		objects.push_back(platform);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		enemies.clear();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		objects.clear();
	}

}
void Game::Update()
{
	this->pollEvents();
	this->Controllers();
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Update();
		if (enemies[i].enemyTexture.getPosition().y > this->window->getSize().y)
		{
			enemies.erase(enemies.begin() + i);
		}
	}
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = 0; j < enemies.size(); j++)
		{
			if (objects[i].objectTexture.getGlobalBounds().contains(enemies[j].enemyTexture.getPosition()))
			{
				enemies[j].ground();
			}
		}
	}
	//Update Mouse Position 
	//std::cout << "Mouse position : " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
	//std::cout << "rectangle position : " << this->enemy.getPosition().x << " " << this->enemy.getPosition().y << std::endl;
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->enemy);


	for (int i = 0; i < objects.size(); i++)
	{
	 this->window->draw(objects[i].objectTexture);
	}

	for (int i = 0; i < enemies.size(); i++)
	{
	  this->window->draw(enemies[i].enemyTexture);
	}



	this->window->display();
}









