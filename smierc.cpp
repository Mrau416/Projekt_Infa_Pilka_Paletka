#include "matka.h"

void Smierc::prost_death(float x_pocz, float y_pocz, float szer_p, float dl_p) {
	x = x_pocz;
	y = y_pocz;
	szerokosc = szer_p;
	dlugosc = dl_p;
	shape.setSize(sf::Vector2f(szerokosc, dlugosc));
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Yellow);
}
void Smierc::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

float Smierc::wezX() {
	return x;
}

float Smierc::wezY() {
	return y;
}

float Smierc::wezSzerokosc() {
	return szerokosc;
}

float Smierc::wezDlugosc() {
	return dlugosc;
}
