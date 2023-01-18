#pragma once
#include <SFML/Graphics.hpp>
#include "lifeheart.h"
#include <iostream>

class Heart
{
private:
	int hp;
	sf::Sprite heart;
	sf::Texture hearthtex;
	sf::Vector2f heartpos;
public:
	Heart(sf::RenderWindow &window, Lifeheart *lh);
	void draw(sf::RenderWindow& window);
	int dechp();
	sf::Vector2f gethpos();
	int gethp();
	sf::FloatRect getBounds();
	void setpos(sf::Vector2f posin);
	sf::Vector2f getpos();
	sf::Sprite* getsprt();
	void sethp(int h);
	/*sf::FloatRect*/
};

