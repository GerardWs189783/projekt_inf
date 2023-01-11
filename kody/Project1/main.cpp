#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Game.h"
#include "paddle.h"
#include "ball.h"
#include "block.h"
#include <sstream>
#include "fps.h"
#include "block2.h"
#include "lifeheart.h"
#include "heart.h"
#include "Menu.h"
//#include "Gameover.h"

void koniec(BlockTab* block);

bool gover(Heart* hp, sf::Event *ev, bool *wait);
bool gover(Ball* b, sf::Event* ev, bool* wait);

int main()
{
	Game* game = new Game();
	game->rungame();
	delete game;
	game = nullptr;

	//sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
	//sf::Event event;
	//Win* win = new Win(window);
	//win->runmenu(window, event);
	/*Win(window);*/
	//sf::Event event;
	//Gameover* gover = new Gameover(window);
	//gover->runmenu(window,event);
	//delete gover;
	//gover = nullptr;
	//window.setFramerateLimit(60);
	//sf::Event event;
	//Level* level = new Level(window);
	//level->runLevel(window, event);
	//delete level;
	//level = nullptr;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
	//Lifeheart* life = new Lifeheart(window);
	//sf::Event event;
	//sf::Clock zegar;
	//bool wait = false;
	//Paddle p1(window);
	//Ball* pb = new Ball(/*300, 300, */window, life);
	//BlockTab* bt = new BlockTab(window);
	//FPS* fps = new FPS();
	//window.setFramerateLimit(60);

	//while (window.isOpen() )
	//{
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
	//			window.close();

	//		if (event.type == sf::Event::MouseMoved && wait == true) {
	//			p1.move(sf::Vector2f(sf::Mouse::getPosition(window).x, 540));
	//		}

	//		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
	//			wait = !wait;

	//		
	//	}
	//	fps->FPSrate();
	//	window.clear(sf::Color::Blue);
	//	p1.pdraw(window);
	//	pb->drawt(window);
	//	bt->draw(window);
	//	fps->drawFPS(window);
	//	life->draw(window);
	//	pb->hpdraw(window);		
	//	window.display();
	//	
	//	
	//	if (wait == true && gover(pb, &event, &wait) == false)
	//		{
	//			gover(pb, &event, &wait);
	//			
	//			if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
	//				
	//				pb->animuj(&p1,bt, window,&wait);
	//				
	//				zegar.restart();
	//			}
	//			
	//		}
	//
	//}
		//, trzeba dodaæ pozosta³ych przeciwników i ustawiæ poziomy trudnoœci, menu wyboru, menu pauzy, zapis wyniku
		return 0;
	
}

void koniec(BlockTab *block) {
	if (block->bTabsize() == 0) {
		std::cout << "WYGRALES!\nKONIEC POZIOMU" << std::endl;
		//dzia³a chociaz w petli wyœwietla to w nieskonczonosc. Powinno wyswietlic duzy napis w okienku i chyba zatrzymac poziom?
	}
}

bool gover(Heart* hp, sf::Event *ev, bool *wait) {
	if (hp->gethp() == 0 && *wait == true)
	{
		std::cout << "GAMEOVER" << std::endl;
		*wait = false;
		return true;
	}
	return false;
}

bool gover(Ball *b, sf::Event *ev, bool *wait){
	if (b->hpTabsize() == 0 && *wait == true) {
		std::cout << "GAMEOVER" << std::endl;
		*wait = false;
		return true;
	}
	return false;
}