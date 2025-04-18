#pragma once
#include "Zwierze.hpp"

class Antylopa : public Zwierze{
    const int ruchy[8][2] = {{0,2},{2,0},{0,-2},{-2,0},{0,1},{1,0},{0,-1},{-1,0}};
public:
    Antylopa(int x, int y);
    void akcja() override;
    bool czyUcieczka() override;
    Organizm* dziecko() override;
};