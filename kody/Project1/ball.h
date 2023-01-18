#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
#include "paddle.h"
#include "blockTab.h"
#include "heart.h"
#include <vector>
#include <random>
#include <iostream>

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
	int ilosc;
	int over;
	/*int poziom;*/
public:
	Ball(sf::RenderWindow& window, Lifeheart* lh,int ilosc);
	Ball(sf::RenderWindow& window, Lifeheart* lh, float bx, float by, int score, int lnum, int heart);
	void przesun(float x_in, float y_in);
	sf::Sprite getBall();
	void sprawdzKolizjeSciany();
	void animuj(Paddle* pad, BlockTab* block, sf::RenderWindow& win, bool* wait);
	int sprawdzKolizjeObiektu(sf::Sprite &sprite);
	/*bool isCollidingWithBlock(Block* block);*/
	/*int scorecount(Block* block);*/
	//void scoreprint();
	void drawt(sf::RenderWindow& window);
	void scoreincr(sf::Sprite &sprite);
	void setScore();
	void velInit();
	bool utratahp(Heart *hrt, sf::RenderWindow &win, bool* wait, Paddle* p);
	void hpinit(sf::RenderWindow& window, Lifeheart* lh);
	void hpdraw(sf::RenderWindow& window);
	void hanima(sf::RenderWindow& win, bool* wait, Paddle* p);
	Heart* getpheart(int n);
	int hpTabsize();
	/*bool hppause(sf::RenderWindow& win, bool *wait);*/
	void hppause(sf::RenderWindow& win, bool* wait, Paddle* p);
	void setrandpos(sf::RenderWindow& win, Paddle *p);
	bool gover(bool *wait);
	int getover();
	float getposy();
	float getposx();
	int getscore();
	/*bool getgover(bool* wait);*/
};

