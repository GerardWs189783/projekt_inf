#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
private:
	sf::Vector2f position;
	sf::Texture tekstura;
	sf::Sprite skin;
public:
	Paddle(float x_in, float y_in);
	void move(sf::Vector2f mov);

	sf::Sprite getSprite();
	sf::Sprite* getSpritep();
	sf::Vector2f getpos();

	void pdraw(sf::RenderWindow& window);
};

