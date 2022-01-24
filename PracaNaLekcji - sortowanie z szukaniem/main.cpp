#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

//zrobiłem osobny program z funkcją quicksort, ponieważ tak mogłem się łatwiej rozeznać w programie.

int main()
{
	
	algorytmy wartosc;


	cout << "Podaj wartosc, ktorej potrzebujesz: ";
	int liczba_do_szukania;
	cin >> liczba_do_szukania;
	int rezultat = wartosc.szukanie(0, liczba_do_szukania);

	if (rezultat == -1)
	{
		cout << "Wartosc nieznaleziona" << endl;
	}
	else
	{
		cout << "Wartosc zostala znaleziona na pozycji nr: " << rezultat << " po " << rezultat << " okrazeniach petli" << endl;
	}






	algorytmy wartosc2;
	wartosc2.QS(0, wartosc2.wektor.size() - 1);
	cout << "Podaj wartosc, ktorej potrzebujesz: ";
	int liczba_do_szukania2;
	cin >> liczba_do_szukania2;
	int rezultat2 = wartosc2.szukanieV2(0, wartosc2.wektor.size(), liczba_do_szukania2);

	if (rezultat2 == -1)
	{
		cout << "Wartosc nieznaleziona" << endl;
	}
	else
	{
		cout << "Wartosc zostala znaleziona na pozycji nr: " << rezultat2 << " po " << wartosc2.liczenie << " okrazeniach petli" << endl;
	}
}