#pragma once
#include "Zwierze.hpp"

class Owca : public Zwierze{
public:
    Owca(int x, int y, int sila = 4, int wiek = 0);
    Organizm* dziecko() override;
};