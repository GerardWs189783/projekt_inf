#include "ball.h"

//std::random_device rd1;

Ball::Ball(sf::RenderWindow& window, Lifeheart *lh)
{

	//romzmiar_okna.x = rx_in - 70;
	//romzmiar_okna.y = ry_in - 70;
	this->tekstura.loadFromFile("zdj/shrokjj.png");
	pSprite.setTexture(tekstura);
	
	pSprite.setScale(sf::Vector2f(70.f / pSprite.getLocalBounds().width, 70.f / pSprite.getLocalBounds().height));
	/*pSprite.setOrigin(pSprite.getGlobalBounds().width/2.f, pSprite.getGlobalBounds().height/2.f);*/
	romzmiar_okna.x = window.getSize().x - pSprite.getGlobalBounds().width /*-70*/;
	romzmiar_okna.y = window.getSize().y - pSprite.getGlobalBounds().height /*- 70*/;
	ballbound = pSprite.getGlobalBounds();
	score = 0;	
	this->ilosc = 1;
	this->scoreinit();
	this->velInit();
	this->hpinit(window,lh);
	this->position.x = window.getSize().x / 2.0f - (0.7)*pSprite.getGlobalBounds().width ;
	this->position.y = window.getSize().y / 2.0f + 100;
	pSprite.setPosition(position);
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


void Ball::animuj(Paddle* pad, BlockTab* block,sf::RenderWindow& win, bool* wait)
{
	sf::Sprite sprite = pad->getSprite();

	/*utratahp(hrt, win);*/
	hanima(win,wait,pad);
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

bool Ball::utratahp(Heart *hrt, sf::RenderWindow &win, bool* wait, Paddle* p) {
	/*sf::Clock clock;*/
	if (position.y + pSprite.getGlobalBounds().height + 10 >= win.getSize().y) {
		hrt->dechp();
		yVel = this->yVel;
		std::cout << "HP: " << hrt->gethp() << std::endl;
		hppause(win,wait,p);
		/*setrandpos(win);*/
		return true;
		
	}
	return false;
}

void Ball::hpinit(sf::RenderWindow& window, Lifeheart* lh) {
	
	for (int i = 0; i < this->ilosc; i++) {
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

void Ball::hanima(sf::RenderWindow& win, bool* wait, Paddle* p) {
	
	if (((Heart*)heartTab[heartTab.size() - 1])->gethp() > 0)
		utratahp(heartTab[heartTab.size() - 1], win,wait,p);
	else
		heartTab.pop_back();
	
}

Heart* Ball::getpheart(int n) {
	return (Heart*)heartTab[n];
}

int Ball::hpTabsize() {
	return heartTab.size();
}

//bool Ball::hppause(sf::RenderWindow& win, bool* wait) {
//	if (position.y + pSprite.getGlobalBounds().height + 10 >= win.getSize().y) {
//		*wait = false;
//		
//		return true;
//		/*sf::Clock* clock = new sf::Clock;
//		if (clock->getElapsedTime().asSeconds() > 3.0f) {
//			delete clock;
//			*wait = true;
//		}*/
//	}
//	return false;
//}

void Ball::hppause(sf::RenderWindow& win, bool* wait, Paddle* p) {

	*wait = false;
	setrandpos(win,p);
	
}


void Ball::setrandpos(sf::RenderWindow& win, Paddle *p) {
	/*std::mt19937 gen(rd1());
	std::uniform_int_distribution<> distX(0, 700);
	int px = distX(gen);*/
	pSprite.setPosition(sf::Vector2f(p->getpos().x - pSprite.getGlobalBounds().width / 2, p->getpos().y - pSprite.getGlobalBounds().height));
}
