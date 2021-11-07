#include <iostream>
#include <string>

using namespace std;

string wlasny_tekst_wejscie, wlasny_tekst_wyjscie;
char wybor_rodzaju_szyfrowania;
int cyfra;

string cezar(string wlasny_tekst_wejscie)
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
                dane = (dane %123) + 97;

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

string przestawienie(string wlasny_tekst_wejscie)
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
    if (wlasny_tekst_wejscie.size() %2 == 1)
    {
        daneA = wlasny_tekst_wejscie[wlasny_tekst_wejscie.size() - 1];
        string_dane = string_dane + daneA;
    }
    return string_dane;
}

string cezarPrzestawienie(string wlasny_tekst_wejscie)
{
    string dane;

    wlasny_tekst_wyjscie = cezar(przestawienie(wlasny_tekst_wejscie));
    return wlasny_tekst_wyjscie;
}

string deszyfr(string wlasny_tekst_wejscie)
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
                x = (wlasny_tekst_wejscie[i] %97) + 123;
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

int main()
{
    cout << "Podaj swoj tekst: ";
    getline(cin, wlasny_tekst_wejscie);
    cout << "Wybierz rodzaj szyfrowania (podaj liczbe)" << endl; 
    cout << "1. Szyf cezara" << endl;
    cout << "2. Szyfr przestawieniowy" << endl;
    cout << "3. Szyfr Cezara i przestawieniowy" << endl;
    cout << "4. odszyfruj szyfr cezara" << endl;
    cin >> wybor_rodzaju_szyfrowania;
    if (wybor_rodzaju_szyfrowania == '1')
    {
        wlasny_tekst_wyjscie = cezar(wlasny_tekst_wejscie);
        cout << "tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == '2')
    {
        wlasny_tekst_wyjscie = przestawienie(wlasny_tekst_wejscie);
        cout << "tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == '3')
    {
        wlasny_tekst_wyjscie = cezarPrzestawienie(wlasny_tekst_wejscie);
        cout << "tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == '4')
    {
        wlasny_tekst_wyjscie = deszyfr(wlasny_tekst_wejscie);
        cout << "tekst wyjsciowy brzmi: " << wlasny_tekst_wyjscie << endl;
    }
    else 
    {
        cout << endl;
        cout << "Wybrany zly rodzaj szyfrowania, uruchom program ponownie" << endl;
    }
}