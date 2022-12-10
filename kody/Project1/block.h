#pragma once
#include <SFML/Graphics.hpp>
class Block
{
private:
	sf::Vector2f pos;
	sf::Texture tekstura;
	sf::Sprite block;

public:
	Block(float x_in, float y_in);
	void bdraw(sf::RenderWindow& window);
	void move();
	sf::Sprite getSprite();
	/*int score(sf:: Sprite sprite, int wynik);*/
	sf::FloatRect getBounds();
};

