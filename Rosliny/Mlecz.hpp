#pragma once
#include "Roslina.hpp"

class Mlecz : public Roslina{
public:
    Mlecz(int x, int y);
    void akcja() override;
    Organizm* dziecko() override;
};