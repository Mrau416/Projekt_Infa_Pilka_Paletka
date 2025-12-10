#pragma once

#include "matka.h"

class Menu { //menu
public:
	void menu(int szer, int wys);
	void draw(sf::RenderWindow& window);
	void wyswietlaczPunktow(int Punkty);
	sf::RectangleShape shape;

	sf::Font font;
	sf::Text PunktyText;
	sf::Text infoText;
	sf::Text skillsText;
	sf::Text grajText;  
	sf::Text wyjscieText;

};


class MenuSkills { //menu do rozwoju pilki
public:
	void skillsmenu(int szer, int wys);
	void draw(sf::RenderWindow& window);
	void informacja(int Points);
	sf::RectangleShape shape;

	sf::Font font;

	sf::Text Punktowy;
	sf::Text informacyjny;
	sf::Text umiejetnosci;
	sf::Text powrot;
};
