#include "Game.h"
#include "Enemy.h"
#include "Object.h"
#include "Sand.h"
#include <sstream>


std::vector<Enemy> enemies;
std::vector<Object> objects;
std::vector<Sand> sands;




void Game::initVariables()
{
	this->font.loadFromFile("Richard Samuels.otf");
	this->myText.setFont(this->font);
	this->myText.setCharacterSize(20);
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
	this->videoMode.height =600;
	this->videoMode.width  = 800;
	this->window = new sf::RenderWindow(this->videoMode, "doing weird stuff", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}





Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initText();
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


void Game::initText()
{
	this->myText.setPosition(10,10);
	this->myText.setFillColor(sf::Color::White);

}



void Game::updateText()
{
	std::stringstream ss;
	ss << "number of particles : " << enemies.size();
	this->myText.setString(ss.str());
}




void Game::Controllers()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Enemy enemy;
		enemy.Render(&this->mousePosView.x,&this->mousePosView.y);
		enemies.push_back(enemy);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Object platform;
		platform.inIt(&this->mousePosView.x,&this->mousePosView.y);
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
	for (int i = 0  ; i < enemies.size(); i++)
	{
		enemies[i].Update();
		if (enemies[i].enemyTexture.getPosition().y > this->window->getSize().y)
		{
			enemies.erase(enemies.begin() + i);
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
	this->updateText();
}

void Game::render()
{
	this->window->clear();
	for (auto& object : objects)
	{
	 this->window->draw(object.objectTexture);
	}

	
	this->window->draw(this->myText);

	for (auto& enemy : enemies)
	{
	  this->window->draw(enemy.enemyTexture);
	}
	for (auto& sand : sands)
	{
		this->window->draw(sand.sandTexutre);
	}
	this->window->display();
}









