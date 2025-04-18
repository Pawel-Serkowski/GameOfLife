#include "Organizm.hpp"
#include <string>

Organizm::Organizm(int x, int y, string ikona, int sila, int inicjatywa){
    this->polozenie.x = x;
    this->polozenie.y = y;
    this->ikona = ikona;
    this->sila = sila;
    this->inicjatywa = inicjatywa;
    this->dlugoscZycia = 0;
    this->swiatRef = Swiat::getStanSwiata();
    czyZyje = true;

    Organizm* temp = swiatRef->getOrganizm(polozenie.x, polozenie.y);
    swiatRef->dodajOrganizm(this);
    if(temp != nullptr){
        swiatRef->dodajLog(this, "nie moze zostac wygenerowane, poniewaz inne zwierze zajmuje ten teren");
        zabij();
    }
}

Organizm::Organizm(const Organizm& copy){
    this->polozenie.x = copy.polozenie.x;
    this->polozenie.y = copy.polozenie.y;
    this->ikona = copy.ikona;
    this->sila = copy.sila;
    this->inicjatywa = copy.inicjatywa;
    this->dlugoscZycia = copy.dlugoscZycia;
    this->swiatRef = copy.swiatRef;
    this->czyZyje = copy.czyZyje;
    swiatRef->dodajOrganizm(this);
}


int Organizm::getX() const{
    return polozenie.x;
}


int Organizm::getY() const{
    return polozenie.y;
}


// char Organizm::getIcon() const{
//     return ikona;
// }


int Organizm::getSila() const{
    return sila;
}


int Organizm::getInicjatywa() const{
    return inicjatywa;
}


int Organizm::getDlugoscZycia() const{
    return dlugoscZycia;
}

void Organizm::addDlugoscZycia(){
    dlugoscZycia++;
}

bool Organizm::getCzyZyje(){
    return czyZyje;
}

//zwraca, czy zmiana polozenia byla wykonana
bool Organizm::setPolozenie(Polozenie_t nowePolozenie, bool czyPuste){ 

    // swiatRef->dodajLog(this, "udalo sie zasiac nowa roslinke");

    if(czyZyje ==false){
        this->polozenie.x = nowePolozenie.x;
        this->polozenie.y = nowePolozenie.y;
        return true;
    }

    //warunek, zeby nie wyszedl za ekran
    if(nowePolozenie.x >= swiatRef->getSzerokosc() || nowePolozenie.x < 0 || nowePolozenie.y >= swiatRef->getWysokosc() || nowePolozenie.y < 0){
        return false;
    }

    if(czyPuste && swiatRef->getOrganizm(nowePolozenie.x,nowePolozenie.y) != nullptr){
        return false;
    }

    poprzedniePolozenie = this->polozenie;
    Organizm* tempOrg = swiatRef->getOrganizm(nowePolozenie.x,nowePolozenie.y);
    this->polozenie = nowePolozenie;

    string log = "zmienił połozenie z (" + to_string(this->poprzedniePolozenie.x) + ";" + to_string(this->poprzedniePolozenie.y) + ")" + " na ("+ to_string(this->polozenie.x) + ";" + to_string(this->polozenie.y) + ")";
    swiatRef->dodajLog(this, log);

    if(tempOrg !=nullptr){
        tempOrg->kolizja(this);
    }

    return true;

}

void Organizm::rysowanie() const{
    cout<<"\033["<<polozenie.y + 2<<";"<<2*polozenie.x+ 2<<"H";
    cout << ikona;
}

void Organizm::zabij(){
    czyZyje = false;
    setPolozenie({-1,-1});
    swiatRef->odejmijOrganizm();
}

string Organizm::toString(){
    string log = "";
    log = ikona + " (s:"+ to_string(sila)+ ";i:"+to_string(inicjatywa)+";w:"
    +to_string(this->getDlugoscZycia()) + ")";
    return log;
}

Polozenie_t Organizm::getPoprzedniePolozenie(){
    return poprzedniePolozenie;
}

bool Organizm::czyUcieczka(){
    return false;
}

void Organizm::setSila(int sila){
    this->sila = sila;
}