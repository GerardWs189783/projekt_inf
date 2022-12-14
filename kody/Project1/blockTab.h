#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
#include "block2.h"
class BlockTab
{
protected:
	Block** btab;
	int n;
public:
	BlockTab(sf::RenderWindow& window);
	void init(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	int getsize();
	Block** getarrpointer();
};

