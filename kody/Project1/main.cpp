#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Game.h"
#include "paddle.h"

std::random_device rd;

class Ball
{
private:
	sf::Vector2f position;
	float xVel = 2.5, yVel = 2.5;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f romzmiar_okna;
public:
	Ball(float x_in, float y_in, float rx_in, float ry_in)
	{
		position.x = x_in;
		position.y = y_in;
		romzmiar_okna.x = rx_in - 70;
		romzmiar_okna.y = ry_in - 70;
		tekstura.loadFromFile("zdj/shrokjj.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
		pSprite.setScale(sf::Vector2f(70.f / pSprite.getLocalBounds().width, 70.f / pSprite.getLocalBounds().height));
	}
	void przesun(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();
		
	}
	sf::Sprite getBall() { return pSprite; }
	void sprawdzKolizjeSciany()
	{
		if (position.x <= 0)
			xVel = abs(xVel);
		if (position.x >= romzmiar_okna.x)
			xVel = -abs(xVel);
		if (position.y <= 0)
			yVel = abs(yVel);
		if (position.y >= romzmiar_okna.y)
			yVel = -abs(yVel);
	}
	void animuj(sf::Sprite sprite)
	{
		sprawdzKolizjeSciany();
		sprawdzKolizjeObiektu(sprite);
		przesun(xVel, yVel);
	}
	void sprawdzKolizjeObiektu(sf::Sprite sprite)
	{
		if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
			yVel *= -1;
		}
	}
};

class Block {
private:
	sf::Vector2f pos;
	sf::RectangleShape block;
public:
	Block(float x_in,float y_in);
	void bdraw(sf::RenderWindow& window);
	void move();
};

Block::Block(float x_in, float y_in)
{
	pos.x = x_in;
	pos.y = y_in;
	block.setPosition(pos.x, pos.y);
	block.setFillColor(sf::Color(0,0,0));
	block.setSize(sf::Vector2f(100.f, 100.f));
	block.setScale(sf::Vector2f(80.f / block.getLocalBounds().width, 40.f / block.getLocalBounds().height));
}

void Block::bdraw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Block::move()
{
	float x = 0, y = 0;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(-300,300);
	std::uniform_int_distribution<> distY(0,200);
	x = distX(gen);
	y = distY(gen);
	//Warunek, ¿e je¿eli wspólrzêdne poza ekranem to jeszcze raz losuje 
	if(!((x< block.getGlobalBounds().width / 2.f) || (x > 800 - block.getGlobalBounds().width / 2.f) || (y<block.getGlobalBounds().height/2.f) ||(y>250)))
	block.move(x, 0);
	else
	{
		block.setPosition(distX(gen),200);
	}
}

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


		window.clear(sf::Color::Green);
		p1.pdraw(window);
		window.draw(pb.getBall());
		b1.bdraw(window);
		window.display();
		if (wait == true)
		{
			if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
				pb.animuj(p1.getSprite());
				zegar.restart();
			}
			if (z.getElapsedTime().asMilliseconds() > 1000.f)
			{
				b1.move();
				z.restart();
			}
		}
	}
	return 0;
}