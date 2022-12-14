#include "block2.h"
#include <random>
#include <iostream>

Block2::Block2()
{
	Block();
	posinit();
	block.setPosition(sf::Vector2f(this->pos.x, this->pos.y));
	block.setTextureRect(sf::IntRect(54, 3, 48, 18));
}

void Block2::posinit()
{
	this->pos.x = 400;
	this->pos.y = 400;
}