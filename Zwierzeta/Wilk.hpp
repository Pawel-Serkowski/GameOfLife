#pragma once
#include "Zwierze.hpp"

class Wilk : public Zwierze{
public:
    Wilk(int x, int y, int sila = 9, int wiek = 0);
    Organizm* dziecko() override;
};
