#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class algorytmy
{
public:
	vector<int> wektor;
	int dane, dane2;
	int liczenie;
	algorytmy();
	~algorytmy();
	void zobacz();
	void QS(int lewo, int prawo);
	int szukanie(int l, int p);
	int szukanieV2(int lewo2, int prawo2, int liczba_do_szukania);
};