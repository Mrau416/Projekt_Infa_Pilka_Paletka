#include "matka.h"

void Pilka::Ustaw(float pocz_x, float pocz_y, float vx_p, float vy_p, float promien, int sila_p) {
	x = pocz_x;
	y = pocz_y;
	vx = vx_p;
	vy = vy_p;
	radius = promien;
	sila = sila_p;
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::White);
	shape.setPosition(x, y);
}
void Pilka::draw(sf::RenderWindow& window) {
	window.draw(shape);
}




float Pilka::zwrotX() {
	return x;
}
float Pilka::zwrotY() {
	return y;
}
float Pilka::zwrotVx() {
	return vx;
}
float Pilka::zwrotVy() {
	return vy;
}




void Pilka::niszczenie(Przeszkoda& p) {
	if (p.zycia() > 0) {
		if (x >= p.X() - p.Szerokosc()/10 && x <= p.X() + p.Szerokosc() && y + radius >= p.Y() && y + radius <= p.Y() + p.Dlugosc()) {//DZIELE NA 10 BO X KTOREGO PRZECHWYTUJE NIE JEST ANI NA SRODKU ANI NA BOKU, U PALETKI TO SAMO
			vy = -vy;
			p.z=p.z-(1+PilkaSil);
			punkty++;
			p.zniszczenia();
		}
		
	}
}

void Pilka::aktualizacja() {
	x += vx;
	y += vy;
	shape.setPosition(x, y);
}

void Pilka::Prawo() {
	x = x + vx;
}
void Pilka::Lewo() {
	x = x - vx;
}

void Pilka::kolizja(Paletka p) {
	if (x >= p.PozycjaX() - (p.getSzerokosc()/10) && x <= (p.PozycjaX() + p.getSzerokosc()) && (y + radius) >= p.PozycjaY() && (y + radius) <= p.PozycjaY() + p.getWysokosc()) {
		vy = -vy;
	}
	
}

void Pilka::OdbijX() {
	if (vx < 0) {
		if (x <= radius) {
			vx = -vx;
		}
	}
	if (vx > 0) {
		if (x >= Ekran_Szerokosc - radius) {
			vx = -vx;
		}
	}
}
void Pilka::OdbijY() {
	if (vy < 0) {
		if (y <= radius) {
			vy = -vy;
		}
	}
	if (vy > 0) {
		if (y >= Ekran_Wysokosc - radius) {
			vy = -vy;
		}
	}
}

void Pilka::kolision(Smierc s) {
	if (x >= s.wezX() - s.wezSzerokosc() && x <= abs(s.wezX() + s.wezSzerokosc()) && abs(y + radius) >= s.wezY() && abs(y + radius) <= s.wezY() + s.wezDlugosc()) {
		k = 4;
	}
}