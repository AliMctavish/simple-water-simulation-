#include "Game.h"
#include "Enemy.h"

std::vector<Enemy> enemies;

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initEnemies()
{
	this->enemy.setPosition(this->enemyPosX,this->enemyPosY);
	this->enemy.setSize(sf::Vector2f(100.f,100.f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(1.f);
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "first sfml :D", sf::Style::Titlebar | sf::Style::Close);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX--, this->enemyPosY));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX++, this->enemyPosY));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX, this->enemyPosY--));
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->enemy.setPosition(sf::Vector2f(this->enemyPosX, this->enemyPosY++));
	}
}

void Game::Update()
{ 
	this->pollEvents();

	this->Controllers();

	// Update Mouse Position 
	 std::cout << "Mouse position : " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
	 std::cout << "rectangle position : " << this->enemy.getPosition().x << " " << this->enemy.getPosition().y << std::endl;
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->enemy);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Enemy enemy;
		enemy.Render(sf::Vector2f(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y), this->size++);
		enemies.push_back(enemy);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Enemy enemy;
		enemy.Render(sf::Vector2f(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y), this->size--);
		enemies.push_back(enemy);
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		this->window->draw(enemies[i].enemyTexture);
		enemies[i].enemyPosition.y--;
	}

	this->window->display();
}









