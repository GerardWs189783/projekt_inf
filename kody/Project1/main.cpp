#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Game.h"
#include "paddle.h"
#include "ball.h"
#include "block.h"



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
	sf::Event event;
	sf::Clock zegar,z;
	bool wait = true;
	Paddle p1(400, 540);
	Ball pb(100, 100, 800, 600);
	Block b1(200, 200);

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

		/*pb.scoreinit();*/
		window.clear(sf::Color::Green);
		p1.pdraw(window);
		/*window.draw(pb.getBall());*/
		pb.drawt(window);
		b1.bdraw(window);
		window.display();
		if (wait == true)
		{
			if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
				pb.animuj(p1.getSprite(),b1.getSprite());
				pb.sprawdzKolizjeObiektu(b1.getSprite());
				zegar.restart();
			}
			/*if (z.getElapsedTime().asMilliseconds() > 1000.f)
			{
				b1.move();
				z.restart();
			}*/
		}
	}
	return 0;
}