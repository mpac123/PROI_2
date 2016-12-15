#ifndef _LISTA_STATKOW_H_
#define _LISTA_STATKOW_H_
#include <vector>
#include "statek.h"
class ListaStatkow
{
public:
	
	std::vector<Statek*> lista;
	Plansza pl;
	
	void DodajJednomasztowce(int x);
	void DodajDwumasztowce(int x);
	void DodajTrzymasztowce(int y);
	void DodajCzteromasztowce(int x);
	void DodajStatkizKlawiatury();
	
	void DodajPlansze(int x, int y);
	void DodajPlanszezKlawiatury();
	
	bool SprawdzKonfiguracje();
	bool Testuj(int x);
	
	
private:
	
};
#endif