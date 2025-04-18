#pragma once
#include "Zwierze.hpp"

class Wilk : public Zwierze{
public:
    Wilk(int x, int y);
    Organizm* dziecko() override;
};
