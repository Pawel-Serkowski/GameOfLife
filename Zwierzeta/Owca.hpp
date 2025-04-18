#pragma once
#include "Zwierze.hpp"

class Owca : public Zwierze{
public:
    Owca(int x, int y);
    Organizm* dziecko() override;
};