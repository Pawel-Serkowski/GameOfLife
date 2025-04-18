#include "Lis.hpp"

Lis::Lis(int x, int y):Zwierze("🦊",3,7,x,y){};

void Lis::akcja(){
    int ruch = rand()%4;

    for(int i = 0; i < 4; i++){
        int x = polozenie.x + mozliweRuchy[(ruch+i)%4][0];
        int y = polozenie.y + mozliweRuchy[(ruch+i)%4][1];
        Organizm* org = swiatRef->getOrganizm(x,y);
        if(org == nullptr || (org != nullptr && this->getSila() >= org->getSila())){
            setPolozenie({x,y});
            return;
        }
    }
    swiatRef->dodajLog(this,"nie wywachal nowego miejsca");
}

Organizm* Lis::dziecko(){
    return new Lis(*this);
}