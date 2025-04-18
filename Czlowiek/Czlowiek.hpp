#include "../Organizm.hpp"

class Czlowiek : public Organizm{
    bool czyUmiejetnoscWlaczona;
    int licznikUmiejetnosci;

public:
    Czlowiek(int x, int y);
    void akcja() override;
    void kolizja(Organizm* atakujacyOrganizm) override;
    Organizm* dziecko() override;

    char getZnakZKlawiatury();
};