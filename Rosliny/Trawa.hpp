#pragma once
#include "Roslina.hpp"

class Trawa : public Roslina{
public:
    Trawa(int x, int y, int wiek = 0);
    Organizm* dziecko() override;
};