#include "plansza.h"
#include "statek.h"
#include "lista_statkow.h"
main()
{
	ListaStatkow Nowa;
	Nowa.DodajPlanszezKlawiatury();
	Nowa.DodajStatkizKlawiatury();
	if (Nowa.SprawdzKonfiguracje()) std::cout<<"TAK\n";
	std::cout << Nowa.pl;
}
