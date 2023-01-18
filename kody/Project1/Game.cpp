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
	n = nullptr;
	x = 1;

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
		if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) && menu->getMenuIndex() == 1) {
			gamestate = 4;
			break;
		}
		if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) && menu->getMenuIndex() == 0 && play ==nullptr) {
			//delete menu i nullptr
			std::cout << "Koniec menu" << std::endl;
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
			if (play->getPlayIndex() == 1) {
				std::cout << "Koniec play tworzenie level2" << std::endl;
				delete play;
				play = nullptr;
				gamestate = 2;
				break;
			}
			if (play->getPlayIndex() == 2) {
				std::cout << "Koniec play tworzenie level3" << std::endl;
				delete play;
				play = nullptr;
				gamestate = 3;
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
		
		while (gamestate >0) {
			std::cout << "LEVEL 1" << std::endl;
			if(gamestate == 1)
				level = new Level(*window, 1,3);
			if (gamestate == 2)
				level = new Level(*window, 20, 2);
			if (gamestate == 3)
				level = new Level(*window, 30, 1);
			if (gamestate == 4) {
				load("Game.dat");
				delete menu;
				menu = nullptr;
				//moze powinno zwracac wskaznik na level
			}
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
					delete gameover, win;
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
					delete gameover, win;
					break;
				}
			}
			if(level !=nullptr && level->koniec() == false) {
				std::cout << "aha" << std::endl;
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

void Game::load(std::string filename) {
	std::fstream file;
	file.open(filename, std::ios::in | std::ios::binary);
	if (file.is_open()) {
		/*BlockTab* bt = new BlockTab(*window);*/
		File testfile(200.0f, 200.0f, 2, 1, 0,10/*,&bt*//*std::vector <int> testpos*/);
		file.read(reinterpret_cast<char*>(&testfile.saveData), sizeof(struct File::Data));
		File* loadfile = new File(testfile.saveData.bx, testfile.saveData.by, testfile.saveData.score, testfile.saveData.lnum, testfile.saveData.heart,testfile.saveData.bnum/*,testfile.saveData.bt*/);
		Level* lvf = new Level(*window,loadfile->saveData.bx,loadfile->saveData.by,loadfile->saveData.score,loadfile->saveData.lnum,loadfile->saveData.heart,loadfile->saveData.bnum/*,loadfile->saveData.bpos*/);
		level = lvf;
		delete loadfile;
		file.close();
	}
	
}