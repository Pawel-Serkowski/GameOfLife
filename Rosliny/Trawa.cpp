#include "Trawa.hpp"

Trawa::Trawa(int x, int y, int wiek) : Roslina("🌱",0,x,y,"Trawa",wiek){
    prawdopodobienstwo = 50;
};

Organizm* Trawa::dziecko(){
    return new Trawa(*this);
}