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
	sf::FloatRect ballbound;
public:
	Ball(float x_in, float y_in, float rx_in, float ry_in)
	{
		position.x = x_in;
		position.y = y_in;
		//romzmiar_okna.x = rx_in - 70;
		//romzmiar_okna.y = ry_in - 70;
		tekstura.loadFromFile("zdj/shrokjj.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
		pSprite.setScale(sf::Vector2f(70.f / pSprite.getLocalBounds().width, 70.f / pSprite.getLocalBounds().height));
		/*pSprite.setOrigin(pSprite.getGlobalBounds().width/2.f, pSprite.getGlobalBounds().height/2.f);*/
		romzmiar_okna.x = rx_in - pSprite.getGlobalBounds().width /*-70*/;
		romzmiar_okna.y = ry_in - pSprite.getGlobalBounds().height /*- 70*/;
		ballbound = pSprite.getGlobalBounds();
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
		sf::FloatRect overlap = sprite.getGlobalBounds();
		if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
			
			//right
			//if (ballbound.left < overlap.left && ballbound.left + ballbound.width < overlap.left + overlap.width
			//	&& ballbound.top < overlap.top + overlap.height
			//	&& ballbound.top + ballbound.height < overlap.top)
			//{
			//	pSprite.setPosition(overlap.left - ballbound.width, ballbound.top);
			//	yVel *= -1;
			//}
			////left
			//else if (ballbound.left > overlap.left && ballbound.left + ballbound.width > overlap.left + overlap.width
			//	&& ballbound.top < overlap.top + overlap.height
			//	&& ballbound.top + ballbound.height < overlap.top)
			//{
			//	pSprite.setPosition(overlap.left + ballbound.width, ballbound.top);
			//	yVel *= -1;
			//}
			////bottom
			//if (ballbound.top < overlap.top && ballbound.top + ballbound.height < overlap.top + overlap.height
			//	&& ballbound.left < overlap.left + overlap.width
			//	&& ballbound.left + ballbound.width < overlap.left)
			//{
			//	pSprite.setPosition(ballbound.left, overlap.top - ballbound.height);
			//	yVel *= -1;
			//}
			////top
			//else if (ballbound.top > overlap.top && ballbound.top + ballbound.height > overlap.top + overlap.height
			//	&& ballbound.left < overlap.left + overlap.width
			//	&& ballbound.left + ballbound.width < overlap.left)
			//{
			//	pSprite.setPosition(ballbound.left, overlap.top - overlap.height);
			//	yVel *= -1;
			//}
			//Lewa czêœæ pi³ki
			/*if (sprite.getPosition().x + sprite.getGlobalBounds().width - pSprite.getPosition().x - pSprite.getGlobalBounds().width < 0)
			{
				xVel *= -1;
				pSprite.move(sf::Vector2f((-1) * (sprite.getPosition().x + sprite.getGlobalBounds().width - pSprite.getPosition().x - pSprite.getGlobalBounds().width), 0.f));
			}*/
			//Najlepiej dzia³a na lew¹ stronê resztynie dotyka ale jest to chyba robocze
			if (pSprite.getPosition().x < sprite.getPosition().x + (0.5)*sprite.getGlobalBounds().width &&
				pSprite.getPosition().x+pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width &&
				abs(sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x) < abs(sprite.getPosition().y + (0.5) * sprite.getGlobalBounds().height - pSprite.getPosition().y) /*&&
				pSprite.getPosition().y+pSprite.getGlobalBounds().height > sprite.getPosition().y - (0.5)*sprite.getGlobalBounds().height*/
				&& sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x <(pSprite.getGlobalBounds().width)/2
				&& pSprite.getPosition().x + pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width)
			{
				xVel *= -1;
				pSprite.move(sf::Vector2f(sprite.getPosition().x+ (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x, 0.f));
			}
			//prawa strona pi³ki
			else if (pSprite.getPosition().x + pSprite.getGlobalBounds().width > sprite.getPosition().x - (sprite.getGlobalBounds().width)/2.f &&
				pSprite.getPosition().x < sprite.getPosition().x - (0.5)*sprite.getGlobalBounds().width &&
				pSprite.getPosition().x < sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width)
			{
				xVel *= -1;
				pSprite.move(sf::Vector2f(pSprite.getPosition().x + pSprite.getGlobalBounds().width - sprite.getPosition().x +(sprite.getGlobalBounds().width) / 4.f , 0.f));
			}
			//Góra i dó³
			/*else if ()*/
			yVel *= -1;
		}
		/*if(position.x<sprite.getPosition().x + sprite.getGlobalBounds().width && position.x+pSprite.getGlobalBounds().width > sprite.getPosition().x
			&& position.y<sprite.getPosition().y + sprite.getGlobalBounds().height && position.y + pSprite.getGlobalBounds().height > sprite.getPosition().y)
			yVel *= -1;*/
	}
};

class Block {
private:
	sf::Vector2f pos;
	sf::Texture tekstura;
	sf::Sprite block;

public:
	Block(float x_in,float y_in);
	void bdraw(sf::RenderWindow& window);
	void move();
	sf::Sprite getSprite();
};

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
	std::uniform_int_distribution<> distX(0,700);
	std::uniform_int_distribution<> distY(0,200);
	x = distX(gen);
	y = distY(gen);
	/*if(!((x< block.getGlobalBounds().width / 2.f) || (x > 800 - block.getGlobalBounds().width / 2.f) || (y<block.getGlobalBounds().height/2.f) ||(y>250)))*/
	block.setPosition(x, y);
	/*else*/
	/*{
		block.setPosition(distX(gen),200);
	}*/
}
//Zrobiæ naliczanie punktów, sprite który zmienia skina przy uderzeniu?
sf::Sprite Block::getSprite() {
	return block;
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
				pb.sprawdzKolizjeObiektu(b1.getSprite());
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