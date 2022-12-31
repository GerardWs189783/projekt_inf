#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"
#include "block.h"
#include "fps.h"
#include "block2.h"
#include "lifeheart.h"
#include "heart.h"


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

public:
	Level(sf::RenderWindow &window);
	~Level();
	void runLevel(sf::RenderWindow &window, sf::Event &event);
	void initLevel(sf::RenderWindow& window);
	void drawLevel(sf::RenderWindow& window);
	void eventLevel(sf::RenderWindow& window, sf::Event &event);
	void koniec(BlockTab* block);
	bool gover(Ball* b, sf::Event* ev, bool* wait);
	// jeszcze moze jakies funkcje zwracaj¹ce score, pozycje pilki i paddla, ilosc zbitych bloków
};

