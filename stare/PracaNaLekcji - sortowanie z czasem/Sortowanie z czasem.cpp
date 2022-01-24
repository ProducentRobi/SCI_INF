#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;

char choose;
alg algorithm;

int main()
{
	//nie wyswietlam tych liczb, poniewaz jest ich 10000 i program bedzie nieczytelny
	algorithm.random();
	cout << "//Wybierz, w jaki sposob chcesz posortowac liczby\\\\" << endl;
	cout << "A - algorytm wstawieniowy" << endl;
	cout << "B - algorytm babelkowy" << endl;
	cout << "C - QS (QuickSort)" << endl;
	cout << "D - algorytm przez wybor" << endl;
	cin >> choose;
	cout << endl;

	if (choose == 'A')
	{
		auto startus = chrono::steady_clock::now();
		algorithm.insert();
		cout << endl;
		auto endus = chrono::steady_clock::now();
		auto timus = chrono::duration<double>(endus - startus);
		cout << "Czas sortowania wstawieniowego: " << timus.count() << endl;
		cout << "\nZastosowano sortowanie wstawieniowe" << endl;
	}

	else if (choose == 'B')
	{
		auto startus = chrono::steady_clock::now();
		algorithm.bubbles();
		cout << endl;
		auto endus = chrono::steady_clock::now();
		auto timus = chrono::duration<double>(endus - startus);
		cout << "Czas sortowania babelkowego: " << timus.count() << endl;
		cout << "\nZastosowano sortowanie babelkowe" << endl;
	}

	else if (choose == 'C')
	{
		auto startus = chrono::steady_clock::now();
		algorithm.quicksort(0, algorithm.vec.size() - 1);
		auto endus = chrono::steady_clock::now();
		auto timus = chrono::duration<double>(endus - startus);
		cout << "Czas sortowania QS: " << timus.count() << endl;
	}

	else if (choose == 'D')
	{
		auto startus = chrono::steady_clock::now();
		algorithm.choosing();
		auto endus = chrono::steady_clock::now();
		auto timus = chrono::duration<double>(endus - startus);
		cout << "Czas sortowania przez wybor: " << timus.count() << endl;
	}

	else
	{
		cout << "Podales zla wartosc, uruchom program ponownie" << endl;
	}
}