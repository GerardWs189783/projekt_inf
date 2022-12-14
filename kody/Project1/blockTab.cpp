#include "blockTab.h"

BlockTab::BlockTab(sf::RenderWindow& window)
{
	init(window);
}

void BlockTab::init(sf::RenderWindow& window)
{
	sf::Vector2u winsize = window.getSize();
	this->n = 4;

	btab = new Block*[n];
	for (int i = 0; i < n; i++) {
		//btab[n] = i % 2 == 0 ? new Block : new Block2;
		btab[i] = new Block();
		btab[i]->setpos(sf::Vector2f((winsize.x) / (n + 1) * (i + 1), 400));
		btab[i]->getSpritep()->setPosition(btab[i]->getpos());
	}
}

void BlockTab::draw(sf::RenderWindow& window) {
	for (int i = 0; i < n; i++) {
		btab[i]->bdraw(window);
	}
}

int BlockTab::getsize() {
	return this->n;
}

Block** BlockTab::getarrpointer() {
	return btab;
}