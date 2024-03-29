#pragma once
#include <SFML/Graphics.hpp>
//#include "Menu.h"
#define Menunumb 3
#define Extnumb 2
//#define Optnumb 2

//class Gameover:public Menu{
//private:
//	sf::Text menu[Extnumb];
//public:
//	Gameover(sf::RenderWindow &window);
//	void backinit(sf::RenderWindow& window);
//	void optinit(sf::RenderWindow& window);
//	void menuinit(sf::RenderWindow& window);
//	void menuevents(sf::RenderWindow& window, sf::Event& event);
//};



class Gameover {
protected:
	bool draw;
	int menuindex;
	sf::Font font;
	sf::Text menu[Extnumb];
	sf::Sprite menusprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;

public:
	Gameover(sf::RenderWindow &window);
	//Gameover();
	///*Gameover()*/;
	void menuUp();
	void menuDown();
	int getMenuIndex();
	void drawmenu(sf::RenderWindow& window);
	void spriteinit();
	void drawsprt(sf::RenderWindow& window);
	void spritesetpos();
	void backinit(sf::RenderWindow& window);
	void backdraw(sf::RenderWindow& window);
	void optinit(sf::RenderWindow& window);
	void menuinit(sf::RenderWindow& window);
	void drawall(sf::RenderWindow& window);
	void runmenu(sf::RenderWindow& window, sf::Event& event);
	void menuevents(sf::RenderWindow& window, sf::Event& event);
};

class Win{
private:
	bool draw;
	int menuindex;
	sf::Font font;
	sf::Text menu[Extnumb];
	sf::Sprite menusprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;
	sf::Text *title;
public:
	Win(sf::RenderWindow & window);
	~Win();
	void menuUp();
	void menuDown();
	int getMenuIndex();
	void drawmenu(sf::RenderWindow& window);
	void backinit(sf::RenderWindow& window);
	void backdraw(sf::RenderWindow& window);
	void optinit(sf::RenderWindow& window);
	void menuinit(sf::RenderWindow& window);
	void drawall(sf::RenderWindow& window);
	void runmenu(sf::RenderWindow& window, sf::Event& event);
	void menuevents(sf::RenderWindow& window, sf::Event& event);
	void spriteinit();
	void drawsprt(sf::RenderWindow& window);
	void spritesetpos();
};

class GameMenu {
private:
	int menuindex;
	sf::Font font;
	sf::Text menu[Menunumb];
	sf::Sprite menusprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;
	/*sf::RenderWindow* window;*/

public:
	GameMenu(sf::RenderWindow& window);
	void menuUp();
	void menuDown();
	int getMenuIndex();
	void drawmenu(sf::RenderWindow& window);
	void optinit(sf::RenderWindow& window);
	void spriteinit();
	void drawsprt(sf::RenderWindow& window);
	void spritesetpos();
	void backinit(sf::RenderWindow& window);
	void backdraw(sf::RenderWindow& window);
	void menuinit(sf::RenderWindow& window);
	void drawall(sf::RenderWindow& window);
	void runmenu(sf::RenderWindow& window, sf::Event& event);
	void menuevents(sf::RenderWindow& window, sf::Event& event);

};