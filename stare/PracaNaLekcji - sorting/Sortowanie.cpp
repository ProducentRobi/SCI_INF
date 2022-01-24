#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

char choose;
alg algorithm;

int main()
{

	cout << "Wylosowane liczby to: " << endl;
	algorithm.random();
	algorithm.see();
	cout << endl << endl;
	cout << "//Wybierz, w jaki sposob chcesz posortowac liczby\\\\" << endl;
	cout << "A - algorytm wstawieniowy" << endl;
	cout << "B - algorytm babelkowy" << endl << endl;
	cin >> choose;
	cout << endl;
	
	cout << "Kolejnosc liczb po sortowaniu wyglada nastepujaco: " << endl;
	if (choose == 'A')
	{
		algorithm.insert();
		algorithm.see();
		cout << "\nZastosowano sortowanie wstawieniowe" << endl;
	}
	
	else if (choose == 'B')
	{
		algorithm.bubbles();
		algorithm.see();
		cout << "\nZastosowano sortowanie babelkowe" << endl;
	}
	
	else
	{
		cout << "Podales zla wartosc, uruchom program ponownie" << endl;
	}
}