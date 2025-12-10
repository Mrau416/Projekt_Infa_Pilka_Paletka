#include "matka.h"
#include "Dane.h"



sf::Vector2f GameStatus::PaletkaPozycja(Paletka& p) {
	float x = p.getSzerokosc();
	float y = p.getWysokosc();
	return { x, y };
}

sf::Vector2f GameStatus::PilkaPozycja(Pilka& s) {
	float pX = s.zwrotX();
	float pY = s.zwrotY();
	return{ pX,pY };
}

sf::Vector2f GameStatus::PilkaPredkosc(Pilka& v) {
	float vX = v.zwrotX();
	float vY = v.zwrotY();
	return{ vX,vY };

}

sf::Vector2f GameStatus::Przeszkody(Przeszkoda& l) {
	float prX = l.X();
	float prY = l.Y();
	return {prX,prY};



}


void GameData::zapis() {//na poczatku main oraz w kluczowych punktach, zapisuje
	
	ofstream MyFile("pilkaskills.txt");

	
	MyFile << punkty<<" "<< PilkaSil;

	
	MyFile.close();

}


void GameData::odczyt() {
	ifstream  MyFile("pilkaskills.txt");


	MyFile >> punkty >> PilkaSil;

	MyFile.close();

}



int GameData::odczytPunkty() {//sprawdza czy ilosc punktow starczy na ulepszenie
	ifstream  MyFile("pilkaskills.txt");
	int tempPunkty;
	int tempPilkSsil;

	MyFile >> tempPunkty >> tempPilkSsil;

	MyFile.close();
	return tempPunkty;
}