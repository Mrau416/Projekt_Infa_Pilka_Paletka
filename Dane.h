#pragma once
#include "matka.h"


struct BlockData {
    float x, y;
    int hp;
};


class GameStatus { //klasa do pauzy
public:
    sf::Vector2f PaletkaPozycja(Paletka& p);
 

    sf::Vector2f PilkaPozycja(Pilka& s);

    sf::Vector2f PilkaPredkosc(Pilka& v);

    sf::Vector2f Przeszkody(Przeszkoda& l);


};


class GameData { //klasa do zapisu
public:
    void zapis();
    void odczyt();
    int odczytPunkty();
};
