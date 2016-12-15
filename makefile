statki: main.cpp plansza.cpp statek.cpp lista_statkow.cpp plansza.h statek.h lista_statkow.h
	g++ -o statki main.cpp plansza.cpp statek.cpp lista_statkow.cpp -I. -Wall

clean:
	rm statki -f
