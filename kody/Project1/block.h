#pragma once
#include <SFML/Graphics.hpp>
class Block
{
protected:
	sf::Vector2f pos;
	sf::Texture tekstura;
	sf::Sprite block;
	int hp;
	void posinit();
public:
	Block(/*float x_in, float y_in*/);
	void bdraw(sf::RenderWindow& window);
	void move();
	sf::Sprite getSprite();
	sf::Sprite* getSpritep();
	/*int score(sf:: Sprite sprite, int wynik);*/
	sf::FloatRect getBounds();
	void animacja();
	void setpos(sf::Vector2f posin);
	sf::Vector2f getpos();
	// void czy floatrect przesuniêcie wewn¹trz rysunku jako animacja, ten ma 1 hp a kolejne dziedzicz¹ce wiêcej
};

