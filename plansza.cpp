#include "plansza.h"
Plansza::Plansza() {}
Plansza::Plansza(int x, int y) : wym_x(x), wym_y(y)
{
	p=new pole*[x];
	for (int i=0; i<x; i++)
		p[i]=new pole[y];
	
	for (int i=0; i<x; i++)
		for (int j=0; j<y; j++)
			p[i][j]=wolne;
}

Plansza::~Plansza()
{
	for (int i=0; i<wym_x; i++)
		delete[] p[i];
	delete[] p;
	p=NULL;
}

Plansza::Plansza(const Plansza& kopiowana)
{
	p=new pole*[kopiowana.wym_x];
	for (int i=0; i<kopiowana.wym_x; i++)
		p[i]=new pole[kopiowana.wym_y];
	
	for (int i=0; i<kopiowana.wym_x; i++)
		for (int j=0; j<kopiowana.wym_y; j++)
			p[i][j]=kopiowana.p[i][j];
}

pole* Plansza::operator[](int a)
{
	return p[a];
}

const pole* Plansza::operator[](int a) const
{
	return p[a];
}

bool Plansza::CzyscPlansze()
{
	for (int i=0; i<wym_x; i++)
		for (int j=0; j<wym_y; j++)
			p[i][j]=wolne;
}

void Plansza::ZajmijPole(int x, int y)
{
	if (x>=0 and x<wym_x and y>=0 and y<wym_y and p[x][y]==wolne)
	{
		p[x][y]=zajete;
		check=succeeded;
	}
	else
		check=failed;
}

void Plansza::CzyscPole(int x, int y)
{
	if (x>=0 and x<wym_x and y>=0 and y<wym_y)
		p[x][y]=wolne;
}

void Plansza::ZaznaczPrzylegajace(int x, int y)
{
	if (x>=0 and x<wym_x and y>=0 and y<wym_y)
		p[x][y]=przylega;
}
std::ostream& operator<<(std::ostream &ekran, const Plansza &pl)
{
	for (int j=0; j<pl.wym_y; j++)
	{
		for (int i=0; i<pl.wym_x; i++)
		{
			ekran << "|";
			if (pl.p[i][j]==wolne)
				ekran << " ";
			else if (pl.p[i][j]==zajete)
				ekran << "X";
			else if (pl[i][j]==przylega)
				ekran << "o";
		}
		ekran << "|" << std::endl;
	}
	return ekran;
}
