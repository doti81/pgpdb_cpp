#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Adres {
  string miasto;
  string ulica;
  int kod_pocztowy;

public:
  Adres(string miasto, string ulica, int kod_pocztowy) {
    this->miasto = miasto;
    this->ulica = ulica;
    this->kod_pocztowy = kod_pocztowy;

    cout << "Nowy adres: " << miasto << ", " << ulica << ", " << kod_pocztowy
         << endl;
  }
};

class Klient {
  string nazwa;
  Adres adres;

public:
  Klient(string nazwa, Adres adres) : nazwa(nazwa), adres(adres) {
    cout << "Nowy klient: " << nazwa << endl;
  }

  string getNazwa() const { return this->nazwa; }

  bool operator==(const Klient &Ref) const {
    return (this->nazwa == Ref.getNazwa());
  }
};

class Siec {
  string nazwa;
  Adres adres;

public:
  Siec(string nazwa, Adres adres) : nazwa(nazwa), adres(adres) {
    cout << "Nowa sieć: " << nazwa << endl;
  }
};

enum towar { druty = 0, cegly = 1, beton = 2 };

class Hurtownia : Siec {
  vector<Klient> klienci;

  int stan_druty;
  int stan_cegly;
  int stan_beton;

public:
  Hurtownia(string nazwa, Adres adres);

  void dodaj_klienta(const Klient &klient);

  void zmien_stan(towar rodzaj, int ilosc);

  void dodaj_towar(towar rodzaj, int ilosc);

  void wydaj_towar(const Klient &klient, towar rodzaj, int ilosc);

  int stan(towar rodzaj);
};