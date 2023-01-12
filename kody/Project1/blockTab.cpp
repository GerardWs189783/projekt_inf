#include "blockTab.h"
#include <iostream>

BlockTab::BlockTab(sf::RenderWindow& window,int n)
{
	init(window,n);
}

void BlockTab::init(sf::RenderWindow& window,int n)
{
	sf::Vector2u winsize = window.getSize();
	this->n = n;
	
	/*btab = new void*[n];*/
	/*bTab = new void* [n];*/
	btype = new int[this->n];
	for (int i = 0; i < this->n; i++) {
		
		//btab[n] = i % 2 == 0 ? new Block : new Block2;
		if (i % 2 == 0) {
			/*btab[i] = new Block2();*/
			bTab.push_back(new Block2);
			btype[i] = 2;
		}
		else {
			/*btab[i] = new Block();*/
			bTab.push_back(new Block);
			/*bTab.at(i) = new Block();*/
			btype[i] = 1;
		}
		//((Block*)btab[i])->setpos(sf::Vector2f((winsize.x) / (n + 1) * (i + 1), 100));
		//((Block*)btab[i])->getSpritep()->setPosition(((Block*)btab[i])->getpos());
		sf::FloatRect bound = ((Block*)bTab[i])->getBounds();
		/*((Block*)bTab[i])->setpos(sf::Vector2f((winsize.x) / (n + 1) * (i + 1), 100));*/
		((Block*)bTab[i])->setpos(sf::Vector2f( (bound.width) / 2 + (bound.width)*(i%10) + 4.5f * ((i%10) + 1), (bound.height) / 2 + 5.0f*((i / 10) + 1) + (bound.height)*((i / 10) + 1)));
		((Block*)bTab[i])->getSpritep()->setPosition(((Block*)bTab[i])->getpos());
	}
}

BlockTab::BlockTab(sf::RenderWindow& window, int* n)
{
	init(window, n);
}

void BlockTab::init(sf::RenderWindow& window, int* n)
{
	sf::Vector2u winsize = window.getSize();
	this->n = *n;

	/*btab = new void*[n];*/
	/*bTab = new void* [n];*/
	btype = new int[this->n];
	for (int i = 0; i < this->n; i++) {

		//btab[n] = i % 2 == 0 ? new Block : new Block2;
		if (i % 2 == 0) {
			/*btab[i] = new Block2();*/
			bTab.push_back(new Block2);
			btype[i] = 2;
		}
		else {
			/*btab[i] = new Block();*/
			bTab.push_back(new Block);
			/*bTab.at(i) = new Block();*/
			btype[i] = 1;
		}
		//((Block*)btab[i])->setpos(sf::Vector2f((winsize.x) / (n + 1) * (i + 1), 100));
		//((Block*)btab[i])->getSpritep()->setPosition(((Block*)btab[i])->getpos());
		sf::FloatRect bound = ((Block*)bTab[i])->getBounds();
		/*((Block*)bTab[i])->setpos(sf::Vector2f((winsize.x) / (n + 1) * (i + 1), 100));*/
		((Block*)bTab[i])->setpos(sf::Vector2f((bound.width) / 2 + (bound.width) * (i % 10) + 4.5f * ((i % 10) + 1), (bound.height) / 2 + 5.0f * ((i / 10) + 1) + (bound.height) * ((i / 10) + 1)));
		((Block*)bTab[i])->getSpritep()->setPosition(((Block*)bTab[i])->getpos());
	}
}

//void BlockTab::draw(sf::RenderWindow& window) {
//	for (int i = 0; i < n; i++) {
//		if (((Block*)btab[i])->gethp() > 0) {
//			((Block*)btab[i])->bdraw(window);
//		}
//	}
//}
void BlockTab::draw(sf::RenderWindow& window) {
	for (int i = 0; i < bTab.size(); i++) {
		//if (((Block*)bTab[i])->gethp() > 0) {
		//	((Block*)bTab[i])->bdraw(window);
		//}
		((Block*)bTab[i])->bdraw(window);
	}
}

int BlockTab::getsize() {
	return this->n;
}

//void** BlockTab::getarrpointer() {
//	return bTab;
//}
//void* BlockTab::getarrpointer() {
//	return bTab;
//}

std::unique_ptr<Block> BlockTab::getelementpointer(int n) {
	if (btype[n] == 1) {
		return std::unique_ptr<Block>{new Block(*((Block*)btab[n]))};
	}
	if (btype[n] == 2) {
		return std::unique_ptr<Block>{new Block2(*((Block*)btab[n]))};
	}
}

//Block* BlockTab::getelementpointerb(int n) {
//	return (Block*)btab[n];
//}

Block* BlockTab::getelementpointerb(int n) {
	return (Block*)bTab[n];
}

//void BlockTab::destab(int i)
//{
//	delete getelementpointerb(i);
//}

void BlockTab::usunelement(int m) {
	
	this->bTab.erase(this->bTab.begin() + m);
	std::cout << "Usunieto: " << m << std::endl << bTab.size()<<"\n";
}

int BlockTab::bTabsize() {
	return bTab.size();
}