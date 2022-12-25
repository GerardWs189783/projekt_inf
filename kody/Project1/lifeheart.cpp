#include "lifeheart.h"

//ilosc hp, animacja serduszka, gdy pilka dotknie podlogi, gameover?

Lifeheart::Lifeheart(sf::RenderWindow& window) {
	lifeinit(window);
}

void Lifeheart::lifeinit(sf::RenderWindow& window) {
	sf::Vector2u winsize = window.getSize();
	textpos = sf::Vector2f((0.65) * (winsize.x), (0.95) * winsize.y);
	if (!this->font.loadFromFile("zdj/arial.ttf"))
	{
		return;
	}
	this->hptext.setFont(this->font);
	this->hptext.setPosition(textpos.x,textpos.y);
	this->hptext.setCharacterSize(28);
	this->hptext.setFillColor(sf::Color::Black);
	this->hptext.setString("Lives: ");
}



void Lifeheart::draw(sf::RenderWindow &window) {
	window.draw(this->hptext);
}

sf::Vector2f Lifeheart::getpos() {
	return this->textpos;
}