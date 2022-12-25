#pragma once
#include <SFML/Graphics.hpp>
#include "ball.h"
class Lifeheart
{
private:
	sf::Font font;
	sf::Text hptext;
	sf::Vector2f textpos;

public:
	Lifeheart(sf::RenderWindow& window);
	void lifeinit(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getpos();

};

