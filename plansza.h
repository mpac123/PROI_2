#ifndef _PLANSZA_H_
#define _PLANSZA_H_

#include <iostream>

enum pole {wolne, zajete, przylega};
enum progress {failed, succeeded};

//Klasa obslugujaca plansze, na ktorej ustawiane sa statki
class Plansza
{
public:
	Plansza();
	Plansza(int x, int y);
	~Plansza();
	Plansza(const Plansza& kopiowana);
	Plansza& operator=(const Plansza& kopiowana);
	bool operator==(const Plansza& pl);

	//Funkcje zaznaczajace okreslone pola na planszy
	void ZajmijPole(int x, int y);
	void CzyscPole(int x, int y);
	void ZaznaczPrzylegajace(int x, int y);
	
	//Funkcje sprawdzajace aktualny stan danego pola
	bool CzyWolne(int x, int y);
	bool CzyZajete(int x, int y);
	
	//Funkcja czyszczaca wszystkie pola oznaczone jako 'przylegajace',
	//ktore zostaly bez zajetych pol obok
	void CzyscWolnePrzylegajace();
	
	pole* operator[](int a);
	const pole* operator[](int a) const;
	
	//wymiary planszy
	int wym_x;
	int wym_y;
	//tablica dwuelementowa przedstawiajaca plansze
	pole** p;

private:
	//Funkcja oznaczajaca wszystkie pola jako wolne
	void CzyscPlansze();
	friend std::ostream& operator<<(std::ostream &ekran, const Plansza &pl);
};

#endif
