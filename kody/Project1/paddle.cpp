#include "paddle.h"

Paddle::Paddle(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	tekstura.loadFromFile("zdj/oak.jpg");
	skin.setTexture(tekstura);
	skin.setPosition(position);
	skin.setScale(sf::Vector2f(100.f / skin.getLocalBounds().width, 40.f / skin.getLocalBounds().height));
	skin.setOrigin(sf::Vector2f(skin.getLocalBounds().width / 2.f, skin.getLocalBounds().height / 2.f));
}

void Paddle::move(sf::Vector2f mov) {
	position.x = mov.x;
	position.y = mov.y;
	if (!(mov.x < skin.getGlobalBounds().width / 2.f || mov.x > 800 - skin.getGlobalBounds().width / 2.f)) {
		skin.setPosition(position);
	}
}

sf::Sprite Paddle::getSprite() {
	return skin;
}
sf::Sprite* Paddle::getSpritep() {
	return &skin;
}

void Paddle::pdraw(sf::RenderWindow& window) {
	window.draw(skin);
}