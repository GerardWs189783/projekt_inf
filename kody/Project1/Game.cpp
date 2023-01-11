#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow();
	gameinit();
	menu = new Menu(*window);
	play = nullptr;
	gameover = nullptr;
	win = nullptr;
	gamestate = 0;

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
			break;
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
			if (play->getPlayIndex() == Optnumb - 1) {
				std::cout << "Koniec play powrot do menu" << std::endl;
				delete play;
				play = nullptr;
				returnmenu();
				break;
			}
			if (play->getPlayIndex() == 0) {
				std::cout << "Koniec play tworzenie level" << std::endl;
				delete play;
				play = nullptr;
				gamestate = 1;
				break;
			}
			//std::cout << "Koniec play" << std::endl;
			//delete play;
			//play = nullptr;
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
		/*if (play ==nullptr && menu == nullptr) {
			std::cout << "Nowe menu" << std::endl;
			menu = new Menu(*window);
		}*/
		
		while (gamestate == 1) {
			std::cout << "LEVEL 1" << std::endl;
			level = new Level(*window);
			level->runLevel(*window, event);
			if (level->gover(event, *window) == true) {
				gameover = new Gameover(*window);
				gameover->runmenu(*window, event);
				if (gameover->getMenuIndex() == 0) {
					delete level;
					level = nullptr;
					std::cout << "crap" << std::endl;
				}
				if (gameover->getMenuIndex() == Extnumb - 1) {
					delete level;
					level = nullptr;
					returnmenu();
					gamestate = 0;
					break;
				}
			}
			if (level != nullptr && level->koniec() == true) {
				win = new Win(*window);
				win->runmenu(*window, event);
				if (win->getMenuIndex() == 0) {
					delete level;
					level = nullptr;
				}
				if (win->getMenuIndex() == Extnumb - 1) {
					delete level;
					level = nullptr;
					returnmenu();
					gamestate = 0;
					break;
				}
			}
			else {
				delete level;
				level = nullptr;
				delete play;
				play = nullptr;
				returnmenu();
				gamestate = 0;
				break;
			}
			//returnmenu();
			//gamestate = 0;
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


void Game::returnmenu() {
	if (play == nullptr && menu == nullptr) {
		std::cout << "Nowe menu" << std::endl;
		menu = new Menu(*window);
	}
}
void Game::returnplay() {
	if (play == nullptr && menu == nullptr) {
		std::cout << "Nowe play" << std::endl;
		play = new Play(*window);
		/*play->runplay(*window, event);
		if (play->getPlayIndex() == Optnumb - 1) {
			std::cout << "Koniec play powrot do menu" << std::endl;
			delete play;
			play = nullptr;
			returnmenu();
			break;
		}
		if (play->getPlayIndex() == 0) {
			std::cout << "Koniec play" << std::endl;
			delete play;
			play = nullptr;
			gamestate = 1;
			break;
		}*/
	}
}