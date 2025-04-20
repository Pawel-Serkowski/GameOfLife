#pragma once
#include "Roslina.hpp"

class Mlecz : public Roslina{
public:
    Mlecz(int x, int y,int wiek = 0);
    void akcja() override;
    Organizm* dziecko() override;
};