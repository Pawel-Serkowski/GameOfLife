#pragma once
#include "Roslina.hpp"

class Guarana : public Roslina{
public:
    Guarana(int x, int y);
    void kolizja(Organizm *atakujacyOrganizm) override;
    Organizm* dziecko() override;
};