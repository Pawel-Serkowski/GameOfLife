#pragma once
#include "Zwierze.hpp"

class Lis : public Zwierze{
public:
    Lis(int x, int y);
    void akcja() override;
    Organizm* dziecko() override;
};