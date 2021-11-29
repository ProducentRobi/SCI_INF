#pragma once
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class szyfr
{
public:
	string szyfr_cezara(string wlasny_tekst_wejscie);
	string przestawienie(string wlasny_tekst_wejscie);
	string cezar_przestawienie(string wlasny_tekst_wejscie);
	string deszyfracja(string wlasny_tekst_wejscie);
	string RSA(string wlasny_tekst_wejscie);
};

