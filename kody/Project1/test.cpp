////#include <SFML/Graphics.hpp>
////#include <iostream>
////#include "Game.h"
////#include "paddle.h"
////
////int main()
////{
////	Game game;
////	while (game.running())
////	{
////	//Event poll w game
////	//Tu tylko update i render
////	game.update();
////	game.render();
////}
////}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <SFML/Graphics.hpp> 
//#include <ctime> 
//#include <iostream> 
//#include <random> 
//#include <string> 
//#include <cstdio> 
//#include <cstdlib>
//class interfejs
//{
//public:
//	interfejs(sf::Vector2f position);
//	~interfejs();
//	void draw(sf::RenderWindow& win);
//	void setText(sf::Text* text1, sf::Text* text2, sf::Text* text3);
//protected:
//	sf::RectangleShape* int_1;
//	sf::Font* font;
//	sf::Text* text1;
//	sf::Text* text2;
//	sf::Text* text3;
//	sf::Vector2f position;
//	void init(sf::Vector2f widht_height);
//};
//interfejs::interfejs(sf::Vector2f position)
//{
//	this->position.x = position.x;
//	this->position.y = position.y;
//	sf::Vector2f width_height(756.f, 500);//windowsize.x /windowsize.y
//	init(width_height);
//}
//interfejs::~interfejs()
//{
//	delete int_1;
//	int_1 = NULL;
//}
//void interfejs::init(sf::Vector2f width_height)
//{
//	int_1 = new sf::RectangleShape;
//	font = new sf::Font;
//	text1 = new sf::Text;
//	text2 = new sf::Text;
//	text3 = new sf::Text;
//	font->loadFromFile("zdj/arial.ttf");
//	text1->setFont(*font);///??? 
//	text2->setFont(*font);///??? 
//	text3->setFont(*font);///??? 
//
//	int_1->setPosition(22.f, 55.f);
//	int_1->setSize(width_height);
//	int_1->setFillColor(sf::Color(0, 0, 255));
//	setText(text1, text2, text3);
//
//}
//void interfejs::draw(sf::RenderWindow& win)
//{
//	win.draw(*int_1);
//	win.draw(*text1);
//	win.draw(*text2);
//	win.draw(*text3);
//
//}
//void interfejs::setText(sf::Text* text1, sf::Text* text2, sf::Text* text3)
//{
//	text1->setString("Left top");
//	text2->setString("Right top");
//	text3->setString("Center bottom");
//	text1->setCharacterSize(24);
//	text2->setCharacterSize(24);
//	text3->setCharacterSize(24);
//	text1->setFillColor(sf::Color(135, 206, 255));
//	text2->setFillColor(sf::Color(240, 248, 255));
//	text3->setFillColor(sf::Color(234, 221, 202));
//	text1->setPosition(100.f, 100.f);
//	text2->setPosition(300.f, 300.f);
//	text3->setPosition(500.f, 500.f);
//}
//
//
//int main()
//{
//	interfejs one(sf::Vector2f(800.f, 600.f));
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML demo");
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		window.clear();
//		one.draw(window);
//
//		window.display();
//	}
//
//
//	return 0;
//}