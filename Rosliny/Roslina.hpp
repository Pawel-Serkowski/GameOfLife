#pragma once
#include "../Organizm.hpp"

class Roslina : public Organizm{
protected:
    int prawdopodobienstwo;
public:
    Roslina(string ikona, int sila,int x, int y,string nazwa, int wiek = 0);
    void akcja() override;
    void kolizja(Organizm *atakujacyOrganizm) override;
};