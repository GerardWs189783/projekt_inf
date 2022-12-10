#include "block.h"
#include <random>

std::random_device rd;

Block::Block(float x_in, float y_in)
{
	pos.x = x_in;
	pos.y = y_in;
	tekstura.loadFromFile("zdj/blockani.png");
	block.setTexture(tekstura);
	block.setTextureRect(sf::IntRect(3, 3, 48, 18));
	block.setPosition(pos.x, pos.y);
	block.setScale(sf::Vector2f(75.f / block.getGlobalBounds().width, 30.f / block.getGlobalBounds().height));
	block.setOrigin(sf::Vector2f(block.getLocalBounds().width / 2.f, block.getLocalBounds().height / 2.f));
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
	block.setPosition(x, y);
	/*else*/
	/*{
		block.setPosition(distX(gen),200);
	}*/
}

sf::Sprite Block::getSprite() {
	return block;
}

//int::Block::score(sf::Sprite sprite, int wynik)
//{
//
//}
sf::FloatRect Block::getBounds() {
	return block.getGlobalBounds();
}