#ifndef _STATEK_H_
#define _STATEK_H_
#include "plansza.h"
enum pozycja {pionowy, poziomy};

class ListaStatkow;
class Statek
{
public:
	friend class ListaStatkow;
	
	Statek();
	Statek(int x, int y, pozycja poz);
	Statek(const Statek& s);
	Statek& operator=(const Statek& s);
	

	int wsp_x;
	int wsp_y;
	pozycja polozenie;

	void Losuj(const Plansza& pl);
	void PrzylegajaceOgolem(int n, Plansza& pl);
	virtual void ZaznaczPrzylegajace(Plansza& pl) {};
	virtual void ZajmijPola(Plansza& pl) {};
	virtual void CzyscPola(Plansza& pl) {};
	
	void UstawStatek(Plansza& pl);
	void UsunStatek(Plansza& pl);

	virtual bool CzySieMiesci(Plansza pl) {};
	
};

class Jednomasztowiec : public Statek
{
public:
	Jednomasztowiec();
	Jednomasztowiec(int x, int y, pozycja poz);
	Jednomasztowiec(const Jednomasztowiec& s);

	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(Plansza pl);
};

class Dwumasztowiec : public Statek
{
public:
	Dwumasztowiec();
	Dwumasztowiec(int x, int y, pozycja poz);
	Dwumasztowiec(const Dwumasztowiec& s);

	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(Plansza pl);
};

class Trzymasztowiec : public Statek
{
public:
	Trzymasztowiec();
	Trzymasztowiec(int x, int y, pozycja poz);
	Trzymasztowiec(const Trzymasztowiec& s);

	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(Plansza pl);
};

class Czteromasztowiec : public Statek
{
public:
	Czteromasztowiec();
	Czteromasztowiec(int x, int y, pozycja poz);
	Czteromasztowiec(const Czteromasztowiec& s);

	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(Plansza pl);
};
#endif
