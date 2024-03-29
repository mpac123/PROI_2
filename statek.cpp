#include "statek.h"
#include <ctime>
#include <cstdlib>
Statek::Statek(int x, int y, pozycja poz)
	: wsp_x(x), wsp_y(y), polozenie(poz) {}

Statek::Statek() {wsp_x=0; wsp_y=0; polozenie=pionowy;}
Statek::Statek(const Statek& s)
{
	wsp_x=s.wsp_x;
	wsp_y=s.wsp_y;
	polozenie=s.polozenie;
}
Statek& Statek::operator=(const Statek& s)
{
	wsp_x=s.wsp_x;
	wsp_y=s.wsp_y;
	polozenie=s.polozenie;
	return *this;
}
Jednomasztowiec::Jednomasztowiec() : Statek() {}
Dwumasztowiec::Dwumasztowiec() : Statek() {}
Trzymasztowiec::Trzymasztowiec() : Statek() {}
Czteromasztowiec::Czteromasztowiec() : Statek() {}

Jednomasztowiec::Jednomasztowiec(int x, int y, pozycja poz) : Statek(x,y,poz) {}
Dwumasztowiec::Dwumasztowiec(int x, int y, pozycja poz) : Statek(x,y,poz) {}
Trzymasztowiec::Trzymasztowiec(int x, int y, pozycja poz) : Statek(x,y,poz) {}
Czteromasztowiec::Czteromasztowiec(int x, int y, pozycja poz) : Statek(x,y,poz) {}

Jednomasztowiec::Jednomasztowiec(const Jednomasztowiec& s) : Statek(s) {}
Dwumasztowiec::Dwumasztowiec(const Dwumasztowiec& s) : Statek(s) {}
Trzymasztowiec::Trzymasztowiec(const Trzymasztowiec& s) : Statek(s) {}
Czteromasztowiec::Czteromasztowiec(const Czteromasztowiec& s) : Statek(s) {}

void Statek::Losuj(const Plansza& pl)
{
	if (pl.wym_x==0 or pl.wym_y==0)
		return;
	srand(time(0));
	do{
		polozenie=static_cast<pozycja>(rand()%2);
		wsp_x=rand()%pl.wym_x;
		wsp_y=rand()%pl.wym_y;
	}while(!CzySieMiesci(pl));
}

void Statek::UstawStatek(Plansza& pl)
{
	if (CzySieMiesci(pl))
	{
		ZajmijPola(pl);
		ZaznaczPrzylegajace(pl);
	}
}

void Statek::UsunStatek(Plansza& pl)
{
	
		CzyscPola(pl);
		pl.CzyscWolnePrzylegajace();
}

bool Jednomasztowiec::CzySieMiesci(const Plansza& pl)
{
	return CzySieMiesciOgolem(1,pl);
}

bool Dwumasztowiec::CzySieMiesci(const Plansza& pl)
{
	return CzySieMiesciOgolem(2,pl);
}

bool Trzymasztowiec::CzySieMiesci(const Plansza& pl)
{
	return CzySieMiesciOgolem(3,pl);
}	

bool Czteromasztowiec::CzySieMiesci(const Plansza& pl)
{
	return CzySieMiesciOgolem(4,pl);
}

bool Statek::CzySieMiesciOgolem(int n, const Plansza& pl)
{
	int pom=0;
	int x=wsp_x;
	int y=wsp_y;
	if (polozenie==pionowy)
	{
		if (y+n-1>=pl.wym_y) return false;
		for (int i=0; i<n; i++)
			if (pl[x][y+i]==wolne) 
				pom++;
		if (pom==n)
			return true;
		else
			pom=0;
	}
	else
	{
		if (x+n-1>=pl.wym_x) return false;
		for (int i=0; i<n; i++)
			if (pl[x+i][y]==wolne) 
				pom++;
		if (pom==n)
			return true;
		else
			pom=0;
	}
	return false;
}
void Jednomasztowiec::ZajmijPola(Plansza& pl)
{
	ZajmijPolaOgolem(1,pl);
}

void Dwumasztowiec::ZajmijPola(Plansza& pl)
{
	ZajmijPolaOgolem(2,pl);
}

void Trzymasztowiec::ZajmijPola(Plansza& pl)
{
	ZajmijPolaOgolem(3,pl);
}

void Czteromasztowiec::ZajmijPola(Plansza& pl)
{
	ZajmijPolaOgolem(4,pl);
}

void Statek::ZajmijPolaOgolem(int n, Plansza& pl)
{
	if (polozenie==pionowy)
		for (int i=0; i<n; i++)
			pl.ZajmijPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<n; i++)
			pl.ZajmijPole(wsp_x+i,wsp_y);
}

void Jednomasztowiec::CzyscPola(Plansza& pl)
{
	CzyscPolaOgolem(1,pl);
}

void Dwumasztowiec::CzyscPola(Plansza& pl)
{
	CzyscPolaOgolem(2,pl);
}

void Trzymasztowiec::CzyscPola(Plansza& pl)
{
	CzyscPolaOgolem(3,pl);
}

void Czteromasztowiec::CzyscPola(Plansza& pl)
{
	CzyscPolaOgolem(4,pl);
}

void Statek::CzyscPolaOgolem(int n, Plansza& pl)
{
	if (polozenie==pionowy)
		for (int i=0; i<n; i++)
			pl.CzyscPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<n; i++)
			pl.CzyscPole(wsp_x+i,wsp_y);
}


void Statek::PrzylegajaceOgolem(int n, Plansza& pl)
{
	if (polozenie==pionowy)
	{
		pl.ZaznaczPrzylegajace(wsp_x,wsp_y-1); //pole nad
		pl.ZaznaczPrzylegajace(wsp_x,wsp_y+n); //pole pod
		for (int i=wsp_y-1; i<=wsp_y+n; i++)
		{
			pl.ZaznaczPrzylegajace(wsp_x-1,i);
			pl.ZaznaczPrzylegajace(wsp_x+1,i);
		}
	}
	else
	{
		pl.ZaznaczPrzylegajace(wsp_x-1,wsp_y); //pole po lewej
		pl.ZaznaczPrzylegajace(wsp_x+n,wsp_y); //pole po prawej
		for (int i=wsp_x-1; i<=wsp_x+n; i++)
		{
			pl.ZaznaczPrzylegajace(i,wsp_y-1);
			pl.ZaznaczPrzylegajace(i,wsp_y+1);
		}
	}
}
void Jednomasztowiec::ZaznaczPrzylegajace(Plansza& pl)
{
	PrzylegajaceOgolem(1,pl);
}
void Dwumasztowiec::ZaznaczPrzylegajace(Plansza& pl)
{
	PrzylegajaceOgolem(2,pl);
}
void Trzymasztowiec::ZaznaczPrzylegajace(Plansza& pl)
{
	PrzylegajaceOgolem(3,pl);
}
void Czteromasztowiec::ZaznaczPrzylegajace(Plansza& pl)
{
	PrzylegajaceOgolem(4,pl);
}
