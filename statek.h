#ifndef _STATEK_H_
#define _STATEK_H_
#include "plansza.h"
enum pozycja {pionowy, poziomy};

class Gra;
class Statek
{
public:
	Statek();
	Statek(Plansza p);
	friend class Gra;
	virtual ~Statek();
	Statek(int x, int y, pozycja poz, Plansza p);
	Plansza pl;
	
protected:
	
	progress check;
	int wsp_x;
	int wsp_y;
	pozycja polozenie;
	
	void Losuj();
	void Dobierz();
	void PrzylegajaceOgolem(int n);
	virtual void ZaznaczPrzylegajace() {};
	virtual void ZajmijPola() {};
	
	virtual bool CzySieMiesci(int x, int y, pozycja poz) {};
};

class Jednomasztowiec : public Statek
{
public:
	Jednomasztowiec(Plansza p);
	~Jednomasztowiec();
private:
	void ZaznaczPrzylegajace();
	void ZajmijPola();
	bool CzySieMiesci(int x, int y, pozycja poz=pionowy);
};

class Dwumasztowiec : public Statek
{
public:
	Dwumasztowiec(Plansza p);
	~Dwumasztowiec();
private:
	void ZaznaczPrzylegajace();
	void ZajmijPola();
	bool CzySieMiesci(int x, int y, pozycja poz);
};

class Trzymasztowiec : public Statek
{
public:
	Trzymasztowiec(Plansza p);
	~Trzymasztowiec();
private:
	void ZaznaczPrzylegajace();
	void ZajmijPola();
	bool CzySieMiesci(int x, int y, pozycja poz);
};

class Czteromasztowiec : public Statek
{
public:
	Czteromasztowiec(Plansza p);
	~Czteromasztowiec();
private:
	void ZaznaczPrzylegajace();
	void ZajmijPola();
	bool CzySieMiesci(int x, int y, pozycja poz);
};
#endif
