#include "Swiat.hpp"

#include "Zwierzeta/Wilk.hpp"
#include "Zwierzeta/Owca.hpp"
#include "Zwierzeta/Lis.hpp"
#include "Zwierzeta/Zolw.hpp"
#include "Zwierzeta/Antylopa.hpp"

#include "Rosliny/Trawa.hpp"
#include "Rosliny/Mlecz.hpp"
#include "Rosliny/Guarana.hpp"
#include "Rosliny/WilczeJagody.hpp"
#include "Rosliny/BarszczSosnowskiego.hpp"

#include "Czlowiek/Czlowiek.hpp"

Swiat::Swiat(int szerokosc, int wysokosc){
    rozmiarRamki = 1;
    nrLog = 0;
    logiSymulacji = "";
    iloscZwierzat = 0;

    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;

}

void Swiat::stworzPopulacje(){
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);

    new Trawa(rand() % szerokosc, rand() % wysokosc);
    new Trawa(rand() % szerokosc, rand() % wysokosc);
    new Mlecz(rand() % szerokosc, rand() % wysokosc);
    new Mlecz(rand() % szerokosc, rand() % wysokosc);
    new Guarana(rand() % szerokosc, rand() % wysokosc);
    new Guarana(rand() % szerokosc, rand() % wysokosc);
    new WilczeJagody(rand()%szerokosc, rand()%wysokosc);
    new BarszczSosnowskiego(rand()%szerokosc, rand()%wysokosc);

    new Czlowiek(rand() % szerokosc, rand() % wysokosc);
}

Swiat* Swiat::getStanSwiata(){
    return stanSwiata;
}

Swiat* Swiat::getStanSwiata(int szerokosc, int wysokosc){
    if(stanSwiata != nullptr){
        delete stanSwiata;
    }

    stanSwiata = new Swiat(szerokosc,wysokosc);
    return stanSwiata;
}

Swiat* Swiat::stanSwiata = nullptr;

void Swiat::dodajOrganizm(Organizm* organizm){
    if(iloscZwierzat == szerokosc * wysokosc){
        dodajLog(organizm,"nie udalo sie dodac przez zbyt duza liczebnosc organizmow");
        organizm->zabij();
        return;
    }
    organizmy.push_front(unique_ptr<Organizm>(organizm));
    iloscZwierzat++;
}

int Swiat::getSzerokosc(){
    return szerokosc;
}

int Swiat::getWysokosc(){
    return wysokosc;
}

void Swiat::rysujLogi(){
    cout<<"\033["<< wysokosc + 4 <<";"<<0<<"H";
    cout << "------Logi symulacji | Tura " << to_string(tura) << "------" << "\n";
    cout << logiSymulacji;
    logiSymulacji="";
    nrLog=0;
}

void Swiat::rysujRamke(){
    cout<<"\033["<<0<<";"<<0<<"H";
    cout << "+";
    for(int i = 1; i < szerokosc*2+1;i++){
        cout << "=";
    }
    cout << "+";
    for(int h = 2; h < wysokosc+2; h++){
        cout<<"\033["<<h<<";"<<0<<"H";
        cout << "|";
        cout<<"\033["<<h<<";"<<2*szerokosc+2<<"H";
        cout << "|";
    }
    cout << "\n+";
    for(int i = 1; i < szerokosc*2+1;i++){
        cout << "=";
    }
    cout << "+";
}

void Swiat::rysujSwiat(){
    cout << "\033c";
    
    for(const auto& organizm : organizmy){
        organizm->rysowanie();
    }

    rysujRamke();
    rysujLogi();
}

void Swiat::wykonajTure(){
    posortujKolejnosc();
    for(const auto& organizm : organizmy){
        if(organizm != nullptr && organizm->getCzyZyje() && organizm->getX()!= -1){
            organizm->addDlugoscZycia();
            organizm->akcja();
        }
    }
    usunNiezyjaceOrganizmy();
    tura++;
}

void Swiat::symulacja(){
    rysujSwiat();
    getchar();
    for(int i = 0; i < 30; i++){
        wykonajTure();
        rysujSwiat();
        getchar();
    }
}

Organizm* Swiat::getOrganizm(int x, int y){
    for(const auto& organizm : organizmy){
        if(organizm->getX() == x && organizm->getY() == y && organizm->getCzyZyje() == true){
            return organizm.get();
        }
    }
    return nullptr;
}

void Swiat::usunNiezyjaceOrganizmy(){
    organizmy.remove_if([&](const unique_ptr<Organizm>& ptr) {
        return ptr.get()->getCzyZyje() == false || ptr == nullptr;
    });
}

void Swiat::dodajLog(Organizm* org,  string log){
    logiSymulacji += to_string(++nrLog) + ". "+ org->toString() +" "+ log + "\n";
}

void Swiat::posortujKolejnosc(){
    organizmy.sort([](const std::unique_ptr<Organizm>& a, const std::unique_ptr<Organizm>& b) {
        if(a->getInicjatywa() == b->getInicjatywa()){
            return a->getDlugoscZycia() < b->getDlugoscZycia();
        }
        return a->getInicjatywa() > b->getInicjatywa();  
    });
}

void Swiat::odejmijOrganizm(){
    iloscZwierzat--;
}

Swiat::~Swiat(){
    organizmy.clear();
}