#include <iostream>
#include <vector>

#include "hurtownia.h"

using namespace std;

int main() {
  Hurtownia drutex("Drutex", Adres("Bydzia", "Fordon", 12345));

  Klient zenek("Zenek", Adres("Gdansk", "Grunwaldzka 5", 80123));
  Klient krystyna("Krystyna", Adres("Warszawa", "Marszalkowska", 01234));
  Klient bogdan("Bogdan", Adres("Bydgoszcz", "Fordon", 62312));

  drutex.dodaj_klienta(zenek);
  drutex.dodaj_klienta(krystyna);

  drutex.dodaj_towar(cegly, 10);
  drutex.dodaj_towar(druty, 1);
  drutex.dodaj_towar(beton, 0);

  drutex.wydaj_towar(zenek, cegly, 3);

  drutex.wydaj_towar(bogdan, cegly, 1);

  drutex.wydaj_towar(krystyna, cegly, 4);
  drutex.wydaj_towar(krystyna, beton, 1);
  drutex.wydaj_towar(krystyna, druty, 1);

  int wynikCegly = drutex.stan(cegly);
  int wynikBeton = drutex.stan(beton);
  int wynikDruty = drutex.stan(druty);

  cout << "Miało zostać 3 cegly: " << wynikCegly << endl;
  cout << "Miało zostać 0 betonu: " << wynikBeton << endl;
  cout << "Miało zostać 0 drutów: " << wynikDruty << endl;

  cout << "Wynik symulacji: "
       << (wynikCegly == 3 && wynikBeton == 0 && wynikDruty == 0
               ? "PRAWIDŁOWY"
               : "NIEPRAWIDŁOWY")
       << endl;

  cin.get();
  return 0;
}