#ifndef _LISTA_STATKOW_H_
#define _LISTA_STATKOW_H_
#include <vector>
#include "statek.h"
class ListaStatkow
{
public:
	//Funkcje dodające statki do listy statkow:
	void DodajJednomasztowce(int x);
	void DodajDwumasztowce(int x);
	void DodajTrzymasztowce(int x);
	void DodajCzteromasztowce(int x);
	void DodajStatkizKlawiatury();
	
	//Funkcja dodające planszę
	void DodajPlansze(int x, int y);
	void DodajPlanszezKlawiatury();
	
	//Funkcja, czy ustawienie jest możliwe
	bool SprawdzKonfiguracje();
	~ListaStatkow();
private:
	//lista statkow
	std::vector<Statek*> lista;
	Plansza pl;
	
	//funkcja rekurencyjna wywolywana przez SprawdzKonfiguracje()
	bool Testuj(size_t x);
	
	
private:
	
};
#endif
