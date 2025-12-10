#pragma once
#include "matka.h"







class Paletka {
private:
	float x; // wspó³rzêdna œrodka w osi X,
	float y; //wspó³rzêdna œrodka w osi Y,
	float szerokosc; //d³ugoœæ paletki w pikselach,
	float wysokosc; // gruboœæ paletki,
	float predkosc; // ile pikseli paletka przesuwa siê na jedn¹ klatkê,
	int hp; //zycia paletki
	sf::RectangleShape shape; // prostok¹t SFML rysuj¹cy paletkê.
public:
	void PaPocz(float pocz_x, float pocz_y, float szer_p, float wys_p, float v_p);
	void draw(sf::RenderWindow& window);
	void ruchLewo();
	void ruchPrawo();
	float PozycjaX();
	float PozycjaY();
	float getSzerokosc();
	float getWysokosc();
};
