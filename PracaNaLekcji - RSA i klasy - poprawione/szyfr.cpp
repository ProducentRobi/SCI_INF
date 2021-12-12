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

int mod(int a, int b)
{
    for (int i = 1; i < b; i++)
        if (((a % b) * (i % b)) % b == 1)
            return i;
}

string szyfr::RSA(string wlasny_tekst_wejscie)
{
    int l1;
    int l2;
    cout << "Wybierz liczbe pierwsza" << endl;
    cin >> l1;
    cout << "Wybierz kolejna liczbe pierwsza" << endl;
    cin >> l2;

    int f = l1 * l2;
    int euler = (l1 - 1) * (l2 - 1);

    cout << "Wybierz liczbe od 1 do " << euler << endl;
    cout << "Liczba ta oraz " << euler << " musi byc wzglednie pierwsza" << endl;
    int e;
    cin >> e;
    int d = mod(e, euler);

    pair<int, int> pub;
    pub.first = f;
    pub.second = e;
    cout << "klucz publiczny: " << pub.first << " " << pub.second << endl;

    pair<int, int> pryw;
    pryw.first = f;
    pryw.second = d;
    cout << "klucz prywatny: " << pryw.first << " " << pryw.second << endl;
    return " ";
}