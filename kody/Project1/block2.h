#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
class Block2 : public Block
{
private:
	//sf::Vector2f pos;
	//sf::Sprite block2;
public:
	void posinit();
	Block2();
	Block2(Block& block);
	void animation();
	void hpdec();
};

