#include "gra.h"
#include <iostream>
#include <vector>
#include "plansza.h"

Gra::Gra(Plansza p) : pl(p)
{
	KonfiguracjaStatkowzKlawiatury();
}

Gra::Gra()
{
	KonfiguracjaPlanszyzKlawiatury();
	KonfiguracjaStatkowzKlawiatury();
}

Gra::Gra(Plansza p, const std::vector<Statek>& ls) : pl(p), lista_statkow(ls) {}

void Gra::DodajStatek(const Statek& s)
{
	lista_statkow.push_back(s);
}

void Gra::KonfiguracjaStatkowzKlawiatury()
{
	int n;
	std::cout << "Ile czteromasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Czteromasztowiec(pl));
	std::cout << "Ile trzymasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Trzymasztowiec(pl));
	std::cout << "Ile dwumasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Dwumasztowiec(pl));
	std::cout << "Ile jednomasztowcow? ";
	std::cin >> n;
	for (int i=0; i<n; i++)
		DodajStatek(Jednomasztowiec(pl));
}

void Gra::KonfiguracjaPlanszyzKlawiatury()
{
	int n,m;
	std::cout << "Podaj szerokosc i wysokosc planszy: ";
	std::cin >> n >> m;
	Plansza pl(n,m);
}

bool Gra::CzyKonfiguracjaMozliwa(int n)
{
	if (n>=lista_statkow.size())
		return true;
	
	lista_statkow[n].Dobierz();
	if (lista_statkow[n].check!=failed)
		if (CzyKonfiguracjaMozliwa(n+1)) return true;
	else
		return false;
			
}
	
