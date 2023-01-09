#pragma once
#include <SFML/Graphics.hpp>
#include "Play.h"

#define Optnumb 4

class Menu
{
protected:
	int menuindex;
	sf::Font font;
	sf::Text menu[Optnumb];
	sf::Sprite menusprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;
	/*sf::RenderWindow* window;*/

public:
	Menu(sf::RenderWindow &window);
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
	void runmenu(sf::RenderWindow& window, sf::Event &event);
	void menuevents(sf::RenderWindow& window, sf::Event &event/*,Play* pl*/);
	/*sf::RenderWindow* getMenuWin();*/
	
};

