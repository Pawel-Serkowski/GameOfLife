#pragma once
#include "Roslina.hpp"

class Trawa : public Roslina{
public:
    Trawa(int x, int y);
    Organizm* dziecko() override;
};