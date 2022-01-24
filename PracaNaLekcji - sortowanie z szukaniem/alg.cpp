#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

const int liczba_elementow = 10000;

algorytmy::algorytmy()
{
	srand(time(NULL));
	for (int i = 0; i < liczba_elementow; i++)
	{
		dane = rand() % 1000;
		wektor.push_back(dane);
	}
}

algorytmy::~algorytmy()
{
}

void algorytmy::zobacz()
{
	for (int i = 0; i < liczba_elementow; i++)
	{
		cout << wektor[i] << "   ";
	}
}

void algorytmy::QS(int lewo, int prawo)
{
	int i = (lewo + prawo) / 2;
	int obrot = wektor[i];
	wektor[i] = wektor[prawo];
	int k = lewo;

	for (i = lewo; i < prawo; i++)
	{
		if (wektor[i] < obrot)
		{
			swap(wektor[i], wektor[k]);
			k = k + 1;
		}
	}

	wektor[prawo] = wektor[k];
	wektor[k] = obrot;

	if (lewo < k - 1)
	{
		QS(lewo, k - 1);
	}

	if (k + 1 < prawo)
	{
		QS(k + 1, prawo);
	}
}

int algorytmy::szukanie(int l, int p)
{
	for (int i = l; i < wektor.size(); i++)
	{
		if (wektor[i] == p)
		{
			return i;
		}
	}
	return -1;
}

int algorytmy::szukanieV2(int lewo2, int prawo2, int liczba_do_szukania)
{
	liczenie++;

	int sred_arytmetyczna = (lewo2 + prawo2) / 2;
	if (prawo2 < lewo2)
	{
		return -1;
	}

	if (wektor[sred_arytmetyczna] == liczba_do_szukania)
	{
		return sred_arytmetyczna;
	}
	else if (wektor[sred_arytmetyczna] > liczba_do_szukania)
	{
		szukanieV2(lewo2, sred_arytmetyczna - 1, liczba_do_szukania);
	}
	else if (wektor[sred_arytmetyczna] < liczba_do_szukania)
	{
		szukanieV2(sred_arytmetyczna + 1, prawo2, liczba_do_szukania);
	}
}