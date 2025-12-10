#include "matka.h"


void Przeszkoda::przeszkoda_tworz(float x_pol, float y_pol, float szer_prost, float dl_prost) {
	x = x_pol;
	y = y_pol;
	szerokosc = szer_prost;
	dlugosc = dl_prost;
	shape.setSize(sf::Vector2f(szerokosc, dlugosc));
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Yellow);
}
void Przeszkoda::draw(sf::RenderWindow& window) {
	if (z > 0) {
		window.draw(shape);
	}
}


int Przeszkoda::zycia() {
	return z;
}

void Przeszkoda::zniszczenia() { //aktualizacja stanu

	if (z == 3) {
		shape.setFillColor(sf::Color::Yellow);
	}
	if (z == 2) {
		shape.setFillColor(sf::Color(255, 127, 39));
	}
	if (z == 1) {
		shape.setFillColor(sf::Color::Red);
	}
}

float Przeszkoda::X() {
	return x;
}

float Przeszkoda::Y() {
	return y;
}

float Przeszkoda::Szerokosc() {
	return szerokosc;
}

float Przeszkoda::Dlugosc() {
	return dlugosc;
}