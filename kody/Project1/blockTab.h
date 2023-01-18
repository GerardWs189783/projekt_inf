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
	std::vector <int> btype;
	
	int n;
public:
	std::vector <int> bpos;
	BlockTab(sf::RenderWindow& window,int *n);
	void init(sf::RenderWindow& window,int *n);
	BlockTab(sf::RenderWindow& window, int n);
	void init(sf::RenderWindow& window, int n);
	BlockTab(sf::RenderWindow& window);
	void init(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	int getsize();
	/*void** getarrpointer();*/
	/*void* getarrpointer();*/
	std::unique_ptr<Block> getelementpointer(int n);
	Block* getelementpointerb(int n);
	/*int getposind();*/
	void usunelement(int m);
	int bTabsize();
	BlockTab(sf::RenderWindow& window, int n, std::vector <int> bpos);
	void init(sf::RenderWindow& window, int n, std::vector <int> bpos);
	//void destab(int i);
};

