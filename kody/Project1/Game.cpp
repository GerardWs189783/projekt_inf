//#include "Game.h"
//#include "paddle.h"
////Privatefun
//void Game::initVar()
//{
//	this->window = nullptr;
//
//}
//
//void Game::initWindow()
//{
//	this->videoMode.height = 600;
//	this->videoMode.width = 800;
//	this->window = new sf::RenderWindow(this->videoMode, "Arkanoid");
//}
//
//Game::Game()
//{
//	this->initVar();
//	this->initWindow();
//}
//Game::~Game()
//{
//	delete this->window;
//}
//const bool Game::running()
//{
//	return this->window->isOpen();
//}
//void Game::pollEvent()
//{
//	bool wait = true;
//	while (this->window->pollEvent(this->ev))
//	{
//		if (this->ev.type == sf::Event::Closed || (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape))
//			this->window->close();
//
//	/*	if (this->ev.type == sf::Event::MouseMoved && wait == true) {
//			p1.move(sf::Vector2f(sf::Mouse::getPosition(*this->window).x, 540));
//		}*/
//		if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::P)
//			wait = !wait;
//	}
//}
////fun
//void Game::update()
//{
//	this->pollEvent();
//}
//
//void Game::render()
//{
//	/*
//	Render objects
//	*/
//	this->window->clear(sf::Color::Green);
//	this->window->display();
//}
