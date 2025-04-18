#pragma once
#include "Roslina.hpp"

class WilczeJagody : public Roslina{
public:
    WilczeJagody(int x, int y);
    void kolizja(Organizm *atakujacyOranizm) override;
    Organizm *dziecko() override;
};