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
	std::cout << "Usunieto Level 1" << std::endl;
}

void Level::runLevel(sf::RenderWindow& window, sf::Event &event)
{
	while (window.isOpen() /*&& ball->getover() != 1*/  /*&& ball->hpTabsize() > 0*/&& gover(event,window) == false) {
		eventLevel(window, event);
		drawLevel(window);
		if (wait == true/* && gover(ball, &event, &wait) == false*/){
			/*gover(ball, &event, &wait);*/

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
	fps->FPSrate();
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

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P /*tu jeszcze ze gdy gover to nie mozna uzyc tylko enter by wrocic*/)
			wait = !wait;


	}
}

void Level::koniec(BlockTab* block)
{
}

bool Level::gover(/*Ball* b,*/ sf::Event& ev,sf::RenderWindow &window /*bool* wait*/)
{
	if (this->ball->hpTabsize() == 0 /*&& *wait == true*/) {
		/*wait = true;*/
		std::cout << "GAMEOVER" << std::endl;
		this->wait = false;
		/*gameover = new Gameover(window);*/

		return true;
	}
	return false;
}

void Level::eventgover(sf::Event& event, sf::RenderWindow& window)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up) {
				gameover->menuUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				gameover->menuDown();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && gameover->getMenuIndex() == Extnumb - 1) {
			/*window.close();*/
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && gameover->getMenuIndex() == 0) {
			/*window.close();*/
			break;
			//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
		}
	}
}

void Level::rungover(sf::Event& event, sf::RenderWindow& window)
{

}
