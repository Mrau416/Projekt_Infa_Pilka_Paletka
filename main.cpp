#include "matka.h"
#include "Game.h"
#include "Menu.h"
#include "Dane.h"


enum class GameState { Menu, Playing, Skills, Exiting };



int main() {

	srand(time(NULL));


	GameData GraPlik;
	GraPlik.odczyt();

	GameStatus statusGry;

	sf::Clock clock;

	MenuSkills skile;
	skile.skillsmenu(Ekran_Szerokosc, Ekran_Wysokosc);

	Menu meni;
	meni.menu(Ekran_Szerokosc, Ekran_Wysokosc);

	Game gierka;
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Super Bowl");
	GameState currentState = GameState::Menu;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				GraPlik.zapis();
				window.close();
			}
			if (currentState == GameState::Menu) { //nawigowanie po menu glownym i aktualizuje zgodnie z decyzjami uzytkownika

				if (event.type == sf::Event::KeyPressed) {

					if (event.key.code == sf::Keyboard::Num1) {
						currentState = GameState::Playing;
						gierka.obiekty();
					}

					else if (event.key.code == sf::Keyboard::Num2) {
						currentState = GameState::Skills;
					}

					else if (event.key.code == sf::Keyboard::Num3) {
						GraPlik.zapis();
						currentState = GameState::Exiting;
					}

				}

			}
			if (currentState == GameState::Skills) { //menu ulepszen i nawigowanie po nim

				if (event.type == sf::Event::KeyPressed) {

					if (event.key.code == sf::Keyboard::Num3) {
						GraPlik.zapis();
						currentState = GameState::Menu;
					}

					if (event.key.code == sf::Keyboard::Num1) {
						int AktualnePunkty = GraPlik.odczytPunkty();
						if (AktualnePunkty >= 30) {
							punkty = punkty - 30;
							PilkaSil++;
							GraPlik.zapis();
						}

						else if (AktualnePunkty < 30) { //pokazuje jezeli nie mozna ulepszyc pilki
							skile.informacja(punkty);
						}

					}

				}

			}

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::P) { //sluzy do zatrzymania gry
					graZatrzymana = !graZatrzymana;
					if (graZatrzymana) {

						sf::Vector2f PozycjaPaletki = statusGry.PaletkaPozycja(gierka.PalGracz);
						sf::Vector2f PozycjaPilki = statusGry.PilkaPozycja(gierka.PilkaWrog);
						sf::Vector2f PredkoscPilki = statusGry.PilkaPredkosc(gierka.PilkaWrog);
						sf::Vector2f PozycjaPrzeszkody = statusGry.Przeszkody(gierka.przeszkadzajka[0]);
					}

				}

			}

		}

		if (currentState == GameState::Exiting) {
			GraPlik.zapis();
			window.close();
		}

		if (currentState == GameState::Skills) {
			window.clear(sf::Color::Black);
			skile.draw(window);
		}

		if (currentState == GameState::Playing && !graZatrzymana) { //sterowanie podczas gry

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				gierka.PalGracz.ruchLewo();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				gierka.PalGracz.ruchPrawo();
			}

			if (k == 4) {
				GraPlik.zapis();
				window.close();
				std::cout << "przegrales" << std::endl;
			}

			gierka.PilkaWrog.kolision(gierka.Prost); //kolizja pilki z przeszkoda

			gierka.PilkaWrog.aktualizacja();

			gierka.PilkaWrog.kolizja(gierka.PalGracz); //kolizja z paletka
			gierka.PilkaWrog.OdbijX();
			gierka.PilkaWrog.OdbijY();

			for (auto& przeszkoda : gierka.przeszkadzajka) {//tutaj tez sprawdza stan kazdego obiektu i go aktualizuje (NISZCZY) zgodnie z jego stanem
				gierka.PilkaWrog.niszczenie(przeszkoda);
			}

		}

		if (currentState == GameState::Menu) { //wyswietlanie menu i licznika punktow
			
			meni.draw(window);
			meni.wyswietlaczPunktow(punkty);
		}

		if (currentState == GameState::Playing) { //renderowanie glownej planszy i obiektow na niej

			window.clear(sf::Color::Blue);
			gierka.Prost.draw(window);
			
			for (auto& przeszkoda : gierka.przeszkadzajka) {//sprawdza stan kazdego obiektu o nazwie przeszkoda w wekotrze, auto automatycznie okresla typ zmiennej
				przeszkoda.draw(window);
			}

			gierka.PalGracz.draw(window);
			gierka.PilkaWrog.draw(window);
		}

			window.display();

	}

		return 0;

}

