#include "Owca.hpp"

Owca::Owca(int x, int y, int sila, int wiek):Zwierze("🐑",4,4,x,y,"Owca",wiek){};

Organizm* Owca::dziecko(){
    return new Owca(*this);
}