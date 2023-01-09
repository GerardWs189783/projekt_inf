#include "Menu.h"


Menu::Menu(sf::RenderWindow& window)
{
	/*window = new sf::RenderWindow();*/
	this->menuindex = 0;
	menuinit(window);
	
}

void Menu::menuUp()
{
	

	menu[menuindex].setFillColor(sf::Color::White);
	
	if (menuindex == 0) {
		menuindex = Optnumb - 1;
	}
	else {
		menuindex--;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

void Menu::menuDown()
{
	menu[menuindex].setFillColor(sf::Color::White);
	if (menuindex == Optnumb - 1) {
		menuindex = 0;
		
	}
	else {
		menuindex++;
	}
	menu[menuindex].setFillColor(sf::Color::Blue);
}

int Menu::getMenuIndex()
{
	return menuindex;
}

void Menu::drawmenu(sf::RenderWindow& window)
{
	for (int i = 0; i < Optnumb; i++) {
		window.draw(menu[i]);
	}
}

void Menu::optinit(sf::RenderWindow& window)
{
	if (!font.loadFromFile("zdj/arial.ttf"))
		return;
	
	menu[0].setFont(font);
	menu[0].setPosition(sf::Vector2f(window.getSize().x /2 - 100,window.getSize().y / (Optnumb + 1) * 1));
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("PLAY");

	menu[1].setFont(font);
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 2));
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("OPTIONS");

	menu[2].setFont(font);
	menu[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 3));
	menu[2].setCharacterSize(40);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXTRAS");

	menu[3].setFont(font);
	menu[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
	menu[3].setCharacterSize(40);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("EXIT");
}

void Menu::spriteinit()
{	
	tsprt.loadFromFile("zdj/trock.png");
	menusprite.setTexture(tsprt);	
	menusprite.setScale(sf::Vector2f(100.f / menusprite.getLocalBounds().width, 80.f / menusprite.getLocalBounds().height));
	menusprite.setOrigin(sf::Vector2f(menusprite.getLocalBounds().width / 2.f, menusprite.getLocalBounds().height / 2.f));
	position.x = menu[0].getPosition().x - menu[0].getGlobalBounds().width / 2;
	position.y = menu[0].getPosition().y + menu[0].getGlobalBounds().height ;
	menusprite.setPosition(position);
}

void Menu::drawsprt(sf::RenderWindow& window)
{
	window.draw(menusprite);
}

void Menu::spritesetpos()
{
	int i = getMenuIndex();
	position.x = menu[i].getPosition().x - menu[i].getGlobalBounds().width / 2;
	position.y = menu[i].getPosition().y + menu[i].getGlobalBounds().height;
	menusprite.setPosition(position);
}

void Menu::backinit(sf::RenderWindow& window)
{
	tback.loadFromFile("zdj/main.jpg");
	background.setTexture(tback);
	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Menu::backdraw(sf::RenderWindow& window)
{
	window.draw(background);
}

void Menu::menuinit(sf::RenderWindow& window)
{
	//window->create(sf::VideoMode(800, 600), "Arkanoid");
	//window->setFramerateLimit(60);
	backinit(window);
	optinit(window);
	spriteinit();
}

void Menu::drawall(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	backdraw(window);
	drawmenu(window);
	drawsprt(window);
	window.display();
}

void Menu::runmenu(sf::RenderWindow& window, sf::Event &event)
{
	while (window.isOpen()) {
		menuevents(window,event);
		drawall(window);
		spritesetpos();
	}
}

void Menu::menuevents(sf::RenderWindow& window,sf::Event &event/* Play* pl*/)
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == Optnumb - 1) {
			window.close();
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getMenuIndex() == 0) {
			Play* pl = new Play(window);
			pl->runplay(window,event);
			delete pl;
			pl = nullptr;
			break;
			//poll event dla Game - silinika?, trzeba tak, aby móc zmieniaæ w kó³ko
		}

	}

}

//sf::RenderWindow* getMenuWin() {
//	return window;
//}
