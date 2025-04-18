#include "Trawa.hpp"

Trawa::Trawa(int x, int y) : Roslina("🌱",0,x,y){
    prawdopodobienstwo = 50;
};

Organizm* Trawa::dziecko(){
    return new Trawa(*this);
}