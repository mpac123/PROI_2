#include "plansza.h"
#include "statek.h"
#include "lista_statkow.h"
int main()
{
	ListaStatkow Pierwsza;
	Pierwsza.DodajPlansze(4,7);
	Pierwsza.DodajCzteromasztowce(4);
	Pierwsza.SprawdzKonfiguracje();
	
	ListaStatkow Nowa;
	Nowa.DodajPlanszezKlawiatury();
	Nowa.DodajStatkizKlawiatury();
	Nowa.SprawdzKonfiguracje();
	
	return 0;
}
