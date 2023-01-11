#include "Level.h"

Level::Level(sf::RenderWindow &window)
{
	initLevel(window);
	helpinit(window);
}

Level::~Level()
{
	delete lh;
	delete paddle;
	delete ball;
	delete fps;
	delete blockt;
	delete helptetx;
	delete pauses;
	delete pausetex;
	delete gm;
	delete gameover;
	std::cout << "Usunieto Level 1" << std::endl;
}

void Level::runLevel(sf::RenderWindow& window, sf::Event &event)
{
	while (window.isOpen() /*&& ball->getover() != 1*/  /*&& ball->hpTabsize() > 0*/&& gover(event,window) == false && koniec() == false) {
		eventLevel(window, event);
		drawLevel(window);
		if (gm != nullptr) {
			gm->spritesetpos();
		}
		if (wait == true/* && gover(ball, &event, &wait) == false*/){
			/*gover(ball, &event, &wait);*/

			if (this->zegar.getElapsedTime().asMilliseconds() > 5.0f) {

				ball->animuj(paddle, blockt, window, &wait);

				this->zegar.restart();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && gm != nullptr && gm->getMenuIndex() == Menunumb - 1) {
			delete gm;
			gm = nullptr;
			break;
		}
	}
}

void Level::initLevel(sf::RenderWindow& window)
{
	wait = false;
	help = false;
	run = false;
	lh = new Lifeheart(window);
	paddle = new Paddle(window);
	ball = new Ball(window, this->lh);
	fps = new FPS();	
	blockt = new BlockTab(window);
	helptetx = nullptr;
	gm = nullptr;
	menu = false;
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
	if (help == true) {
		window.draw(*helptetx);
		window.draw(*pauses);
	}
	if (menu == true) {
		gm->drawall(window);
		window.draw(*pauses);
	}
	window.display();
		
}

void Level::eventLevel(sf::RenderWindow& window, sf::Event &event)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed /*|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)*/) {

			window.close();
			break;
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && menu == false && gm==nullptr) {
			gm = new GameMenu(window);
			wait = false;
			menu = !menu;
			std::cout << "Menu otwarte" << std::endl;
			break;
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && menu == true && gm!=nullptr ) {
			delete gm;
			gm = nullptr;
			wait = true;
			menu = !menu;
			std::cout << "Menu zamkniete" << std::endl;
			break;
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && gm != nullptr && gm->getMenuIndex() == 0) {
			delete gm;
			gm = nullptr;
			wait = true;
			menu = !menu;
			std::cout << "Menu zamkniete" << std::endl;
			break;
		}


		if (event.type == sf::Event::KeyReleased && gm!=nullptr) {
			if (event.key.code == sf::Keyboard::Up) {
				gm->menuUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down && gm!=nullptr) {
				gm->menuDown();
				break;
			}
		}


		if (event.type == sf::Event::MouseMoved && wait == true) {
			paddle->move(sf::Vector2f(sf::Mouse::getPosition(window).x, 540));
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && run == false /*tu jeszcze ze gdy gover to nie mozna uzyc tylko enter by wrocic*/) {
			wait = !wait;
			run = true;
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1 && wait == true && run !=false) {
			wait = false;
			help = true;
			break;
			/*if (helptetx != nullptr) {
				wait = true;
				helpdelete();
			}*/
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1 && wait == false) {
			wait = !wait;
			help = !help;
			break;
			/*if (helptetx != nullptr) {
				wait = true;
				helpdelete();
			}*/
		}

	}
}

bool Level::koniec()
{
	if (blockt->bTabsize() == 0) {
		std::cout << "WYGRALES!\nKONIEC POZIOMU" << std::endl;
		wait = false;
		return true;
	}
	return false;
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

void Level::helpinit(sf::RenderWindow &window)
{
	font = new sf::Font;
	if (!font->loadFromFile("zdj/arial.ttf"))
		return;
	helptetx = new sf::Text;
	helptetx->setFont(*font);
	helptetx->setCharacterSize(20);
	helptetx->setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - 250, window.getSize().y / 3 - 150));
	helptetx->setFillColor(sf::Color(255, 255, 255));
	helptetx->setString("Gra polega na zbijaniu blokow u gory ekranu.\nKazdy kolor bloku ma inne wlasciowsci.\nUwazaj, aby pilka nie spadla ponizej paletki.\nPaletka sterowana jest za pomoca myszki.\n");

	pauses = new sf::Sprite;
	pausetex = new sf::Texture;
	pausetex->loadFromFile("zdj/pause.png");
	pauses->setTexture(*pausetex);
	pauses->setTextureRect(sf::IntRect(300,200,700,700));
	pauses->setScale(sf::Vector2f(50.0f / pauses->getGlobalBounds().width, 50.0f / pauses->getGlobalBounds().height));
	pauses->setPosition(sf::Vector2f(window.getSize().x - pauses->getGlobalBounds().width, 0));
}

void Level::helpdelete()
{
	delete helptetx;
	helptetx = nullptr;
}


// poziomy trudnosci chyba do konstruktorow wejsciowe dane, czyli nowy konstruktor? mozna zmieniac predkosc, ilosc zyc i ilosc klockow
// zapis stanu gry