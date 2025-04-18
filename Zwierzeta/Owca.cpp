#include "Owca.hpp"

Owca::Owca(int x, int y):Zwierze("🐑",4,4,x,y){};

Organizm* Owca::dziecko(){
    return new Owca(*this);
}