#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
class Block2 : public Block
{
private:
	int hp;
	//sf::Vector2f pos;
	//sf::Sprite block2;
 	void posinit();
public:
	Block2();
	void animation();
	void hpdec();
};

