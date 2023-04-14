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
	this->enemy.setPosition(this->enemyPosX,this->enemyPosY);
	this->enemy.setSize(sf::Vector2f(150.f,50.f));
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


void Game::initObjects()
{
	
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
}
void Game::Update()
{ 
	this->pollEvents();
	this->Controllers();

	// Update Mouse Position 
	 //std::cout << "Mouse position : " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
	// std::cout << "rectangle position : " << this->enemy.getPosition().x << " " << this->enemy.getPosition().y << std::endl;
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->enemy);

	for (auto& b : objects)
	{
		b.render();
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Enemy enemy;
		enemy.Render(sf::Vector2f(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y), 2);
		enemies.push_back(enemy);	
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Object platform;
		platform.inIt(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
		objects.push_back(platform);
	}

	/*for (int i = 0; i < objects.size(); i++)
	{
		
	}*/

	for (int i = 0; i < enemies.size(); i++)
	{
		if (this->enemy.getGlobalBounds().contains(enemies[i].enemyTexture.getPosition()))
		{
			enemies[i].ground();
		}
		else {
			enemies[i].Update();
		}

		for (int j = 0; j < objects.size(); j++)
		{
			if (objects[j].objectTexture.getGlobalBounds().contains(enemies[j].enemyTexture.getPosition()))
			{
				enemies[j].ground();
			}
			else {
				enemies[j].Update();
			}
			this->window->draw(objects[j].objectTexture);

		}
	
		this->window->draw(enemies[i].enemyTexture);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		enemies.clear();
	}

	this->window->display();
}









