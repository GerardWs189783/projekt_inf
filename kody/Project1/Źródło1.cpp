//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//class Ball
//{
//private:
//	sf::Vector2f position;
//	float xVel = 1, yVel = 1;
//	sf::Texture tekstura;
//	sf::Sprite pSprite;
//	sf::Vector2f romzmiar_okna;
//public:
//	Ball(float x_in, float y_in, float rx_in, float ry_in)
//	{
//		position.x = x_in;
//		position.y = y_in;
//		romzmiar_okna.x = rx_in - 100;
//		romzmiar_okna.y = ry_in - 100;
//		tekstura.loadFromFile("zdj/shrokjj.png");
//		pSprite.setTexture(tekstura);
//		pSprite.setPosition(position);
//	}
//	void przesun(float x_in, float y_in);
//	sf::Sprite getBall() { return pSprite; }
//	void sprawdzKolizjeSciany();
//	void animuj();
//};
//
//void Ball::przesun(float x_in, float y_in)
//{
//	sf::Vector2f pos;
//	pos.x = x_in;
//	pos.y = y_in;
//	pSprite.move(pos);
//	position = pSprite.getPosition();
//}
//
//void Ball::sprawdzKolizjeSciany()
//{
//	if (position.x <= 0)
//		xVel = 1;
//	if (position.x >= romzmiar_okna.x)
//		xVel = -1;
//	if (position.y <= 0)
//		yVel = 1;
//	if (position.y >= romzmiar_okna.y)
//		yVel = -1;
//}
//void Ball::animuj()
//{
//	sprawdzKolizjeSciany();
//	przesun(xVel, yVel);
//}
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML animation");
//	sf::Event event;
//	Ball pb(100, 100, 800, 600);
//	sf::Clock zegar;
//
//	while (window.isOpen())
//	{
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		window.clear(sf::Color::Green);
//		window.draw(pb.getBall());
//		window.display();
//		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
//			pb.animuj();
//			zegar.restart();
//		}
//	}
//	return 0;
//}