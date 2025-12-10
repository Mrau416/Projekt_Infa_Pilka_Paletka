#include "Game.h"
#include "matka.h"

void Game::obiekty() {
	przeszkadzajka.clear();
	int min_wierszy = 1;
	int max_wierszy = 5;
	int liczba_kolumn = 4;

	float PoczX = 30.0f;
	float PoczY = 30.0f;

	float odstepX = 110.0f; 
	float odstepY = 50.0f;
	float przeszkodaSzerokosc = 100.0f;
	float przeszkodaDlugosc = 20.0f;
	int aktualnaLiczbaWierszy = rand() % (max_wierszy - min_wierszy + 1) + min_wierszy;//losowanie z zakresu od 1 do 5

	for (int i = 0; i < liczba_kolumn; i++) {
		for (int y = 0; y < aktualnaLiczbaWierszy; y++) {

			float PozycjaX = PoczX + i * (przeszkodaSzerokosc + odstepX);
			float PozycjaY = PoczY + y * (przeszkodaDlugosc + odstepY);
			Przeszkoda nowaPrzeszkoda;

			
			nowaPrzeszkoda.przeszkoda_tworz(PozycjaX, PozycjaY, przeszkodaSzerokosc, przeszkodaDlugosc);
			nowaPrzeszkoda.z = 3;
			nowaPrzeszkoda.zniszczenia();

			
			przeszkadzajka.push_back(nowaPrzeszkoda);
		}
	}

	Prost.prost_death(0.f, 590.f, 800.f, 20.f);


	PalGracz.PaPocz(Ekran_Szerokosc / 2 - 50, Ekran_Wysokosc - 50, 100.0f, 20.0f, 0.1f);


	PilkaWrog.Ustaw(Ekran_Szerokosc / 2 + 25, Ekran_Wysokosc / 2 - 100, 0.05, 0.05, 10.f,  1);	
};

