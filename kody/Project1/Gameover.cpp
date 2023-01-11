#include "Gameover.h"

//Gameover::Gameover(sf::RenderWindow &window):Menu(window)
//{
//	menuinit(window);
//}
//
//void Gameover::backinit(sf::RenderWindow& window)
//{
//	tback.loadFromFile("zdj/gameover.jpg");
//	background.setTexture(tback);
//	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
//	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
//	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
//}
//
//void Gameover::optinit(sf::RenderWindow& window)
//{
//	if (!font.loadFromFile("zdj/arial.ttf"))
//		return;
//
//	menu[0].setFont(font);
//	menu[0].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 1));
//	menu[0].setCharacterSize(40);
//	menu[0].setFillColor(sf::Color::Blue);
//	menu[0].setString("PLAY AGAIN");
//
//	menu[1].setFont(font);
//	menu[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 2));
//	menu[1].setCharacterSize(40);
//	menu[1].setFillColor(sf::Color::White);
//	menu[1].setString("EXIT");
//
//	//menu[2].setFont(font);
//	//menu[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 3));
//	//menu[2].setCharacterSize(40);
//	//menu[2].setFillColor(sf::Color::White);
//	//menu[2].setString("EXTRAS");
//
//	//menu[3].setFont(font);
//	//menu[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
//	//menu[3].setCharacterSize(40);
//	//menu[3].setFillColor(sf::Color::White);
//	//menu[3].setString("EXIT");
//}
//
//void Gameover::menuinit(sf::RenderWindow& window)
//{
//	backinit(window);
//	optinit(window);
//	spriteinit();
//}
//
//void Gameover::menuevents(sf::RenderWindow& window, sf::Event& event/* Play* pl*/)
//{
//	/*sf::Event event;*/
//
//	while (window.pollEvent(event)) {
//		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
//			window.close();
//		}
//		if (event.type == sf::Event::KeyReleased) {
//			if (event.key.code == sf::Keyboard::Up) {
//				menuUp();
//				break;
//			}
//			if (event.key.code == sf::Keyboard::Down) {
//				menuDown();
//				break;
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == Optnumb - 1) {
//			window.close();
//			break;
//		}
//		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == 0) {
//		//	Play* pl = new Play(window);
//		//	pl->runplay(window, event);
//		//	delete pl;
//		//	pl = nullptr;
//		//	break;
//		//	//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
//		//}
//
//	}
//
//}

//void Gamover::runmenu(sf::RenderWindow& window)
//{
//	while (window.isOpen()) {
//		menuevents(window);
//		drawall(window);
//		spritesetpos();
//	}
//}


Gameover::Gameover(sf::RenderWindow& window)
{
	/*window = new sf::RenderWindow();*/
	this->menuindex = 0;
	menuinit(window);
	draw = true;
}



//Gameover::Gameover() {
//
//}

void Gameover::menuUp()
{


	menu[menuindex].setFillColor(sf::Color::White);

	if (menuindex == 0) {
		menuindex = Extnumb - 1;
	}
	else {
		menuindex--;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

void Gameover::menuDown()
{
	menu[menuindex].setFillColor(sf::Color::White);
	if (menuindex == Extnumb - 1) {
		menuindex = 0;

	}
	else {
		menuindex++;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

int Gameover::getMenuIndex()
{
	return menuindex;
}

void Gameover::drawmenu(sf::RenderWindow& window)
{
	for (int i = 0; i < Extnumb; i++) {
		window.draw(menu[i]);
	}
}

void Gameover::optinit(sf::RenderWindow& window)
{
	if (!font.loadFromFile("zdj/arial.ttf"))
		return;

	menu[0].setFont(font);
	menu[0].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Extnumb + 1) * 1 - 100));
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("PLAY AGAIN");

	menu[1].setFont(font);
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Extnumb + 1) * 2 + 50));
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("BACK TO MENU");

	//menu[2].setFont(font);
	//menu[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 3));
	//menu[2].setCharacterSize(40);
	//menu[2].setFillColor(sf::Color::White);
	//menu[2].setString("EXTRAS");

	//menu[3].setFont(font);
	//menu[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
	//menu[3].setCharacterSize(40);
	//menu[3].setFillColor(sf::Color::White);
	//menu[3].setString("EXIT");
}

void Gameover::spriteinit()
{
	tsprt.loadFromFile("zdj/trock.png");
	menusprite.setTexture(tsprt);
	menusprite.setScale(sf::Vector2f(100.f / menusprite.getLocalBounds().width, 80.f / menusprite.getLocalBounds().height));
	menusprite.setOrigin(sf::Vector2f(menusprite.getLocalBounds().width / 2.f, menusprite.getLocalBounds().height / 2.f));
	position.x = menu[0].getPosition().x - menu[0].getGlobalBounds().width / 2;
	position.y = menu[0].getPosition().y + menu[0].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void Gameover::drawsprt(sf::RenderWindow& window)
{
	window.draw(menusprite);
}

void Gameover::spritesetpos()
{
	int i = getMenuIndex();
	position.x = menu[i].getPosition().x - menu[i].getGlobalBounds().width / 2;
	position.y = menu[i].getPosition().y + menu[i].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void Gameover::backinit(sf::RenderWindow& window)
{
	tback.loadFromFile("zdj/gameover.png");
	background.setTexture(tback);
	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Gameover::backdraw(sf::RenderWindow& window)
{
	window.draw(background);
}

void Gameover::menuinit(sf::RenderWindow& window)
{
	//window->create(sf::VideoMode(800, 600), "Arkanoid");
	//window->setFramerateLimit(60);
	backinit(window);
	optinit(window);
	spriteinit();
}

void Gameover::drawall(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	backdraw(window);
	drawmenu(window);
	drawsprt(window);
	window.display();
}

void Gameover::runmenu(sf::RenderWindow& window, sf::Event& event)
{
	while (window.isOpen() && draw == true) {
		menuevents(window, event);
		drawall(window);
		spritesetpos();
	}
}

void Gameover::menuevents(sf::RenderWindow& window, sf::Event& event/* Play* pl*/)
{
	/*sf::Event event;*/

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up) {
				menuUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				menuDown();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == Extnumb - 1) {
			draw = !draw;
			/*window.close();*/
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == 0) {
			draw = !draw;
			/*window.close();*/
			break;
			//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
		}

	}

}

//sf::RenderWindow* getMenuWin() {
//	return window;
//}



//Win::Win(sf::RenderWindow& window) /*: Gameover(window)*/
//{
//
//}
//
//Win::Win(){}
//
//void Win::drawmenu(sf::RenderWindow& window)
//{
//}
//
//void Win::backinit(sf::RenderWindow& window)
//{
//}
//
//void Win::backdraw(sf::RenderWindow& window)
//{
//}
//
//void Win::optinit(sf::RenderWindow& window)
//{
//}
//
//void Win::menuinit(sf::RenderWindow& window)
//{
//}
//
//void Win::drawall(sf::RenderWindow& window)
//{
//}
//
//void Win::runmenu(sf::RenderWindow& window, sf::Event& event)
//{
//}
//
//void Win::menuevents(sf::RenderWindow& window, sf::Event& event)
//{
//}

Win::Win(sf::RenderWindow& window)
{
	/*window = new sf::RenderWindow();*/
	this->menuindex = 0;
	menuinit(window);
	draw = true;
}

Win::~Win()
{
	delete title;
}

void Win::menuUp()
{


	menu[menuindex].setFillColor(sf::Color::White);

	if (menuindex == 0) {
		menuindex = Extnumb - 1;
	}
	else {
		menuindex--;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

void Win::menuDown()
{
	menu[menuindex].setFillColor(sf::Color::White);
	if (menuindex == Extnumb - 1) {
		menuindex = 0;

	}
	else {
		menuindex++;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

int Win::getMenuIndex()
{
	return menuindex;
}

void Win::drawmenu(sf::RenderWindow& window)
{
	for (int i = 0; i < Extnumb; i++) {
		window.draw(menu[i]);
	}
}

void Win::optinit(sf::RenderWindow& window)
{
	if (!font.loadFromFile("zdj/arial.ttf"))
		return;

	title = new sf::Text;
	title->setFont(font);
	title->setCharacterSize(60);
	title->setPosition(sf::Vector2f(window.getSize().x / 2 - 120, window.getSize().y / 3 - 150));
	title->setFillColor(sf::Color(250, 114, 0));
	title->setOutlineColor(sf::Color(255, 255, 255));
	title->setOutlineThickness(2.0f);
	title->setString("VICTORY");

	menu[0].setFont(font);
	menu[0].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Extnumb + 1) * 1 + 50));
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("PLAY AGAIN");

	menu[1].setFont(font);
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Extnumb + 1) * 2 - 50));
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("BACK TO MENU");

	//menu[2].setFont(font);
	//menu[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 3));
	//menu[2].setCharacterSize(40);
	//menu[2].setFillColor(sf::Color::White);
	//menu[2].setString("EXTRAS");

	//menu[3].setFont(font);
	//menu[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
	//menu[3].setCharacterSize(40);
	//menu[3].setFillColor(sf::Color::White);
	//menu[3].setString("EXIT");
}

void Win::spriteinit()
{
	tsprt.loadFromFile("zdj/trock.png");
	menusprite.setTexture(tsprt);
	menusprite.setScale(sf::Vector2f(100.f / menusprite.getLocalBounds().width, 80.f / menusprite.getLocalBounds().height));
	menusprite.setOrigin(sf::Vector2f(menusprite.getLocalBounds().width / 2.f, menusprite.getLocalBounds().height / 2.f));
	position.x = menu[0].getPosition().x - menu[0].getGlobalBounds().width / 2;
	position.y = menu[0].getPosition().y + menu[0].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void Win::drawsprt(sf::RenderWindow& window)
{
	window.draw(menusprite);
}

void Win::spritesetpos()
{
	int i = getMenuIndex();
	position.x = menu[i].getPosition().x - menu[i].getGlobalBounds().width / 2;
	position.y = menu[i].getPosition().y + menu[i].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void Win::backinit(sf::RenderWindow& window)
{
	tback.loadFromFile("zdj/main.jpg");
	background.setTexture(tback);
	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Win::backdraw(sf::RenderWindow& window)
{
	window.draw(background);
}

void Win::menuinit(sf::RenderWindow& window)
{
	//window->create(sf::VideoMode(800, 600), "Arkanoid");
	//window->setFramerateLimit(60);
	backinit(window);
	optinit(window);
	spriteinit();
}

void Win::drawall(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	backdraw(window);
	drawmenu(window);
	window.draw(*title);
	drawsprt(window);
	window.display();
}

void Win::runmenu(sf::RenderWindow& window, sf::Event& event)
{
	while (window.isOpen() && draw == true) {
		menuevents(window, event);
		drawall(window);
		spritesetpos();
	}
}

void Win::menuevents(sf::RenderWindow& window, sf::Event& event/* Play* pl*/)
{
	/*sf::Event event;*/

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up) {
				menuUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				menuDown();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == Extnumb - 1) {
			draw = !draw;
			/*window.close();*/
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == 0) {
			draw = !draw;
			/*window.close();*/
			break;
			//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
		}

	}

}


GameMenu::GameMenu(sf::RenderWindow& window)
{
	/*window = new sf::RenderWindow();*/
	this->menuindex = 0;
	menuinit(window);

}

void GameMenu::menuUp()
{


	menu[menuindex].setFillColor(sf::Color::White);

	if (menuindex == 0) {
		menuindex = Menunumb - 1;
	}
	else {
		menuindex--;
	}
	menu[menuindex].setFillColor(sf::Color::Red);
}

void GameMenu::menuDown()
{
	menu[menuindex].setFillColor(sf::Color::White);
	if (menuindex == Menunumb - 1) {
		menuindex = 0;

	}
	else {
		menuindex++;
	}
	menu[menuindex].setFillColor(sf::Color::Red);
}

int GameMenu::getMenuIndex()
{
	return menuindex;
}

void GameMenu::drawmenu(sf::RenderWindow& window)
{
	for (int i = 0; i < Menunumb; i++) {
		window.draw(menu[i]);
	}
}

void GameMenu::optinit(sf::RenderWindow& window)
{
	if (!font.loadFromFile("zdj/arial.ttf"))
		return;

	menu[0].setFont(font);
	menu[0].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Menunumb + 1) * 1));
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("CONTINUE");

	menu[1].setFont(font);
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Menunumb + 1) * 2));
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SAVE GAME");

	menu[2].setFont(font);
	menu[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Menunumb + 1) * 3));
	menu[2].setCharacterSize(40);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("QUIT GAME");

	//menu[3].setFont(font);
	//menu[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
	//menu[3].setCharacterSize(40);
	//menu[3].setFillColor(sf::Color::White);
	//menu[3].setString("EXIT");
}

void GameMenu::spriteinit()
{
	tsprt.loadFromFile("zdj/trock.png");
	menusprite.setTexture(tsprt);
	menusprite.setScale(sf::Vector2f(100.f / menusprite.getLocalBounds().width, 80.f / menusprite.getLocalBounds().height));
	menusprite.setOrigin(sf::Vector2f(menusprite.getLocalBounds().width / 2.f, menusprite.getLocalBounds().height / 2.f));
	position.x = menu[0].getPosition().x - menu[0].getGlobalBounds().width / 2;
	position.y = menu[0].getPosition().y + menu[0].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void GameMenu::drawsprt(sf::RenderWindow& window)
{
	window.draw(menusprite);
}

void GameMenu::spritesetpos()
{
	int i = getMenuIndex();
	position.x = menu[i].getPosition().x - menu[i].getGlobalBounds().width / 2;
	position.y = menu[i].getPosition().y + menu[i].getGlobalBounds().height;
	menusprite.setPosition(position);
}

//void Menu::backinit(sf::RenderWindow& window)
//{
//	tback.loadFromFile("zdj/main.jpg");
//	background.setTexture(tback);
//	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
//	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
//	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
//}

//void Menu::backdraw(sf::RenderWindow& window)
//{
//	window.draw(background);
//}

void GameMenu::menuinit(sf::RenderWindow& window)
{
	//window->create(sf::VideoMode(800, 600), "Arkanoid");
	//window->setFramerateLimit(60);
	/*backinit(window);*/
	optinit(window);
	spriteinit();
}

void GameMenu::drawall(sf::RenderWindow& window)
{
	/*window.clear(sf::Color::Black);*/
	/*backdraw(window);*/
	drawmenu(window);
	drawsprt(window);
	/*window.display();*/
}

void GameMenu::runmenu(sf::RenderWindow& window, sf::Event& event)
{
	while (window.isOpen()) {
		menuevents(window, event);
		drawall(window);
		spritesetpos();
	}
}

void GameMenu::menuevents(sf::RenderWindow& window, sf::Event& event/* Play* pl*/)
{
	///*sf::Event event;*/

	//while (window.pollEvent(event)) {
	//	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
	//		window.close();
	//	}
	//	if (event.type == sf::Event::KeyReleased) {
	//		if (event.key.code == sf::Keyboard::Up) {
	//			menuUp();
	//			break;
	//		}
	//		if (event.key.code == sf::Keyboard::Down) {
	//			menuDown();
	//			break;
	//		}
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == Menunumb - 1) {
	//		window.close();
	//		break;
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == 0) {
	//		Play* pl = new Play(window);
	//		pl->runplay(window, event);
	//		delete pl;
	//		pl = nullptr;
	//		break;
	//		//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
	//	}

	//}

}