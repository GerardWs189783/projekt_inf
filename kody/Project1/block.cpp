#include "block.h"
#include <random>

std::random_device rd;

Block::Block(/*float x_in, float y_in*/)
{
	//pos.x = x_in;
	//pos.y = y_in;
	hp = 3;
	this->posinit();
	tekstura.loadFromFile("zdj/blockani.png");
	block.setTexture(tekstura);
	block.setTextureRect(sf::IntRect(112, 3, 48, 18));//3,3,48,18
	block.setPosition(pos.x, pos.y);
	block.setScale(sf::Vector2f(75.f / block.getGlobalBounds().width, 30.f / block.getGlobalBounds().height));
	block.setOrigin(sf::Vector2f(block.getLocalBounds().width / 2.f, block.getLocalBounds().height / 2.f));
}
//
//Block::Block(Block& block) {
//	*this = block;
//}

void Block::posinit()
{
	this->pos.x = 200;
	this->pos.y = 200;
}

void Block::bdraw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Block::move()
{
	float x = 0, y = 0;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(0, 700);
	std::uniform_int_distribution<> distY(0, 200);
	x = distX(gen);
	y = distY(gen);
	/*if(!((x< block.getGlobalBounds().width / 2.f) || (x > 800 - block.getGlobalBounds().width / 2.f) || (y<block.getGlobalBounds().height/2.f) ||(y>250)))*/
	this->block.setPosition(x, y);
	/*else*/
	/*{
		block.setPosition(distX(gen),200);
	}*/
}

sf::Sprite Block::getSprite() {
	return block;
}
sf::Sprite* Block::getSpritep() {
	return &block;
}

//int::Block::score(sf::Sprite sprite, int wynik)
//{
//
//}
sf::FloatRect Block::getBounds() {
	return block.getGlobalBounds();
}

void Block::animacja()
{
	sf::IntRect txtrect = block.getTextureRect();
	txtrect.top += 25;//25
	block.setTextureRect(txtrect);
}

void Block::setpos(sf::Vector2f posin) {
	pos = posin;
}

sf::Vector2f Block::getpos() {
	return pos;
}

 int Block::hit()
{
	 if (hp > 0) {
		 hp--;
	 }
	 return hp;
	
}

 int Block::gethp()
 {
	 return this->hp;
 }