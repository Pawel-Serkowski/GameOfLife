#include <iostream>
#include "Swiat.hpp"
#include <cstdlib>
#include <time.h>

int main(){
    srand(time(NULL));
    Swiat* swiat = Swiat::getStanSwiata(10,10);
    swiat->stworzPopulacje();
    swiat->symulacja();

    std::cout << "\n";
}