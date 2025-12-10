#include "matka.h"

void Paletka::PaPocz(float pocz_x, float pocz_y, float szer_p, float wys_p, float v_p) { //funckja tworzaca paletke
	x = pocz_x;
	y = pocz_y;
	szerokosc = szer_p;
	wysokosc = wys_p;
	predkosc = v_p;
	shape.setSize(sf::Vector2f(szerokosc, wysokosc));
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color(234, 54, 128));
}
void Paletka::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

float Paletka::getWysokosc() {
	return wysokosc;
}

float Paletka::getSzerokosc() {
	return szerokosc;
}

float Paletka::PozycjaX() {
	return x;
}


float Paletka::PozycjaY() {
	return y;
}


void Paletka::ruchLewo() {
	x = x - predkosc;
	shape.setPosition(x, y);
}
void Paletka::ruchPrawo() {
	x = x + predkosc;
	shape.setPosition(x, y);
}