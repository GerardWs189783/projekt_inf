#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
#include "paddle.h"
#include "blockTab.h"
#include "heart.h"
#include <vector>

class Ball
{
private:
	sf::Vector2f position;
	float xVel/* = 2.5*/, yVel/* = 2.5*/;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f romzmiar_okna;
	sf::FloatRect ballbound;
	sf::Text scoretext;
	sf::Font font;
	int score;
	void scoreinit();
	std::vector <Heart*> heartTab;
	/*int poziom;*/
public:
	Ball(float x_in, float y_in,sf::RenderWindow& window, Lifeheart* lh);
	void przesun(float x_in, float y_in);
	sf::Sprite getBall();
	void sprawdzKolizjeSciany();
	void animuj(Paddle* pad, BlockTab* block, Heart* hrt, sf::RenderWindow& win);
	int sprawdzKolizjeObiektu(sf::Sprite &sprite);
	/*bool isCollidingWithBlock(Block* block);*/
	/*int scorecount(Block* block);*/
	//void scoreprint();
	void drawt(sf::RenderWindow& window);
	void scoreincr(sf::Sprite &sprite);
	void setScore();
	void velInit();
	void utratahp(Heart *hrt, sf::RenderWindow &win);
	void hpinit(sf::RenderWindow& window, Lifeheart* lh);
	void hpdraw(sf::RenderWindow& window);
	void hanima(Heart* hrt, sf::RenderWindow& win);
	Heart* getpheart(int n);
};

