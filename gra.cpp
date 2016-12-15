#include "gra.h"
#include <iostream>
#include <vector>
#include "plansza.h"

Gra::Gra(Plansza p) : pl(p)
{
	KonfiguracjaStatkowzKlawiatury();
}

/*Gra::Gra()
{
	KonfiguracjaPlanszyzKlawiatury();
	KonfiguracjaStatkowzKlawiatury();
}
*/
Gra::Gra(Plansza p, const std::vector<Statek>& ls) : pl(p), lista_statkow(ls) {}

void Gra::DodajStatek(const Statek& s)
{
	lista_statkow.push_back(s);
}

void Gra::UstawStatek(Statek s)
{
	s.ZajmijPola(pl);
	s.ZaznaczPrzylegajace(pl);
}

void Gra::KonfiguracjaStatkowzKlawiatury()
{
	int n;
	std::cout << "Ile czteromasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Czteromasztowiec());
	std::cout << "Ile trzymasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Trzymasztowiec());
	std::cout << "Ile dwumasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Dwumasztowiec());
	std::cout << "Ile jednomasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Jednomasztowiec());
}

void Gra::KonfiguracjaPlanszyzKlawiatury()
{
	int n,m;
	std::cout << "Podaj szerokosc i wysokosc planszy: ";
	std::cin >> n >> m;
	Plansza pl(n,m);
}


