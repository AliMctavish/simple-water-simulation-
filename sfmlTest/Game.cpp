#include "Game.h"
#include "Enemy.h"
#include "Object.h"
#include "Sand.h"

std::vector<Enemy> enemies;
std::vector<Object> objects;
std::vector<Sand> sands;

void Game::initVariables()
{
	this->window = nullptr;
	this->enemyPosX = 20;
	this->enemyPosY = 20;
	this->size = 1;
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Enemy enemy;
		enemy.Render(this->mousePosView.x,this->mousePosView.y);
		enemies.push_back(enemy);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Object platform;
		platform.inIt(this->mousePosView.x,this->mousePosView.y);
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Sand sand(this->mousePosView.x,this->mousePosView.y);
		sands.push_back(sand);
	}

}

void Game::EnemyUpdate()
{
	for (auto& enemy : enemies)
	{
		enemy.Update();
		if (enemy.enemyTexture.getPosition().y > this->window->getSize().y)
		{
			enemies.erase(enemies.begin());
		}
	}
	for (auto& sand : sands)
	{
		if (sand.isGrounded == false)
		{
		sand.update();
		}
		if (sand.sandTexutre.getPosition().y > this->window->getSize().y)
		{
			sands.erase(sands.begin());
		}
	}
	for (auto& object : objects)
	{
		for (auto& enemy : enemies)
		{
			if (object.objectTexture.getGlobalBounds().contains(enemy.enemyTexture.getPosition()))
			{
				enemy.ground();
			}
		}
	}
}

void Game::UpdateMousePosition()
{
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::Update()
{
	this->pollEvents();
	this->Controllers();
	this->UpdateMousePosition();
	this->EnemyUpdate();
}

void Game::render()
{
	this->window->clear();
	for (int i = 0; i < objects.size(); i++)
	{
	 this->window->draw(objects[i].objectTexture);
	}

	for (int i = 0; i < enemies.size(); i++)
	{
	  this->window->draw(enemies[i].enemyTexture);
	}
	for (int i = 0; i < sands.size(); i++)
	{
		this->window->draw(sands[i].sandTexutre);
	}
	this->window->display();
}









