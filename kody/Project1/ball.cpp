#include "ball.h"
#include "block.h"
#include <iostream>

Ball::Ball(float x_in, float y_in, float rx_in, float ry_in)
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
	romzmiar_okna.x = rx_in - pSprite.getGlobalBounds().width /*-70*/;
	romzmiar_okna.y = ry_in - pSprite.getGlobalBounds().height /*- 70*/;
	ballbound = pSprite.getGlobalBounds();
	score = 0;	
	this->scoreinit();
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

void Ball::animuj(sf::Sprite sprite, sf::Sprite sprite1)
{
	sprawdzKolizjeSciany();
	sprawdzKolizjeObiektu(sprite);
	przesun(xVel, yVel);
	scoreincr(sprite1);
}

void Ball::sprawdzKolizjeObiektu(sf::Sprite sprite)
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
	}

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
	this->scoretext.setString("Score: " + std::to_string(this->score));
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

void Ball::scoreincr(sf::Sprite sprite)
{
	if (pSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		this->score ++;
	}
}