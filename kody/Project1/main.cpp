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

void koniec(BlockTab* block);

bool gover(Heart* hp, sf::Event *ev, bool *wait);

int main()
{
	//Game game();
	/*while (game.running())
	{
	//Event poll w game
	//Tu tylko update i render
	game.update();
	game.render();
}*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
	Lifeheart* life = new Lifeheart(window);
	sf::Event event;
	sf::Clock zegar;
	bool wait = true;
	Paddle p1(400, 540);
	Ball* pb = new Ball(300, 300,window,life);
	//Block* b1 = new Block();
	//Block2* b2 = new Block2();
	BlockTab* bt = new BlockTab(window);
	/*Block b1(200,200);*/
	FPS* fps = new FPS();
	Heart* heart = new Heart(window, life);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::MouseMoved && wait==true) {
				p1.move(sf::Vector2f(sf::Mouse::getPosition(window).x, 540));
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
				wait = !wait;

		}
		fps->FPSrate();
		window.clear(sf::Color::Blue);
		p1.pdraw(window);
		/*window.draw(pb.getBall());*/
		pb->drawt(window);
		//b1->bdraw(window);
		//b2->bdraw(window);
		/*if(bt != NULL)*/
		bt->draw(window);
		fps->drawFPS(window);
		life->draw(window);
		heart->draw(window);
		window.display();	
		if (wait == true && gover(heart, &event, &wait) == false)
		{
			gover(heart, &event, &wait);
			if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
				pb->animuj(&p1,bt, heart, window);
				//pb.sprawdzKolizjeObiektu(b2->getSprite());
				zegar.restart();
			}
			/*if (z.getElapsedTime().asMilliseconds() > 1000.f)
			{
				b1.move();
				z.restart();
			}*/
		}
	}

	//, trzeba dodaæ pozosta³ych przeciwników i ustawiæ poziomy trudnoœci, menu wyboru, menu pauzy, zapis wyniku
	return 0;
}

void koniec(BlockTab* block) {
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