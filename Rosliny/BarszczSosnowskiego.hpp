#pragma once
#include "Roslina.hpp"

class BarszczSosnowskiego: public Roslina{
    const int mozliweZabojstwa[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
public:
    BarszczSosnowskiego(int x, int y, int wiek = 0);
    void akcja() override;
    void kolizja(Organizm* atakujacyOrganizm) override;
    Organizm *dziecko() override;
};