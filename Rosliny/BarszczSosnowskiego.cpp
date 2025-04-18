#include "BarszczSosnowskiego.hpp"
#include "../Zwierzeta/Zwierze.hpp"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y):Roslina("🍄",10,x,y){
    prawdopodobienstwo=10;
}

void BarszczSosnowskiego::akcja(){
    for(int i = 0; i < 8;i++){
        auto sasiad = swiatRef->getOrganizm(mozliweZabojstwa[i][0],mozliweZabojstwa[i][1]);
        if(sasiad != nullptr){
            bool isZwierze = dynamic_cast<Zwierze*>(sasiad);
            if(isZwierze){
                swiatRef->dodajLog(this,"zatruł "+sasiad->toString());
                sasiad->zabij();
            }
        }
    }
    Roslina::akcja();
}

void BarszczSosnowskiego::kolizja(Organizm *atakujacyOrganizm){
    swiatRef->dodajLog(this,"zatruł "+atakujacyOrganizm->toString());
    atakujacyOrganizm->zabij();
}

Organizm* BarszczSosnowskiego::dziecko(){
    return new BarszczSosnowskiego(*this);
}