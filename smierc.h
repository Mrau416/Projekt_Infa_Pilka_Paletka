#pragma once

#include "matka.h"







class Smierc { //klasa zwiazana z prostokatem na samym dole
private:
	sf::RectangleShape shape;
	float x;
	float y;
	float dlugosc, szerokosc;
public:
	void prost_death(float x_pocz, float y_pocz, float szer_p, float dl_p);
	void draw(sf::RenderWindow& window);
	float wezX();
	float wezY();
	float wezSzerokosc();
	float wezDlugosc();
};

