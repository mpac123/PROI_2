#ifndef _STATEK_H_
#define _STATEK_H_
#include "plansza.h"
enum pozycja {pionowy, poziomy};

class ListaStatkow;

//klasa czysto wirtualna przechowujaca statki - mogace byc jednomasztowcami,
//dwumasztowcami, trojmasztowcami lub czteromasztowcami
//Metody pozwalaja zarzadzac statkiem na planszy -> korzysta z klasy Plansza

class Statek
{
public:
	friend class ListaStatkow;
	
	Statek();
	virtual ~Statek() {};
	Statek(int x, int y, pozycja poz);
	Statek(const Statek& s);
	Statek& operator=(const Statek& s);
	
protected:
	int wsp_x;
	int wsp_y;
	pozycja polozenie;

	//Funkcja pomocnicza, losujaca wolne wspolrzedne dla statku
	void Losuj(const Plansza& pl);
	//Funkcje wywolywane przez metody wirtualne klas pochodnych
	void PrzylegajaceOgolem(int n, Plansza& pl);
	void CzyscPolaOgolem(int n, Plansza& pl);
	void ZajmijPolaOgolem(int n, Plansza& pl);
	//Funkcje wirtualne
	virtual void ZaznaczPrzylegajace(Plansza& pl) = 0;
	virtual void ZajmijPola(Plansza& pl) =0;
	virtual void CzyscPola(Plansza& pl) =0;
	//Funkcje ustawiajace statek
	void UstawStatek(Plansza& pl);
	void UsunStatek(Plansza& pl);
	//Funkcja sprawdzajaca czy statek mozna ustawic na danym polu
	virtual bool CzySieMiesci(const Plansza& pl) =0;
	bool CzySieMiesciOgolem(int n, const Plansza& pl);
	
	
};

class Jednomasztowiec : public Statek
{
public:
	Jednomasztowiec();
	Jednomasztowiec(int x, int y, pozycja poz);
	Jednomasztowiec(const Jednomasztowiec& s);
private:
	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(const Plansza& pl);
};

class Dwumasztowiec : public Statek
{
public:
	Dwumasztowiec();
	Dwumasztowiec(int x, int y, pozycja poz);
	Dwumasztowiec(const Dwumasztowiec& s);
private:
	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(const Plansza& pl);
};

class Trzymasztowiec : public Statek
{
public:
	Trzymasztowiec();
	Trzymasztowiec(int x, int y, pozycja poz);
	Trzymasztowiec(const Trzymasztowiec& s);
private:
	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(const Plansza& pl);
};

class Czteromasztowiec : public Statek
{
public:
	Czteromasztowiec();
	Czteromasztowiec(int x, int y, pozycja poz);
	Czteromasztowiec(const Czteromasztowiec& s);
private:
	void ZaznaczPrzylegajace(Plansza& pl);
	void ZajmijPola(Plansza& pl);
	void CzyscPola(Plansza& pl);
	bool CzySieMiesci(const Plansza& pl);
};
#endif
