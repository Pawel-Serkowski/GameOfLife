#pragma once
#include "Zwierze.hpp"

class Zolw : public Zwierze{
    public:
        Zolw(int x, int y);
        void akcja() override;
        void kolizja(Organizm* atakujacyOrganizm) override;
        Organizm* dziecko() override;
};