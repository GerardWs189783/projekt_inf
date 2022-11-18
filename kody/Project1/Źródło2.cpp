//#include <SFML/Graphics.hpp>
//#include <random>
//
//
//class toads {
//private:
//    sf::CircleShape *ball;
//    int N;
//    //https://docs.microsoft.com/pl-pl/cpp/standard-library/random?view=msvc-160#code
//    std::random_device rd;
//
//public:
//    toads(int Nt);
//    void draw(sf::RenderWindow& window);
//    void move();
//};
//
//
//toads::toads(int Nt) {
//
//    std::mt19937 gen(rd());  
//    std::uniform_int_distribution<> distX(1, 750);
//    std::uniform_int_distribution<> distY(1, 550);
//    float x = 0, y = 0;
//    N = Nt;
//    ball = new sf::CircleShape[N];
//    for (int i = 0; i < N; i++)
//    {
//        x = distX(gen);
//        y = distY(gen);
//
//        (ball + i )->setRadius(20);
//        (ball + i)->setFillColor(sf::Color(150, 50, 250));
//        (ball + i)->setPosition(sf::Vector2f(x, y));
//        /*ball[i].setScale(sf::Vector2f(0.03f, 0.03f));*///skalowanie rozmiaru
//    }
//}
//
//void toads::draw(sf::RenderWindow& window) {
//    for (int i = 0; i < N; i++)
//    {
//        window.draw(*(ball+i));
//    }
//}
//
//void toads::move() {
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distX(1, 750);
//    std::uniform_int_distribution<> distY(1, 550);
//    std::uniform_int_distribution<> distXl(-20, 20);
//    std::uniform_int_distribution<> distYl(-20, 20);
//    for (int i = 0; i < N; i++)
//    {
//        (ball + i)->move(sf::Vector2f(distXl(gen), distYl(gen)));
//        sf::Vector2f position = (ball + i)->getPosition();
//        if (position.x > 750 || position.x < 0 || position.y > 530 || position.y < 0)
//            (ball + i)->setPosition(distX(gen), distY(gen));
//    }
//
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Super Mario Toads");
//    sf::Clock zegar;
//    toads td(10);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        if (zegar.getElapsedTime().asMilliseconds() > 100.0f) {
//            td.move();		
//            zegar.restart();
//        }
//
//        window.clear(sf::Color::White);
//        td.draw(window);
//        window.display();
//    }
//
//    return 0;
//}