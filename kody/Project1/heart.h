#pragma once
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "lifeheart.h"

class Heart
{
private:
	int hp;
	sf::Sprite heart;
	sf::Texture hearthtex;
	sf::Vector2f heartpos;
public:
	Heart(sf::RenderWindow &window, Lifeheart* lh);
	void draw(sf::RenderWindow& window);
	int dechp();
	void animuj(Ball* b);
	sf::Vector2f gethpos();
};

