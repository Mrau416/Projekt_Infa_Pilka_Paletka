#include "matka.h"
#include "Menu.h"


void Menu::wyswietlaczPunktow(int Punkty) {
    string WartoscPunktow = "Twoje Punkty: " + to_string(Punkty);//konwersja int na string
    PunktyText.setString(WartoscPunktow);
}



void Menu::menu(int szer, int wys) { //stylistyka menu glownego i teksty w nim
	Ekran_Szerokosc = szer;
	Ekran_Wysokosc = wys;

    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    infoText.setFont(font);
    infoText.setString("Kliknij 1, by grac, 2, aby ulepszyc pilke lub 3, by wyjsc");
    infoText.setCharacterSize(30);
    infoText.setFillColor(sf::Color::Yellow);

    infoText.setPosition(35.f, 20.f);

    grajText.setFont(font);
    grajText.setString("1.Graj");
    grajText.setCharacterSize(50);
    grajText.setFillColor(sf::Color::Yellow);

    

    
    grajText.setPosition(320.f, 200.f);
   




    skillsText.setFont(font);
    skillsText.setString("2.Ulepszenia");
    skillsText.setCharacterSize(50);
    skillsText.setFillColor(sf::Color::Yellow);


    skillsText.setPosition(260.f, 275.f);



    wyjscieText.setFont(font);
    wyjscieText.setString("3.Wyjdz");
    wyjscieText.setCharacterSize(50);
    wyjscieText.setFillColor(sf::Color::Yellow);

    
    wyjscieText.setPosition(310.f, 350.f);
    

    PunktyText.setFont(font);
    PunktyText.setCharacterSize(25);
    PunktyText.setFillColor(sf::Color::Red);
    PunktyText.setPosition(500.f, 540.f);


	shape.setSize(sf::Vector2f(szer, wys));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(0.f, 0.f);
}






void Menu::draw(sf::RenderWindow& window) {
	window.draw(shape);
    window.draw(skillsText);
    window.draw(grajText);
    window.draw(wyjscieText);
    window.draw(infoText);
    window.draw(PunktyText);
}



void MenuSkills::informacja(int Punkty) {
    string WartoscPunktow = "Brakuje ci: " + to_string(30-Punkty);//konwersja int na string
    Punktowy.setString(WartoscPunktow);
}

void MenuSkills::skillsmenu(int szer, int wys) { //wyglad menu rozwoju pilki i tekst w nim

    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");



    Punktowy.setFont(font);
    Punktowy.setCharacterSize(25);
    Punktowy.setFillColor(sf::Color::Green);
    Punktowy.setPosition(600.f, 540.f);


    informacyjny.setFont(font);
    informacyjny.setString("Kliknij 1, aby ulepszyc pilke");
    informacyjny.setCharacterSize(50);
    informacyjny.setFillColor(sf::Color::Red);

    informacyjny.setPosition(100.f, 40.f);

    
    umiejetnosci.setFont(font);
    umiejetnosci.setString("1.Zwieksz sile- 30pkt");
    umiejetnosci.setCharacterSize(50);
    umiejetnosci.setFillColor(sf::Color::Red);


    umiejetnosci.setPosition(160.f, 300.f);


    powrot.setFont(font);
    powrot.setString("3.Wroc do menu");
    powrot.setCharacterSize(50);
    powrot.setFillColor(sf::Color::Red);


    powrot.setPosition(210.f, 500.f);


}
void MenuSkills::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(informacyjny);
    window.draw(umiejetnosci);
    window.draw(powrot);
    window.draw(Punktowy);
}