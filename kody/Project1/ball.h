#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
class Ball
{
private:
	sf::Vector2f position;
	float xVel = 2.5, yVel = 2.5;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f romzmiar_okna;
	sf::FloatRect ballbound;
	sf::Text scoretext;
	sf::Font font;
	int score;
	void scoreinit();
public:
	Ball(float x_in, float y_in, float rx_in, float ry_in);
	void przesun(float x_in, float y_in);
	sf::Sprite getBall();
	void sprawdzKolizjeSciany();
	void animuj(sf::Sprite sprite, sf::Sprite sprite1);
	void sprawdzKolizjeObiektu(sf::Sprite sprite);
	/*bool isCollidingWithBlock(Block* block);*/
	//Metoda zbieraj¹ca isCllliding i potem z polem score dzaila?
	/*int scorecount(Block* block);*/
	//void scoreprint();
	void drawt(sf::RenderWindow& window);
	void scoreincr(sf::Sprite sprite);
};

