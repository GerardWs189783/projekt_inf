#include "fps.h"

FPS::FPS()
{
	this->initFPS();
}

void FPS::setFPS()
{
	this->text.setString(std::to_string(this->fps));
}

void FPS::drawFPS(sf::RenderWindow& window)
{
	window.draw(this->text);
}
//jeszcze init jutro z rana do kona=ca

void FPS::initFPS()
{
	if (!this->font.loadFromFile("zdj/arial.ttf"))
	{
		return;
	}
	this->text.setFont(this->font);
	this->text.setPosition(sf::Vector2f(10.f, 560.f));
	this->text.setCharacterSize(18);
	this->text.setFillColor(sf::Color::Black);
	this->setFPS();
}

void FPS::FPSrate()
{
	float currentTime = this->clock.restart().asSeconds();
	this->fps = 1 / currentTime;
	this->setFPS();
}