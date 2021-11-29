#include "szyfr.h"
#include <iostream>
#include <string>

string wlasny_tekst_wejscie, wlasny_tekst_wyjscie;
int cyfra;

string szyfr::szyfr_cezara(string wlasny_tekst_wejscie)
{
    string string_dane;
    cout << "wypisz o ile chcesz przesunac szyfr (przedzial 1-26): ";
    cin >> cyfra;

    for (int i = 0; i < wlasny_tekst_wejscie.size(); i++)
    {
        if (wlasny_tekst_wejscie[i] > 96)
        {
            char dane;
            dane = wlasny_tekst_wejscie[i] + cyfra;
            if (dane > 124)
            {
                dane = (dane % 123) + 97;

            }
            string_dane = string_dane + dane;
        }
        else
        {
            string_dane = string_dane + wlasny_tekst_wejscie[i];
        }
    }

    return string_dane;
}

string szyfr::przestawienie(string wlasny_tekst_wejscie)
{
    string string_dane;
    char daneA;

    for (int i = 0; i < wlasny_tekst_wejscie.size() - 1; i = i + 2)
    {
        swap(wlasny_tekst_wejscie[i], wlasny_tekst_wejscie[i + 1]);
        daneA = wlasny_tekst_wejscie[i];
        string_dane = string_dane + daneA;
        daneA = wlasny_tekst_wejscie[i + 1];
        string_dane = string_dane + daneA;
    }
    if (wlasny_tekst_wejscie.size() % 2 == 1)
    {
        daneA = wlasny_tekst_wejscie[wlasny_tekst_wejscie.size() - 1];
        string_dane = string_dane + daneA;
    }
    return string_dane;
}

string szyfr::cezar_przestawienie(string wlasny_tekst_wejscie)
{
    string dane;

    wlasny_tekst_wyjscie = szyfr_cezara(przestawienie(wlasny_tekst_wejscie));
    return wlasny_tekst_wyjscie;
}

string szyfr::deszyfracja(string wlasny_tekst_wejscie)
{
    string string_dane;
    cout << "Wypisz o ile chcesz przesunac szyfr (przedzial 1 - 26): ";
    cin >> cyfra;
    for (int i = 0; i < wlasny_tekst_wejscie.size(); i++)
    {
        if (wlasny_tekst_wejscie[i] > 96)
        {
            char dane;
            dane = wlasny_tekst_wejscie[i] - cyfra;
            if (dane < 97)
            {
                char x;
                x = (wlasny_tekst_wejscie[i] % 97) + 123;
                x = x - cyfra;
                dane = x;
            }
            string_dane = string_dane + dane;
        }
        else
        {
            string_dane = string_dane + wlasny_tekst_wejscie[i];
        }
    }
    return string_dane;
}

int odwrotnosc_modulo(int a, int b)
{
    for (int t = 1; t < b; t++)
        if (((a % b) * (t % b)) % b == 1)
            return t;
}

string szyfr::RSA(string wlasny_tekst_wejscie)
{
    int liczba_pierwsza1, lizba_pierwsza2;
    cout << "Podaj 1 liczbe pierwsza: ";
    cin >> liczba_pierwsza1;
    cout << "Podaj 1 liczbe pierwsza: ";
    cin >> lizba_pierwsza2;
    int l = liczba_pierwsza1 * lizba_pierwsza2;
    int z = (liczba_pierwsza1 - 1) * (lizba_pierwsza2 - 1);
    cout << "Podaj liczbe z przedzialu od 1 do " << z << endl;
    cout << "Ta liczba i " << z << " powinny byc wzglednie pierwsze" << endl;
    int e; 
    cin >> e;
    int m; 
    m = odwrotnosc_modulo(e, z);

    pair<int, int> publiczny;
    publiczny.first = l;
    publiczny.second = e;
    cout << "Klucz publiczny: " << publiczny.first << " - " << publiczny.second << endl;
    pair<int, int> prywatny;
    prywatny.first = l;
    prywatny.second = m;
    cout << "Klucz prywatny: " << prywatny.first << " - " << prywatny.second << endl;
    return " ";
}