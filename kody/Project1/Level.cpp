#include "Level.h"

Level::Level(sf::RenderWindow &window)
{
	initLevel(window);
}

Level::~Level()
{
	delete lh;
	delete paddle;
	delete ball;
	delete fps;
	delete blockt;
}

void Level::runLevel(sf::RenderWindow& window, sf::Event &event)
{
	while (window.isOpen()) {
		eventLevel(window, event);
		drawLevel(window);
		if (wait == true && gover(ball, &event, &wait) == false){
			gover(ball, &event, &wait);

			if (this->zegar.getElapsedTime().asMilliseconds() > 5.0f) {

				ball->animuj(paddle, blockt, window, &wait);

				this->zegar.restart();
			}

		}
	}
}

void Level::initLevel(sf::RenderWindow& window)
{
	wait = false;
	lh = new Lifeheart(window);
	paddle = new Paddle(window);
	ball = new Ball(window, this->lh);
	fps = new FPS();	
	blockt = new BlockTab(window);
	
}

void Level::drawLevel(sf::RenderWindow& window)
{
	window.clear(sf::Color::Blue);
	lh->draw(window);
	paddle->pdraw(window);
	ball->drawt(window);
	ball->hpdraw(window);
	fps->drawFPS(window);
	blockt->draw(window);
	window.display();
}

void Level::eventLevel(sf::RenderWindow& window, sf::Event &event)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window.close();

		if (event.type == sf::Event::MouseMoved && wait == true) {
			paddle->move(sf::Vector2f(sf::Mouse::getPosition(window).x, 540));
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			wait = !wait;


	}
}

void Level::koniec(BlockTab* block)
{
}

bool Level::gover(Ball* b, sf::Event* ev, bool* wait)
{
	if (b->hpTabsize() == 0 && *wait == true) {
		std::cout << "GAMEOVER" << std::endl;
		*wait = false;
		return true;
	}
	return false;
}
