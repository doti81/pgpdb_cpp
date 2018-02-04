#include <algorithm>

#include "hurtownia.h"

std::ostream &operator<<(std::ostream &os, const towar &rodzaj) {
  switch (rodzaj) {
  case druty:
    os << "druty";
    break;
  case cegly:
    os << "cegly";
    break;
  case beton:
    os << "beton";
    break;
  }
}

Hurtownia::Hurtownia(string nazwa, Adres adres) : Siec(nazwa, adres) {
  stan_druty = 0;
  stan_cegly = 0;
  stan_beton = 0;

  cout << "Nowa hurtownia: " << nazwa << endl;
}

void Hurtownia::dodaj_klienta(const Klient &klient) {
  cout << "Dodaje klienta: " << klient.getNazwa() << endl;
  klienci.push_back(klient);
}

void Hurtownia::zmien_stan(towar rodzaj, int ilosc) {
  cout << "Zmien stan towaru " << rodzaj << " o ilość " << ilosc << endl;
  switch (rodzaj) {
  case druty:
    stan_druty += ilosc;
    break;
  case cegly:
    stan_cegly += ilosc;
    break;
  case beton:
    stan_beton += ilosc;
    break;
  }
}

void Hurtownia::dodaj_towar(towar rodzaj, int ilosc) {
  cout << "Dodaj " << ilosc << " towaru " << rodzaj << endl;
  zmien_stan(rodzaj, ilosc);
}

void Hurtownia::wydaj_towar(const Klient &klient, towar rodzaj, int ilosc) {
  if (stan(rodzaj) < ilosc) {
    cout << "Za mało towaru " << rodzaj << " na stanie: " << stan(rodzaj)
         << endl;
    return;
  }

  if (std::find(klienci.begin(), klienci.end(), klient) == klienci.end()) {
    cout << "Klient " << klient.getNazwa() << " nie jest klientem hurtowni!" << endl;
    return;
  }

  cout << "Wydaj " << ilosc << " towaru " << rodzaj << " klientowi " << klient.getNazwa() << endl;
  zmien_stan(rodzaj, -ilosc);
}

int Hurtownia::stan(towar rodzaj) {
  int stan;
  switch (rodzaj) {
  case druty:
    stan = stan_druty;
    break;
  case cegly:
    stan = stan_cegly;
    break;
  case beton:
    stan = stan_beton;
    break;
  default:
    0;
    break;
  }
  cout << "Stan towaru " << rodzaj << " to " << stan << endl;
  return stan;
}