#ifndef _PLANSZA_H_
#define _PLANSZA_H_

#include <iostream>

enum pole {wolne, zajete, przylega};
enum progress {failed, succeeded};


class Plansza
{
public:
	friend class Statek;
	friend class Gra;
	progress check;
	Plansza();
	Plansza(int x, int y);
	~Plansza();
	Plansza(const Plansza& kopiowana);
	void ZajmijPole(int x, int y);
	void CzyscPole(int x, int y);
	void ZaznaczPrzylegajace(int x, int y);
	pole* operator[](int a);
	const pole* operator[](int a) const;
	
private:
	
	int wym_x;
	int wym_y;
	pole** p;
	
	bool CzyscPlansze();
	friend std::ostream& operator<<(std::ostream &ekran, const Plansza &pl);
};

#endif
