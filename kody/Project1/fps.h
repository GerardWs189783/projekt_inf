#pragma once
#include <SFML/Graphics.hpp>


class FPS
{
private:
	sf::Font font;
	sf::Text text;
	sf::Clock clock;
	int fps;
	void initFPS();

public:
	FPS();
	void setFPS();
	void drawFPS(sf::RenderWindow& window);
	void FPSrate();
};

