#ifndef _GRA_H_
#define _GRA_H_
#include <vector>
#include "statek.h"
class Gra
{
public:
	Gra(Plansza p);
	Gra(Plansza p, const std::vector<Statek>& ls);
	Gra();
	
	progress check;
	std::vector<Statek> lista_statkow;
	Plansza pl;
	void DodajStatek(const Statek& s);
	void UstawStatek(Statek s);
	void KonfiguracjaStatkowzKlawiatury();
	void KonfiguracjaPlanszyzKlawiatury();
	bool CzyKonfiguracjaMozliwa(int n);
	void LosujKonfiguracje();
	void UstawStatki();
	
	
private:
	
};
#endif
