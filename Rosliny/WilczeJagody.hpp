#pragma once
#include "Roslina.hpp"

class WilczeJagody : public Roslina{
public:
    WilczeJagody(int x, int y,int wiek = 0);
    void kolizja(Organizm *atakujacyOranizm) override;
    Organizm *dziecko() override;
};