#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle 
{
private:
	sf::Vector2f position;
	float speed;
	sf::Texture tekstura;
	sf::Sprite skin;
	sf::Vector2f okno;
public:
	Paddle(float x_in, float y_in, float rx_in, float ry_in)
			{
				position.x = x_in;
				position.y = y_in;
				okno.x = rx_in - 100;
				okno.y = ry_in - 100;
				tekstura.loadFromFile("zdj/oak.jpg");
				skin.setTexture(tekstura);
				skin.setPosition(position);
				skin.setScale(sf::Vector2f(100.f / skin.getLocalBounds().width, 40.f / skin.getLocalBounds().height));
				skin.setOrigin(sf::Vector2f(skin.getLocalBounds().width / 2.f, skin.getLocalBounds().height / 2.f));
			}

	void move(sf::Vector2f mov) {
		position.x = mov.x;
		position.y = mov.y;
		if (!(mov.x < skin.getGlobalBounds().width / 2.f || mov.x > 800 - skin.getGlobalBounds().width / 2.f)) {
			skin.setPosition(position);
		}
	}

	sf::Sprite getSprite() {
		return skin;
	}

	void pdraw(sf::RenderWindow& window) {
		window.draw(skin);
	}
};

class Ball
{
private:
	sf::Vector2f position;
	float xVel = 4, yVel = 4;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f romzmiar_okna;
public:
	Ball(float x_in, float y_in, float rx_in, float ry_in)
	{
		position.x = x_in;
		position.y = y_in;
		romzmiar_okna.x = rx_in - 100;
		romzmiar_okna.y = ry_in - 100;
		tekstura.loadFromFile("zdj/shrokjj.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
	}
	void przesun(float x_in, float y_in);
	sf::Sprite getBall() { return pSprite; }
	void sprawdzKolizjeSciany();
	void animuj(sf::Sprite sprite);
	void sprawdzKolizjeObiektu(sf::Sprite sprite);
};

void Ball::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();
}

void Ball::sprawdzKolizjeSciany()
{
	if (position.x <= 0)
		xVel = abs(xVel);
	if (position.x >= romzmiar_okna.x)
		xVel = -abs(xVel);
	if (position.y <= 0)
		yVel = abs(yVel);
	if (position.y >= romzmiar_okna.y)
		yVel = -abs(yVel);
}


void Ball::sprawdzKolizjeObiektu(sf::Sprite sprite) {
	if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		yVel *= -1;
	}
}

void Ball::animuj(sf::Sprite sprite)
{
	sprawdzKolizjeSciany();
	sprawdzKolizjeObiektu(sprite);
	przesun(xVel, yVel);
}


int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML animation");
	sf::Event event;
	sf::Clock zegar;

	Paddle p1(400, 500, 800, 600);
	Ball pb(100, 100, 800, 600);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved) {
				p1.move(sf::Vector2f(sf::Mouse::getPosition(window).x, 500));
			}
		}
		window.clear(sf::Color::Green);
		p1.pdraw(window);
		window.draw(pb.getBall());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
			pb.animuj(p1.getSprite());
			zegar.restart();
		}
	}
	return 0;
}