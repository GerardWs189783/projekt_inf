#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow();
	gameinit();
	menu = new Menu(*window);
	play = nullptr;
}

void Game::pollEvent()
{
	
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && play->getPlayIndex() == Optnumb - 1) {
	//	menu = new Menu();
	//}

	
		//menu->menuevents(*window, event);
		///*play->playevents(*window,event);*/
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window->close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up) {
				menu->menuUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				menu->menuDown();
				break;
			}
		}
		if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) && menu->getMenuIndex() == Optnumb - 1) {
			window->close();
			break;
		}
		if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) && menu->getMenuIndex() == 0 && play ==nullptr) {
			//delete menu i nullptr
			delete menu;
			menu = nullptr;
			play = new Play(*window);
			play->runplay(*window, event);
			std::cout << "Koniec play" << std::endl;
			delete play;
			play = nullptr;
			break;
			
			//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
		}
		
	}

		
	
	/*menu->menuevents(*window, event);*/
	
}

void Game::rungame()
{
	while (window->isOpen()) {
		/*menu->runmenu(*window);*/
		menu->spritesetpos();
		pollEvent();
		//if (play != nullptr && menu == nullptr) {
		//	play->runplay(*window, event);
		//	delete play;
		//	play = nullptr;
		//}
		if (play ==nullptr && menu == nullptr) {
			std::cout << "Nowe menu" << std::endl;
			menu = new Menu(*window);
		}
		render();
	}
	/*menu->runmenu(*window);*/
}

void Game::gameinit()
{
	window->create(sf::VideoMode(800, 600), "Arkanoid");
	window->setFramerateLimit(60);
}

void Game::render() {
	menu->drawall(*window);
	/*play->drawall(*window);*/
}
