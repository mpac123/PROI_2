#include "plansza.h"
#include "statek.h"
#include "lista_statkow.h"
int main()
{
	//Test #1
	ListaStatkow Pierwsza;
	Pierwsza.DodajPlansze(4,7);
	Pierwsza.DodajCzteromasztowce(4);
	Pierwsza.SprawdzKonfiguracje();
	
	//Test #2
	ListaStatkow Druga;
	Druga.DodajPlansze(5,6);
	Druga.DodajCzteromasztowce(3);
	Druga.DodajDwumasztowce(5);
	Druga.SprawdzKonfiguracje();
	
	//Test #3
	ListaStatkow Trzecia;
	Trzecia.DodajPlansze(3,4);
	Trzecia.DodajTrzymasztowce(1);
	Trzecia.DodajDwumasztowce(2);
	Trzecia.SprawdzKonfiguracje();
	
	//Test #4
	ListaStatkow Czwarta;
	Czwarta.DodajPlansze(10,1);
	Czwarta.DodajCzteromasztowce(1);
	Czwarta.DodajJednomasztowce(3);
	Czwarta.SprawdzKonfiguracje();
	
	//Test #5
	ListaStatkow Piata;
	Piata.DodajPlansze(10,2);
	Piata.DodajTrzymasztowce(1);
	Piata.DodajDwumasztowce(3);
	Piata.SprawdzKonfiguracje();
	
	//Z klawiatury
	ListaStatkow Nowa;
	Nowa.DodajPlanszezKlawiatury();
	Nowa.DodajStatkizKlawiatury();
	Nowa.SprawdzKonfiguracje();
	
	return 0;
}
