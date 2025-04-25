#include "Zwierze.hpp"

class Czlowiek : public Zwierze{

public:
    Czlowiek(int x, int y, int sila = 5,bool czyUmiejetnoscWlaczona= false, int licznikUmiejetnosci = 5, int wiek = 0);
    void akcja() override;
    void kolizja(Organizm* atakujacyOrganizm) override;
    Organizm* dziecko() override;

};