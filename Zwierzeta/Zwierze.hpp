#pragma once 
#include "../Organizm.hpp"

class Zwierze : public Organizm{
public:
    Zwierze(std::string ikona, int sila, int inicjatywa, int x, int y,string nazwa, int wiek = 0);
    ~Zwierze() ;
    virtual void akcja() override;
    virtual void kolizja(Organizm* atakujacyOrganizm) override;
    void rozmnazanie() ;
};