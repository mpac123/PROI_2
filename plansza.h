#ifndef _PLANSZA_H_
#define _PLANSZA_H_

#include <iostream>

enum pole {wolne, zajete, przylega};
enum progress {failed, succeeded};


class Plansza
{
public:
	friend class Statek;
	friend class Jednomasztowiec;
	friend class Dwumasztowiec;
	friend class Trzymasztowiec;
	friend class Czteromasztowiec;
	friend class ListaStatkow;
	Plansza();
	Plansza(int x, int y);
	~Plansza();
	Plansza(const Plansza& kopiowana);
	Plansza& operator=(const Plansza& kopiowana);
	bool operator==(const Plansza& pl);
	
	void ZajmijPole(int x, int y);
	void CzyscPole(int x, int y);
	void ZaznaczPrzylegajace(int x, int y);
	bool CzyWolne(int x, int y);
	bool CzyZajete(int x, int y);
	
	void CzyscWolnePrzylegajace();
	
	pole* operator[](int a);
	const pole* operator[](int a) const;
	
private:
	
	int wym_x;
	int wym_y;
	pole** p;
	
	void CzyscPlansze();
	friend std::ostream& operator<<(std::ostream &ekran, const Plansza &pl);
};

#endif
