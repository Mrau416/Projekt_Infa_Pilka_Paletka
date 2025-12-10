#pragma once

#include "matka.h"







class Pilka {
private:
	sf::CircleShape shape;
	sf::Vector2f velocity{ 200.f,200.f };
	float x, y; // pozycja œrodka,
	float vx, vy; //prêdkoœci,
	float radius;// promieñ,
	int sila;
public:
	void Ustaw(float pocz_x, float pocz_y, float vx_p, float vy_p, float promien, int sila_p);
	void draw(sf::RenderWindow& window);
	void aktualizacja();
	void Prawo();
	void Lewo();
	void OdbijX();
	void OdbijY();
	void kolizja(Paletka p);
	void kolision(Smierc s);
	void niszczenie(Przeszkoda& p);
	float zwrotX();
	float zwrotY();
	float zwrotVx();
	float zwrotVy();
};
 



