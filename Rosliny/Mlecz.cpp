#include "Mlecz.hpp"

Mlecz::Mlecz(int x, int y, int wiek) : Roslina("🌼",0,x,y,"Mlecz",wiek){
    prawdopodobienstwo = 10;
}

void Mlecz::akcja(){
    for(int i = 0; i < 3; i++){
        Roslina::akcja();
    }
}

Organizm* Mlecz::dziecko(){
    return new Mlecz(*this);
}