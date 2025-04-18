#include <termios.h>
#include <unistd.h>
#include <iostream>

#include "Czlowiek.hpp"



Czlowiek::Czlowiek(int x, int y) : Organizm(x,y,"🤠",5,4){
    licznikUmiejetnosci = 5;
    czyUmiejetnoscWlaczona = false;
}

void Czlowiek::akcja(){
    if(czyUmiejetnoscWlaczona && licznikUmiejetnosci > 0){
        licznikUmiejetnosci--;
        if(licznikUmiejetnosci == 0){
            czyUmiejetnoscWlaczona = false;
        }
    }

    if(!czyUmiejetnoscWlaczona && licznikUmiejetnosci < 5){
        licznikUmiejetnosci++;
    }

    int x = 0;
    int y = 0;
    bool czyRuch = false;
    
    do{
        std::cout << "Wykonaj ruch czlowiekem (strzalkami) | p - umiejetnosc" << "\n";
        char kierunek = getZnakZKlawiatury();
        if (kierunek == 27) {
            if (getZnakZKlawiatury() == '[') {
                switch (getZnakZKlawiatury()) {
                    case 'A': x = 0;y = -1; czyRuch = true; break;
                    case 'B': x = 0;y = 1; czyRuch = true;break;
                    case 'C': x = 1;y = 0; czyRuch = true;break;
                    case 'D': x = -1;y = 0; czyRuch = true;break;
                }
            }     
        } else if(kierunek == 112){
            if(licznikUmiejetnosci == 5 && czyUmiejetnoscWlaczona == false){
                cout<<"Umiejetnosc zostala wlaczona" << "\n";
                swiatRef->dodajLog(this, "uzywa umiejetnosci");
                czyUmiejetnoscWlaczona = true;
            }else{
                if(czyUmiejetnoscWlaczona == true) cout << "Twoja umiejetnosc jest juz wlaczona" << "\n";
                if(czyUmiejetnoscWlaczona == false && licznikUmiejetnosci < 5) cout << "Umiejetnosc bedzie dostepna za: "<< 5 - licznikUmiejetnosci << " tur" << "\n";
            }   
        }
    }while(!czyRuch || !setPolozenie({getX()+x,getY()+y}));
}

void Czlowiek::kolizja(Organizm* atakujacyOrganizm){
    if(czyUmiejetnoscWlaczona){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    atakujacyOrganizm->zabij();
                    continue;
                }
                Organizm* temp = swiatRef->getOrganizm(getX()+i,getY()+j);
                if(temp != nullptr){
                    swiatRef->dodajLog(atakujacyOrganizm, "zostaj calopalony przez "+toString());
                    temp->zabij();
                }
            }
        }
    }else{
        if(atakujacyOrganizm->getSila() >= getSila()){
            swiatRef->dodajLog(atakujacyOrganizm, "wygrywa walke z "+toString());
            zabij();
        }
        else{
            swiatRef->dodajLog(this, "wygrywa walke z "+atakujacyOrganizm->toString());
            atakujacyOrganizm->zabij();
        }
    }
}


Organizm* Czlowiek::dziecko(){
    return new Czlowiek(*this);
}

char Czlowiek::getZnakZKlawiatury(){
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

