#include "lista_statkow.h"
#include <iostream>
#include <vector>
#include "plansza.h"


void ListaStatkow::DodajJednomasztowce(int x)
{
	Jednomasztowiec* s=new Jednomasztowiec;
	for (int i=0; i<x; i++)
		lista.push_back(s);
}

void ListaStatkow::DodajDwumasztowce(int x)
{
	Dwumasztowiec* s=new Dwumasztowiec;
	for (int i=0; i<x; i++)
		lista.push_back(s);
}

void ListaStatkow::DodajTrzymasztowce(int x)
{
	Trzymasztowiec* s=new Trzymasztowiec;
	for (int i=0; i<x; i++)
		lista.push_back(s);
}

void ListaStatkow::DodajCzteromasztowce(int x)
{
	Czteromasztowiec* s=new Czteromasztowiec;
	for (int i=0; i<x; i++)
		lista.push_back(s);
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

bool ListaStatkow::Testuj(int n)
{
	//std::cout << n << " " << lista[n]->wsp_x << " " << lista[n]->wsp_y << std::endl << pl << std::endl;
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
				//std::cout << "Usuwamy " << n << " " << lista[n]->wsp_x << " " << lista[n]->wsp_y << std::endl;
			}
			lista[n]->polozenie=poziomy;
			if (lista[n]->CzySieMiesci(pl))
			{
				lista[n]->UstawStatek(pl);
				if (Testuj(n+1)) return true;
				lista[n]->UsunStatek(pl);
				//std::cout << "Usuwamy " << n << " " << lista[n]->wsp_x << " " << lista[n]->wsp_y << std::endl;
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
