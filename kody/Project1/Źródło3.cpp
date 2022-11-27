//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <SFML/Graphics.hpp>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//
//typedef struct {
//	char nazwa[20];
//	int liczb_pkt;
//	char plec;
//} gracz_cechy;
//
//
//
//
//
//void players_to_file()
//{
//	srand(time(NULL));
//	gracz_cechy playerschar[10];
//
//	FILE* fp;
//	fp = fopen("gracze.dat", "w+b");
//
//	strcpy(playerschar[0].nazwa, "Johny");
//	strcpy(playerschar[1].nazwa, "Bathman");
//	strcpy(playerschar[2].nazwa, "Dedman");
//	strcpy(playerschar[3].nazwa, "Bethymanamm");
//	strcpy(playerschar[4].nazwa, "Alloy_jr");
//	strcpy(playerschar[5].nazwa, "Poul");
//	strcpy(playerschar[6].nazwa, "Snake");
//	strcpy(playerschar[7].nazwa, "BK");
//	strcpy(playerschar[8].nazwa, "Pascal");
//	strcpy(playerschar[9].nazwa, "Java");
//
//
//	for (int i = 0; i < 10; i++)
//		playerschar[i].liczb_pkt = rand() % 2000;
//	playerschar[0].plec = 'm';
//	playerschar[1].plec = 'w';
//	playerschar[2].plec = 'm';
//	playerschar[3].plec = 'w';
//	playerschar[4].plec = 'm';
//	playerschar[5].plec = 'w';
//	playerschar[6].plec = 'm';
//	playerschar[7].plec = 'w';
//	playerschar[8].plec = 'w';
//	playerschar[9].plec = 'w';
//	fwrite(playerschar, sizeof(gracz_cechy), 10, fp);
//	fclose(fp);
//}
//
//int porownaj(const void* left, const void* right) {
//	const gracz_cechy* a = (const gracz_cechy*)left;
//	const gracz_cechy* b = (const gracz_cechy*)right;
//	if (a->liczb_pkt > b->liczb_pkt) {
//		return -1;
//	}
//	else if (a->liczb_pkt < b->liczb_pkt) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//class players_list {
//private:
//	sf::Text* players;//dane tekstowe do wyswietlenia
//	gracz_cechy* player_char;//rzeczywista specyfikacja graczy
//	sf::Font czcionka;
//	int Np;
//public:
//	players_list(int N);
//	void laduj();
//	void sortuj();
//	void draw(sf::RenderWindow& window);
//};
//
//players_list::players_list(int N)
//{
//
//	if (!czcionka.loadFromFile("zdj/arial.ttf"))
//		return;
//
//	FILE* fp = fopen("gracze.dat", "r+b");
//	unsigned int rozmiar_plik = 0, ile_graczy = 0;
//	fseek(fp, 0, SEEK_END);//na ostatni bajt
//	rozmiar_plik = ftell(fp);//czytaj indeks ostatniego bajtu
//	ile_graczy = rozmiar_plik / sizeof(gracz_cechy);
//	if (N > ile_graczy)
//	{
//		Np = 5;//moze byc cokolwiek by zabezpieczalo przed odczytem danych ktorych nie ma
//	}
//	else
//	{
//		Np = N;
//	}
//
//	players = new sf::Text[Np];
//	player_char = new gracz_cechy[Np];
//
//	rewind(fp);//czytaj od poczatku
//	fread(player_char, sizeof(gracz_cechy), Np, fp);
//	fclose(fp);
//
//	for (int i = 0; i < Np; i++)
//	{
//		players[i].setFont(czcionka);
//		players[i].setCharacterSize(30);
//		players[i].setFillColor(sf::Color::Red);
//		players[i].setPosition(10 + 800 / 4, 20 + (float)i * 50);
//
//	}
//}
//
//
//void players_list::laduj()
//{
//	std::string tmp_tekst;
//	for (int i = 0; i < Np; i++)
//	{
//		players[i].setFont(czcionka);
//		players[i].setCharacterSize(30);
//		players[i].setFillColor(sf::Color::Red);
//		players[i].setPosition(10 + 800 / 4, 20 + (float)i * 50);
//
//		tmp_tekst.assign(player_char[i].nazwa);
//		tmp_tekst += " Punkty: " + std::to_string(player_char[i].liczb_pkt);
//		if (player_char[i].plec == 'm')
//			tmp_tekst += " MAN";
//		if (player_char[i].plec == 'w')
//			tmp_tekst += " WOMAN";
//		players[i].setString(tmp_tekst);
//	}
//}
//
//
//void players_list::sortuj()
//{
//	qsort(player_char, Np, sizeof(gracz_cechy), porownaj);
//}
//
//void players_list::draw(sf::RenderWindow& window)
//{
//	for (int i = 0; i < Np; i++)
//	{
//		window.draw(players[i]);
//	}
//}
//
//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML demo");// utworz okno
//	players_to_file();//potrzebne tylko raz!
//
//	players_list* pl = new players_list(8);
//	pl->sortuj();
//	pl->laduj();
//	// petla wieczna - dopoki okno jest otwarte
//	while (window.isOpen())
//	{
//		// w kazdej iteracji petli sprawdzaj zdarzenia
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// jezeli odebrano zdarzenie "Closed" zamknij okno
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		pl->draw(window);
//
//		window.display();
//	}
//
//	return 0;
//}