#include <iostream>
#include "Swiat.hpp"
#include <cstdlib>
#include <time.h>

int main(){
    srand(time(NULL));
    cout << "Witaj w symulatorze wirtualnego swiata\n";
    cout << "Wybierz opcje \n 1. Stworz swiat defaultowy \n 2. Stworz swiat z zapisu\n Opcja: ";
    int opcja;
    do{
        cin >> opcja;
    }while(opcja != 1 && opcja != 2);

    Swiat* swiat;
    if(opcja == 1){
        int w, h;
        cout << "Podaj szerokosc swiata (zalecana 10): ";
        cin >> w;
        cout << "Podaj wysokosc swiata (zalecana 10): ";
        cin >> h;
        swiat = Swiat::getStanSwiata(w,h);
        swiat->stworzPopulacje();
    }else{
        swiat = Swiat::getStanSwiataZPliku();
    }
    
    swiat->symulacja();

    std::cout << "\n";
}