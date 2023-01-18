#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "paddle.h"
#include "ball.h"
#include "block.h"
#include "fps.h"
#include "block2.h"
#include "lifeheart.h"
#include "heart.h"
#include "Gameover.h"


class Level
{
private:
	Ball* ball;
	Paddle* paddle;
	BlockTab* blockt;
	FPS* fps;
	Lifeheart* lh;
	sf::Clock zegar;
	bool wait;
	Gameover* gameover;
	sf::Text* helptetx;
	sf::Font* font;
	bool help;
	bool run;
	bool menu;
	sf::Sprite* pauses;
	sf::Texture* pausetex;
	GameMenu* gm;
	//symbol pauzy czy w rysowaniu moze byc petla ktora co sekunde zmienia czy rysuje czy nie?

	/*sf::Sprite backgover;*/

public:
	/*Level(sf::RenderWindow &window,int* n);*/
	Level(sf::RenderWindow& window, int n,int l);
	Level(sf::RenderWindow& window, float bx, float by, int score, int lnum, int heart,int bn);
	~Level();
	void runLevel(sf::RenderWindow &window, sf::Event &event);
	/*void initLevel(sf::RenderWindow& window,int* n);*/
	void initLevel(sf::RenderWindow& window, int n, int l);
	void initLevel(sf::RenderWindow& window, float bx, float by, int score, int lnum, int heart,int bn);
	void drawLevel(sf::RenderWindow& window);
	void eventLevel(sf::RenderWindow& window, sf::Event &event);
	bool koniec();
	bool gover(/*Ball* b,*/ sf::Event& ev,sf::RenderWindow &window /*bool* wait*/);
	void eventgover(sf::Event &event, sf::RenderWindow & window);
	void rungover(sf::Event& event, sf::RenderWindow& window);
	void helpinit(sf::RenderWindow& window);
	void helpdelete();
	Level(sf::RenderWindow& window, float bx, float by, int score, int lnum, int heart, int bn, std::vector <int> bp);
	void initLevel(sf::RenderWindow& window, float bx, float by, int score, int lnum, int heart, int bn, std::vector <int> bp);
	// jeszcze moze jakies funkcje zwracaj¹ce score, pozycje pilki i paddla, ilosc zbitych bloków
};

class File {
public:
	File(float bx, float by, int score, int lnum, int heart, int bnum/* ,BlockTab bt*/) {
		saveData.bx = bx;
		saveData.by = by;
		saveData.score = score;
		saveData.lnum = lnum;
		saveData.heart = heart;
		saveData.bnum = bnum;
		/*saveData.bt = bt;
		for (int i = 0; i < bt.bpos.size(); i++) {
		saveData.bpos.push_back(bt.bpos[i]);
		}*/
		 
	}

	struct Data{
		float bx;
		float by;
		int score;
		int lnum;
		int heart;
		int bnum;
		//std::vector <int> bpos;
		//BlockTab bt;
	}saveData;

	void save(std::string filename);
	void load(std::string filename);

};