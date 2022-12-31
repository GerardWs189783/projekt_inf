#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
private:
	sf::Vector2f position;
	sf::Texture tekstura;
	sf::Sprite skin;
public:
	Paddle(sf::RenderWindow& window);
	void move(sf::Vector2f mov);

	sf::Sprite getSprite();
	sf::Sprite* getSpritep();
	sf::Vector2f getpos();

	void pdraw(sf::RenderWindow& window);
};

