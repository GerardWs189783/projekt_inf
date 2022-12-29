#pragma once
#include <SFML/Graphics.hpp>

#define Optnumb 4

class Menu
{
private:
	int menuindex;
	sf::Font font;
	sf::Text menu[Optnumb];
	sf::Sprite menusprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;

public:
	Menu(sf::RenderWindow &window);
	void menuUp();
	void menuDown();
	int getMenuIndex();
	void drawmenu(sf::RenderWindow& window);
	void optinit(sf::RenderWindow& window);
	void spriteinit(sf::RenderWindow &window);
	void drawsprt(sf::RenderWindow& window);
	void spritesetpos();
	void backinit(sf::RenderWindow& window);
	void backdraw(sf::RenderWindow& window);
};

