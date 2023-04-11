#pragma once
#include "SFML/Graphics.hpp"


class Game
{
private:

	void initVariables();
	void initWindow();

public :
	Game();

	virtual ~Game();

	void Update();


	void render();

};

