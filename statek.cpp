#include "statek.h"
#include <ctime>
#include <cstdlib>
Statek::Statek(int x, int y, pozycja poz, Plansza p)
	: wsp_x(x), wsp_y(y), polozenie(poz), pl(p)
{}

Statek::Statek() {}

Statek::Statek(Plansza p) : pl(p) {
	wsp_x=0; wsp_y=0;  }
	
Jednomasztowiec::Jednomasztowiec(Plansza p) : Statek(p) {}
	
Dwumasztowiec::Dwumasztowiec(Plansza p) : Statek(p) {}
	
Trzymasztowiec::Trzymasztowiec(Plansza p) : Statek(p) {}
	
Czteromasztowiec::Czteromasztowiec(Plansza p) : Statek(p) {}

Statek::~Statek() {}

Jednomasztowiec::~Jednomasztowiec()
{
	pl.CzyscPole(wsp_x, wsp_y);
}

Dwumasztowiec::~Dwumasztowiec()
{
	pl.CzyscPole(wsp_x,wsp_y);
	if (polozenie==pionowy)
		pl.CzyscPole(wsp_x,wsp_y+1);
	else
		pl.CzyscPole(wsp_x+1, wsp_y);
}

Trzymasztowiec::~Trzymasztowiec()
{
	if (polozenie==pionowy)
		for (int i=0; i<3; i++)
			pl.CzyscPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<3; i++)
			pl.CzyscPole(wsp_x+i,wsp_y);
}

Czteromasztowiec::~Czteromasztowiec()
{
	if (polozenie==pionowy)
		for (int i=0; i<4; i++)
			pl.CzyscPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<4; i++)
			pl.CzyscPole(wsp_x+i,wsp_y);
}
void Statek::Losuj()
{
	srand(time(0));
	do{
		polozenie=static_cast<pozycja>(rand()%2);
		wsp_x=rand()%10;
		wsp_y=rand()%10;
	}while(!CzySieMiesci(wsp_x,wsp_y,polozenie));
}

void Statek::Dobierz()
{
	for (wsp_x; wsp_x<pl.wym_x; wsp_x++)
		for (int wsp_y; wsp_y<pl.wym_y; wsp_y++)
		{
			polozenie=poziomy;
			if(CzySieMiesci(wsp_x,wsp_y,polozenie)) return;
			polozenie=pionowy;
			if(CzySieMiesci(wsp_x,wsp_y,polozenie)) return;
		}
	check=failed;	
}
bool Jednomasztowiec::CzySieMiesci(int x, int y, pozycja poz)
{
	if (pl[x][y]==wolne) return true;
	else return false;
}

bool Dwumasztowiec::CzySieMiesci(int x, int y, pozycja poz)
{
	if (poz==pionowy)
	{
		if (y+1>wsp_y) return false;
		if (pl[x][y]==wolne && pl[x][y+1]==wolne) return true;
	}
	else
	{
		if (x+1>wsp_x) return false;
		if (pl[x][y]==wolne && pl[x+1][y]==wolne) return true;
	}
	return false;
}

bool Trzymasztowiec::CzySieMiesci(int x, int y, pozycja poz)
{
	if (poz==pionowy)
	{
		if (y+2>wsp_y) return false;
		if (pl[x][y]==wolne && pl[x][y+1]==wolne && pl[x][y+2]==wolne) return true;
	}
	else
	{
		if (x+2>wsp_x) return false;
		if (pl[x][y]==wolne && pl[x+1][y]==wolne && pl[x+2][y]==wolne) return true;
	}
	return false;
}	

bool Czteromasztowiec::CzySieMiesci(int x, int y, pozycja poz)
{
	if (poz==pionowy)
	{
		if (y+3>wsp_y) return false;
		if (pl[x][y]==wolne && pl[x][y+1]==wolne && pl[x][y+2]==wolne && pl[x][y+3]==wolne) return true;
	}
	else
	{
		if (x+3>wsp_x) return false;
		if (pl[x][y]==wolne && pl[x+1][y]==wolne && pl[x+2][y]==wolne && pl[x+3][y]==wolne) return true;
	}
	return false;
}

void Jednomasztowiec::ZajmijPola()
{
	pl.ZajmijPole(wsp_x, wsp_y);
}

void Dwumasztowiec::ZajmijPola()
{
	pl.ZajmijPole(wsp_x,wsp_y);
	if (polozenie==pionowy)
		pl.ZajmijPole(wsp_x,wsp_y+1);
	else
		pl.ZajmijPole(wsp_x+1, wsp_y);
}

void Trzymasztowiec::ZajmijPola()
{
	if (polozenie==pionowy)
		for (int i=0; i<3; i++)
			pl.ZajmijPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<3; i++)
			pl.ZajmijPole(wsp_x+i,wsp_y);
}

void Czteromasztowiec::ZajmijPola()
{
	if (polozenie==pionowy)
		for (int i=0; i<4; i++)
			pl.ZajmijPole(wsp_x,wsp_y+i);
	else
		for (int i=0; i<4; i++)
			pl.ZajmijPole(wsp_x+i,wsp_y);
}
void Statek::PrzylegajaceOgolem(int n)
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
void Jednomasztowiec::ZaznaczPrzylegajace()
{
	PrzylegajaceOgolem(1);
}
void Dwumasztowiec::ZaznaczPrzylegajace()
{
	PrzylegajaceOgolem(2);
}
void Trzymasztowiec::ZaznaczPrzylegajace()
{
	PrzylegajaceOgolem(3);
}
void Czteromasztowiec::ZaznaczPrzylegajace()
{
	PrzylegajaceOgolem(4);
}
