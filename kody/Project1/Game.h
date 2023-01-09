#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Play.h"
#include <iostream>
#include "Level.h"
#include "Gameover.h"

class Game
{
private:
	//Var
	//Window
	sf::RenderWindow* window;
	sf::Event event;
	Menu* menu;
	Play* play;
	//sf::VideoMode videoMode;
	//void initVar();
	//void initWindow();
	int gamestate;
	Level* level;
	Gameover* gameover;
public:
	Game();
	//~Game();

	//const bool running();
	////FUNKCJE
	void pollEvent();
	void rungame();
	void gameinit();
	//void update();
	void render();
	void returnmenu();
	void returnplay();
};

