#pragma once
#include "Zwierze.hpp"

class Lis : public Zwierze{
public:
    Lis(int x, int y, int sila = 3, int wiek = 0);
    void akcja() override;
    Organizm* dziecko() override;
};