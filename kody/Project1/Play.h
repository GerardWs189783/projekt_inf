#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

#define Optnumb 4

class Play
{
protected:
	int playindex;
	int draw;
	sf::Font font;
	sf::Text play[Optnumb];
	sf::Sprite playsprite;
	sf::Texture tsprt;
	sf::Vector2f position;
	sf::Sprite background;
	sf::Texture tback;
	/*sf::RenderWindow* window;*/

public:
	Play(sf::RenderWindow& window);
	~Play();
	void playUp();
	void playDown();
	int getPlayIndex();
	void drawplay(sf::RenderWindow& window);
	void optinit(sf::RenderWindow& window);
	void spriteinit();
	void drawsprt(sf::RenderWindow& window);
	void spritesetpos();
	void backinit(sf::RenderWindow& window);
	void backdraw(sf::RenderWindow& window);
	void playinit(sf::RenderWindow& window);
	void drawall(sf::RenderWindow& window);
	void runplay(sf::RenderWindow& window, sf::Event event);
	void playevents(sf::RenderWindow& window,sf::Event &event);
	int getdraw();
	/*Play();
	void playsetString();*/
};
