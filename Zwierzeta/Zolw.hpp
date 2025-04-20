#pragma once
#include "Zwierze.hpp"

class Zolw : public Zwierze{
    public:
        Zolw(int x, int y, int sila = 2, int wiek = 0);
        void akcja() override;
        void kolizja(Organizm* atakujacyOrganizm) override;
        Organizm* dziecko() override;
};