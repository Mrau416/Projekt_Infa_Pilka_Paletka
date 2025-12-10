#pragma once

#include "matka.h"








class Przeszkoda {
private:
	sf::RectangleShape shape;
	float x; //polozenie x
	float y; //polozenie y
	float dlugosc, szerokosc; 
public:
	void przeszkoda_tworz(float x_pol, float y_pol, float szer_prost, float dl_prost);
	void draw(sf::RenderWindow& window);
	int z = 3;
	float X();
	float Y();
	float Szerokosc();
	float Dlugosc();
	void zniszczenia();
	int zycia();
	
};

