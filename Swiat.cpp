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

    czyLegendaPokazana = true;
    czyLogiPokazane = true;

}

void Swiat::stworzPopulacje(){
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

    new Czlowiek(rand()%szerokosc, rand()%wysokosc);
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

int Swiat::getTura(){
    return this->tura;
}

void Swiat::setTura(int tura){
    this->tura = tura;
}



void Swiat::rysujLogi(){
    cout<<"\033["<< wysokosc + 4 <<";"<<0<<"H";
    cout << "------Logi symulacji | Tura " << to_string(tura) << "------" << "\n";
    cout << logiSymulacji;

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

void Swiat::rysujLegende(){
    int x = 2*szerokosc+8;
    int y = 2;
    string legenda[12];
    legenda[0] = "---Legenda---";
    legenda[1] = "🦌 - Antylopa";
    legenda[2] = "🦊 - Lis";
    legenda[3] = "🐑 - Owca";
    legenda[4] = "🐺 - Wilk";
    legenda[5] = "🐢 - Zolw";
    legenda[6] = "🤠 - Czlowiek";
    legenda[7] = "🍄 - Barszcz Sosnowskiego";
    legenda[8] = "🌺 - Guarana";
    legenda[9] = "🌼 - Mlecz";
    legenda[10] = "🌱 - Trawa";
    legenda[11] = "🫐 - Wilcze Jagody";


    for(int i = 0; i < 7;i++){
        cout<<"\033["<<y+i<<";"<<x<<"H";
        cout << legenda[i];
    }
    x += 15;
    for(int i = 0; i < 6;i++){
        cout<<"\033["<<y+1+i<<";"<<x<<"H";
        cout << legenda[7 + i];
    }
}

void Swiat::rysujSwiat(){
    cout << "\033c";
    
    for(const auto& organizm : organizmy){
        organizm->rysowanie();
    }

    if(czyLegendaPokazana)rysujLegende();
    rysujRamke();
    if(czyLogiPokazane)rysujLogi();

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
    czySymulacjaDziala = true;
    rysujSwiat();
    cout << "Rozpocznij symulacje klikając k\n";
    while(getZnakZKlawiatury() != 'k');
    char znak;
    while(czySymulacjaDziala){
        if(!czyLogiPokazane) cout << "\033["<<wysokosc+4 << ";"<<0<<"H";
        cout << "--------MENU--------\n";
        cout << "Kliknij opcje w turze: \n ENTER -> przejdz dalej \n 's' - zapisz stan swiata \n 'q' - zakoncz symulacje\n 'l' - pokaz logi symulacji \n 'i' - pokaz legende symulacji\n";
        cout << "--------------------\n";
        znak = getZnakZKlawiatury();
        switch(znak){
            case 's':
                zapiszStanSwiata();
                break;
            case 'i':
                
                czyLegendaPokazana = !czyLegendaPokazana;
                rysujSwiat();
                break;
            case 'l':
                czyLogiPokazane = !czyLogiPokazane;
                rysujSwiat();
                break;
            case 'q':
                czySymulacjaDziala = false;
                break;
            default:
                wykonajTure();
                rysujSwiat();
                logiSymulacji="";
                nrLog=0;
        }
        
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

void Swiat::zapiszStanSwiata(){
    string nazwaPliku;
    cout << "Podaj nazwe pliku i rozszerzenie do ktorego chcesz zapisac stan swiata\n Nazwa pliku: ";
    cin >> nazwaPliku;

    fstream plik;
    plik.open(nazwaPliku,ios::out);
    if(plik.good()){
        cout << "Plik pomyślnie utworzony :) \n";
    }
    plik << this->szerokosc << " " <<  this->wysokosc  << " " << getTura()<< endl;

    for(const auto& organizm : organizmy){
        if(organizm->getInicjatywa() == 0){
            plik << organizm->getNazwa() << " ";
            plik << organizm->getX()<< " ";
            plik << organizm->getY()<< " ";
            plik << organizm->getDlugoscZycia();
        }else if(organizm->getNazwa() == "Czlowiek") {
            plik << organizm->getNazwa()<< " ";
            plik << organizm->getX()<< " ";
            plik << organizm->getY()<< " ";
            plik << organizm->getSila()<< " ";
            plik << organizm->getCzyUmiejetnoscWlanczona()<< " ";
            plik << organizm->getLicznikUmiejetnosci()<< " ";
            plik << organizm->getDlugoscZycia();
        }else{
            plik << organizm->getNazwa()<< " ";
            plik << organizm->getX()<< " ";
            plik << organizm->getY()<< " ";
            plik << organizm->getSila()<< " ";
            plik << organizm->getDlugoscZycia();
        }
        plik << endl;
    }
    plik.close();

    cout << "kliknij 'k' aby kontynuowac\n";
    while(getZnakZKlawiatury() != 'k'); 
}


Swiat* Swiat::getStanSwiataZPliku(){
    string tempNazwaPliku;
    bool czyPlikPoprawny = false;
    fstream plikZSwiatem;

    if(stanSwiata){
        delete stanSwiata;
        stanSwiata = nullptr;
    } 

    do{
        cout << " -- Wpisz nazwe pliku, z ktorego chcesz wziac stan swiata --  \n Nazwa pliku: ";
        cin >> tempNazwaPliku;
        plikZSwiatem.open(tempNazwaPliku);
        if(plikZSwiatem.good())czyPlikPoprawny = true;
        else cout << "Nie istnieje taki plik! \n";        
    }while(!czyPlikPoprawny);

    int w,h,t;
    plikZSwiatem >> w >> h >> t;
    stanSwiata = new Swiat(w,h);

    stanSwiata->setTura(t);
    string nazwa;
    int x,y,sila,wiek;  

    while(plikZSwiatem >> nazwa){
        stworzZwierzeZPliku(nazwa, &plikZSwiatem);
    }

    return stanSwiata;
}

void Swiat::stworzZwierzeZPliku(string nazwa, fstream *plik){
    int x,y,sila,wiek,licznikUmiejetnosci;
    bool czyUmiejetnoscWlaczona;
    if(nazwa == "Wilk"){
        *plik >> x >> y >> sila >> wiek;
        new Wilk(x,y,sila,wiek);
    }else if(nazwa == "Owca"){
        *plik >> x >> y >> sila >> wiek;
        new Owca(x,y,sila,wiek);
    }else if(nazwa == "Antylopa"){
        *plik >> x >> y >> sila >> wiek;
        new Antylopa(x,y,sila,wiek);
    }else if(nazwa == "Lis"){
        *plik >> x >> y >> sila >> wiek;
        new Lis(x,y,sila,wiek);
    }else if(nazwa == "Zolw"){
        *plik >> x >> y >> sila >> wiek;
        new Zolw(x,y,sila,wiek);
    }else if(nazwa == "BarszczSosnowskiego"){
        *plik >> x >> y  >> wiek;
        new BarszczSosnowskiego(x,y,wiek);
    }else if(nazwa == "Guarana"){
        *plik >> x >> y  >> wiek;
        new Guarana(x,y,wiek);
    }else if(nazwa == "Mlecz"){
        *plik >> x >> y  >> wiek;
        new Mlecz(x,y,wiek);
    }else if(nazwa == "Trawa"){
        *plik >> x >> y  >> wiek;
        new Trawa(x,y,wiek);
    }else if(nazwa == "WilczeJagody"){
        *plik >> x >> y  >> wiek;
        new WilczeJagody(x,y,wiek);
    }else if(nazwa == "Czlowiek"){
        *plik >> x >> y >> sila >>  czyUmiejetnoscWlaczona >> licznikUmiejetnosci  >> wiek;
        new Czlowiek(x,y,sila,czyUmiejetnoscWlaczona,licznikUmiejetnosci,wiek);
    }
    else{
        cout << "Nie mozna dodac zwierzecia: " + nazwa + "\nponiewaz nie wystepuje w symulacji taki gatunek \n";
    }
}

char Swiat::getZnakZKlawiatury(){
    termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);         // Zapisz bieżące ustawienia terminala
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);       // Wyłącz tryb kanoniczny i echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Ustaw nowe ustawienia

    ch = getchar();                         // Odczytaj znak

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Przywróć stare ustawienia

    return ch;
}
