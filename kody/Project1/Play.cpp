#include "Play.h"

//Play::Play()
//{
//	/*playsetString();*/
//}

//void Play::playsetString()
//{
//	//menu[0].setString("LEVEL 1");
//	//menu[1].setString("LEVEL 2");
//	//menu[2].setString("LEVEL 3");
//	//menu[3].setString("MAIN MENU");
//}

Play::Play(sf::RenderWindow& window)
{
	/*this->window = new sf::RenderWindow();*/
	this->playindex = 0;
	playinit(window);
	draw = 0;

}

Play::~Play()
{
}

void Play::playUp()
{


	play[playindex].setFillColor(sf::Color::White);

	if (playindex == 0) {
		playindex = Optnumb - 1;
	}
	else {
		playindex--;
	}
	play[playindex].setFillColor(sf::Color::Blue);
}

void Play::playDown()
{
	play[playindex].setFillColor(sf::Color::White);
	if (playindex == Optnumb - 1) {
		playindex = 0;

	}
	else {
		playindex++;
	}
	play[playindex].setFillColor(sf::Color::Blue);
}

int Play::getPlayIndex()
{
	return this->playindex;
}

void Play::drawplay(sf::RenderWindow& window)
{
	for (int i = 0; i < Optnumb; i++) {
		window.draw(play[i]);
	}
}

void Play::optinit(sf::RenderWindow& window)
{
	if (!font.loadFromFile("zdj/arial.ttf"))
		return;

	play[0].setFont(font);
	play[0].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 1));
	play[0].setCharacterSize(40);
	play[0].setFillColor(sf::Color::Blue);
	play[0].setString("LEVEL 1");

	play[1].setFont(font);
	play[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 2));
	play[1].setCharacterSize(40);
	play[1].setFillColor(sf::Color::White);
	play[1].setString("LEVEL 2");

	play[2].setFont(font);
	play[2].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 3));
	play[2].setCharacterSize(40);
	play[2].setFillColor(sf::Color::White);
	play[2].setString("LEVEL 3");

	play[3].setFont(font);
	play[3].setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / (Optnumb + 1) * 4));
	play[3].setCharacterSize(40);
	play[3].setFillColor(sf::Color::White);
	play[3].setString("MAIN MENU");
}

void Play::spriteinit()
{
	tsprt.loadFromFile("zdj/trock.png");
	playsprite.setTexture(tsprt);
	playsprite.setScale(sf::Vector2f(100.f / playsprite.getLocalBounds().width, 80.f / playsprite.getLocalBounds().height));
	playsprite.setOrigin(sf::Vector2f(playsprite.getLocalBounds().width / 2.f, playsprite.getLocalBounds().height / 2.f));
	position.x = play[0].getPosition().x - play[0].getGlobalBounds().width / 2;
	position.y = play[0].getPosition().y + play[0].getGlobalBounds().height;
	playsprite.setPosition(position);
}

void Play::drawsprt(sf::RenderWindow& window)
{
	window.draw(playsprite);
}

void Play::spritesetpos()
{
	int i = getPlayIndex();
	position.x = play[i].getPosition().x - play[i].getGlobalBounds().width / 2;
	position.y = play[i].getPosition().y + play[i].getGlobalBounds().height;
	playsprite.setPosition(position);
}

void Play::backinit(sf::RenderWindow& window)
{
	tback.loadFromFile("zdj/main.jpg");
	background.setTexture(tback);
	/*background.setScale(sf::Vector2f(100.f / background.getLocalBounds().width, 80.f / background.getLocalBounds().height));*/
	background.setOrigin(sf::Vector2f(background.getLocalBounds().width / 2.f, background.getLocalBounds().height / 2.f));
	background.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Play::backdraw(sf::RenderWindow& window)
{
	window.draw(background);
}

void Play::playinit(sf::RenderWindow& window)
{
	//window.create(sf::VideoMode(800, 600), "Arkanoid");
	//window.setFramerateLimit(60);
	backinit(window);
	optinit(window);
	spriteinit();
}

void Play::drawall(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	backdraw(window);
	drawplay(window);
	drawsprt(window);
	window.display();
}

void Play::runplay(sf::RenderWindow& window,sf::Event event)
{
	while (window.isOpen() && draw == 0) {
		playevents(window,event);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && getPlayIndex() == Optnumb - 1) {
			draw = 1;
			/*window.close();*/
			break;
		}
		drawall(window);
		spritesetpos();
	}
}

void Play::playevents(sf::RenderWindow& window, sf::Event &event)
{
	/*sf::Event event;*/

	while (window.pollEvent(event) && draw == 0) {
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up) {
				playUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				playDown();
				break;
			}
		}
		

	}

}

int Play::getdraw() {
	return draw;
}
