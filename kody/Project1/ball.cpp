#include "ball.h"
#include "block.h"
#include <iostream>
#include "paddle.h"


Ball::Ball(float x_in, float y_in,sf::RenderWindow& window, Lifeheart *lh)
{
	this->position.x = x_in;
	this->position.y = y_in;
	//romzmiar_okna.x = rx_in - 70;
	//romzmiar_okna.y = ry_in - 70;
	this->tekstura.loadFromFile("zdj/shrokjj.png");
	pSprite.setTexture(tekstura);
	pSprite.setPosition(position);
	pSprite.setScale(sf::Vector2f(70.f / pSprite.getLocalBounds().width, 70.f / pSprite.getLocalBounds().height));
	/*pSprite.setOrigin(pSprite.getGlobalBounds().width/2.f, pSprite.getGlobalBounds().height/2.f);*/
	romzmiar_okna.x = window.getSize().x - pSprite.getGlobalBounds().width /*-70*/;
	romzmiar_okna.y = window.getSize().y - pSprite.getGlobalBounds().height /*- 70*/;
	ballbound = pSprite.getGlobalBounds();
	score = 0;	
	this->scoreinit();
	this->velInit();
	this->hpinit(window,lh);
}

void Ball::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();

}

sf::Sprite Ball::getBall() { return pSprite; }

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

void Ball::animuj(Paddle* pad, BlockTab* block, Heart* hrt, sf::RenderWindow& win)
{
	sf::Sprite sprite = pad->getSprite();

	utratahp(hrt, win);
	sprawdzKolizjeSciany();
	sprawdzKolizjeObiektu(sprite);
	przesun(xVel, yVel);
	/*int n = block->getsize();*/
	//int n = block->bTabsize();
	for (int i = 0; i < block->bTabsize(); i++) {
		auto blockpointer = block->getelementpointerb(i);
		/*std::cout << "test2\n";*/
		if (blockpointer != nullptr) {
			if (blockpointer->gethp() > 0) {

				sf::Sprite sprite1 = blockpointer->getSprite();

				scoreincr(sprite1);

				if (sprawdzKolizjeObiektu(sprite1) == 1) {
					if (blockpointer->hit() > 0) {
						blockpointer->animacja();
						//std::cout << blockpointer->hit() << "\n";
					}
				}
			}
			else {
				block->usunelement(i);

			}
		}
		
	}


}

int Ball::sprawdzKolizjeObiektu(sf::Sprite &sprite)
{
	sf::FloatRect overlap = sprite.getGlobalBounds();
	if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {

		//Najlepiej dzia³a na lew¹ stronê resztynie dotyka ale jest to chyba robocze
		if (pSprite.getPosition().x < sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width &&
			pSprite.getPosition().x + pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width &&
			abs(sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x) < abs(sprite.getPosition().y + (0.5) * sprite.getGlobalBounds().height - pSprite.getPosition().y) /*&&
			pSprite.getPosition().y+pSprite.getGlobalBounds().height > sprite.getPosition().y - (0.5)*sprite.getGlobalBounds().height*/
			&& sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x <(pSprite.getGlobalBounds().width) / 2
			&& pSprite.getPosition().x + pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width)
		{
			xVel *= -1;
			pSprite.move(sf::Vector2f(sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x, 0.f));
		}
		//////prawa strona pi³ki
		else if (pSprite.getPosition().x + pSprite.getGlobalBounds().width > sprite.getPosition().x - (sprite.getGlobalBounds().width) / 2.f &&
			pSprite.getPosition().x < sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width &&
			pSprite.getPosition().x < sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width &&
			abs(sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width - pSprite.getPosition().x -pSprite.getGlobalBounds().width) < abs(sprite.getPosition().y + (0.5) * sprite.getGlobalBounds().height - pSprite.getPosition().y)
			&& pSprite.getPosition().y + pSprite.getGlobalBounds().height > sprite.getPosition().y + (0.5) * sprite.getGlobalBounds().height
			/*&& pSprite.getPosition().y > sprite.getPosition().y - (0.5) * sprite.getGlobalBounds().height*/)
		{
			xVel *= -1;
			pSprite.move(sf::Vector2f(pSprite.getPosition().x + pSprite.getGlobalBounds().width - sprite.getPosition().x + (sprite.getGlobalBounds().width) / 4.f, 0.f));
		}
		////Góra 
		else if (/*pSprite.getPosition().y < sprite.getPosition().y + (0.5)*sprite.getGlobalBounds().height &&*/ pSprite.getPosition().y + pSprite.getGlobalBounds().height > sprite.getPosition().y - (0.5) * sprite.getGlobalBounds().height
			&& pSprite.getPosition().x +pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width && pSprite.getPosition().x < sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width
			&& pSprite.getPosition().y + pSprite.getGlobalBounds().height < sprite.getPosition().y + (0.5)*sprite.getGlobalBounds().height)
		{
			yVel *= -1;
			pSprite.move(sf::Vector2f(0.f, sprite.getPosition().y - (0.5) * sprite.getGlobalBounds().height - pSprite.getPosition().y - pSprite.getGlobalBounds().height));
		}
		////Dó³ po³owa do³u nie dzia³a
		else if (pSprite.getPosition().y + pSprite.getGlobalBounds().height > sprite.getPosition().y - (0.5) * sprite.getGlobalBounds().height && pSprite.getPosition().y <sprite.getPosition().y + (0.5)*sprite.getGlobalBounds().height
			&& pSprite.getPosition().x +pSprite.getGlobalBounds().width > sprite.getPosition().x - (0.5) * sprite.getGlobalBounds().width && pSprite.getPosition().x < sprite.getPosition().x + (0.5) * sprite.getGlobalBounds().width)
		{
			yVel *= -1;
			pSprite.move(sf::Vector2f(0.f, + sprite.getPosition().y + (0.5) * sprite.getGlobalBounds().height - pSprite.getPosition().y));
		}
		/*yVel *= -1;*/
		return 1;
	}
	return 0;

}

//bool Ball::isCollidingWithBlock(Block* block) 
//{
//	if (pSprite.getGlobalBounds().intersects(block->getBounds())) {
//		return true;
//	}
//	return false;
//}

void Ball::scoreinit()
{
	if (!this->font.loadFromFile("zdj/arial.ttf"))
	{
		return ;
	}
	this->scoretext.setFont(this->font);
	this->scoretext.setPosition(sf::Vector2f(10.f, 5.f));
	this->scoretext.setCharacterSize(28);
	this->scoretext.setFillColor(sf::Color::Black);
	setScore();
}

//int Ball::scorecount(Block *block)
//{
//	if (this->isCollidingWithBlock(block) == true)
//	{
//		this->score += 1;
//		return score;
//	}
//}

void Ball::drawt(sf::RenderWindow& window)
{
	window.draw(pSprite);
	window.draw(this->scoretext);
}

void Ball::scoreincr(sf::Sprite &sprite)
{
	if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		this->score ++;
		setScore();
	}
}

void Ball::setScore()
{
	this->scoretext.setString("Score: " + std::to_string(this->score));
}

void Ball::velInit()
{
	this->yVel = 6;
	this->xVel = 6;
}

void Ball::utratahp(Heart *hrt, sf::RenderWindow &win) {
	if (position.y + pSprite.getGlobalBounds().height > win.getSize().y) {
		hrt->dechp();
		pSprite.setPosition(sf::Vector2f(400.f,300.f));
		yVel = 6;
		std::cout << "HP: " << hrt->gethp() << std::endl;
	}
}

void Ball::hpinit(sf::RenderWindow& window, Lifeheart* lh) {
	int ilosc = 3;
	for (int i = 0; i < ilosc; i++) {
		heartTab.push_back(new Heart(window, lh));

		sf::FloatRect bound = ((Heart*)heartTab[i])->getBounds();
		((Heart*)heartTab[i])->setpos(sf::Vector2f(lh->getpos().x + 100 + bound.width * (i + 1), window.getSize().y - bound.height / 2));
		((Heart*)heartTab[i])->getsprt()->setPosition(((Heart*)heartTab[i])->getpos());
	}
	
}

void Ball::hpdraw(sf::RenderWindow& window) {
	for (int i = 0; i < heartTab.size(); i++) {
		((Heart*)heartTab[i])->draw(window);
	}
}

void Ball::hanima(Heart* hrt, sf::RenderWindow& win) {
	for (int i = 0; i < heartTab.size(); i++) {
		// sprawdzanie utraty hp i usuwanie
	}
}

Heart* Ball::getpheart(int n) {
	return (Heart*)heartTab[n];
}