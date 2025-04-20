#include "Wilk.hpp"

Wilk::Wilk(int x, int y, int sila, int wiek):Zwierze("🐺",sila,5,x,y,"Wilk",wiek){}

Organizm* Wilk::dziecko(){
    return new Wilk(*this);
}