#include "Wilk.hpp"

Wilk::Wilk(int x, int y):Zwierze("🐺",9,5,x,y){}

Organizm* Wilk::dziecko(){
    return new Wilk(*this);
}