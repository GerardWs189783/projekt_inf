#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
#include "block2.h"
#include <vector>

class BlockTab
{
protected:
	void** btab;
	std::vector <void*> bTab;
	int* btype;
	int n;
public:
	BlockTab(sf::RenderWindow& window);
	void init(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	int getsize();
	/*void** getarrpointer();*/
	/*void* getarrpointer();*/
	std::unique_ptr<Block> getelementpointer(int n);
	Block* getelementpointerb(int n);
	void usunelement(int m);
	int bTabsize();
	//void destab(int i);
};

