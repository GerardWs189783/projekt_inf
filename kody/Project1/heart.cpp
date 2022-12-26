#include "heart.h"

Heart::Heart(sf::RenderWindow& window, Lifeheart* lh) {
	sf::Vector2u winsize = window.getSize();
	this->hearthtex.loadFromFile("zdj/heart.png");
	this->heart.setTexture(this->hearthtex);
	heart.setTextureRect(sf::IntRect(14, 200, 165, 165));//druga animacja (230,200), trzecia animacja (446,200)
	heart.setOrigin(sf::Vector2f(heart.getLocalBounds().width / 2.f, heart.getLocalBounds().height / 2.f));
	heart.setScale(sf::Vector2f(40.f / heart.getGlobalBounds().width, 40.f / heart.getGlobalBounds().height));
	this->heartpos.x = lh->getpos().x + 100;
	this->heartpos.y = winsize.y - heart.getGlobalBounds().height / 2;
	heart.setPosition(heartpos.x, heartpos.y);
	this->hp = 4;
}

int Heart::dechp() {
	sf::IntRect txtrect = heart.getTextureRect();
	txtrect.left += 216;//25
	heart.setTextureRect(txtrect);
	return this->hp--;
}


void Heart::draw(sf::RenderWindow& window) {
	if(this->hp >0)
		window.draw(this->heart);
}

sf::Vector2f Heart::gethpos() {
	return this->heartpos;
}

int Heart::gethp() {
	return this->hp;
}

sf::FloatRect Heart::getBounds() {
	return heart.getGlobalBounds();
}

void Heart::setpos(sf::Vector2f posin) {
	heartpos = posin;
}

sf::Vector2f Heart::getpos() {
	return heartpos;
}

sf::Sprite* Heart::getsprt() {
	return &heart;
}