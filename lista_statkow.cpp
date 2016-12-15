#include "lista_statkow.h"
#include <iostream>
#include <vector>
#include "plansza.h"

ListaStatkow::~ListaStatkow()
{
	for (size_t i=0; i<lista.size(); i++)
	{
		delete lista[i];
	}
}
void ListaStatkow::DodajJednomasztowce(int x)
{
	for (int i=0; i<x; i++)
		lista.push_back(new Jednomasztowiec);
}

void ListaStatkow::DodajDwumasztowce(int x)
{
	for (int i=0; i<x; i++)
		lista.push_back(new Dwumasztowiec);
}

void ListaStatkow::DodajTrzymasztowce(int x)
{
	for (int i=0; i<x; i++)
		lista.push_back(new Trzymasztowiec);
}

void ListaStatkow::DodajCzteromasztowce(int x)
{
	for (int i=0; i<x; i++)
		lista.push_back(new Czteromasztowiec);
}

void ListaStatkow::DodajPlansze(int x, int y)
{
	pl=Plansza(x,y);
}

bool ListaStatkow::SprawdzKonfiguracje()
{
	if (Testuj(0))
	{
		std::cout << "TAK\n" <<pl;
		return true;
	}
	else
	{
		std::cout << "NIE\n";
		return false;
	}
}

bool ListaStatkow::Testuj(size_t n)
{
	
	if (n>=lista.size())
		return true;
	for (int i=0; i<pl.wym_x; i++)
	{
		for (int j=0; j<pl.wym_y; j++)
		{
			lista[n]->wsp_x=i;
			lista[n]->wsp_y=j;
			lista[n]->polozenie=pionowy;
			if (lista[n]->CzySieMiesci(pl))
			{
				lista[n]->UstawStatek(pl);
				if (Testuj(n+1)) return true;
				lista[n]->UsunStatek(pl);
			}
			lista[n]->polozenie=poziomy;
			if (lista[n]->CzySieMiesci(pl))
			{
				lista[n]->UstawStatek(pl);
				if (Testuj(n+1)) return true;
				lista[n]->UsunStatek(pl);
			}
		}
	}
	return false;
}

void ListaStatkow::DodajStatkizKlawiatury()
{
	int n;
	std::cout << "Ile jednomasztowcow? ";
	std::cin >> n;
	DodajJednomasztowce(n);
	std::cout << "Ile dwumasztowcow? ";
	std::cin >> n;
	DodajDwumasztowce(n);
	std::cout << "Ile trzymasztowcow? ";
	std::cin >> n;
	DodajTrzymasztowce(n);
	std::cout << "Ile czteromasztowcow? ";
	std::cin >> n;
	DodajCzteromasztowce(n);
}

void ListaStatkow::DodajPlanszezKlawiatury()
{
	int n,m;
	std::cout << "Podaj wymiary planszy: ";
	std::cin >> n >> m;
	DodajPlansze(n,m);
}
