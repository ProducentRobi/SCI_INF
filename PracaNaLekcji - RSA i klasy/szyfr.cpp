#include <iostream>
#include <string>
#include "szyfr.h"

using namespace std;


int main()
{
    int wybor_rodzaju_szyfrowania;
    string wlasny_tekst_wejscie, wlasny_tekst_wyjscie;
    szyfr szyfrik;
    cout << "Podaj swoj tekst: ";
    getline(cin, wlasny_tekst_wejscie);
    cout << "Wybierz rodzaj szyfrowania (podaj liczbe)" << endl;
    cout << "1. Szyf cezara" << endl;
    cout << "2. Szyfr przestawieniowy" << endl;
    cout << "3. Szyfr Cezara i przestawieniowy" << endl;
    cout << "4. Odszyfruj szyfr cezara" << endl;
    cout << "5. RSA" << endl;
    cin >> wybor_rodzaju_szyfrowania;
    if (wybor_rodzaju_szyfrowania == 1)
    {
        wlasny_tekst_wyjscie = szyfrik.szyfr_cezara(wlasny_tekst_wejscie);
        cout << "Tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == 2)
    {
        wlasny_tekst_wyjscie = szyfrik.przestawienie(wlasny_tekst_wejscie);
        cout << "Tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == 3)
    {
        wlasny_tekst_wyjscie = szyfrik.cezar_przestawienie(wlasny_tekst_wejscie);
        cout << "Tekst zaszyfrowany to: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == 4)
    {
        wlasny_tekst_wyjscie = szyfrik.deszyfracja(wlasny_tekst_wejscie);
        cout << "Tekst wyjsciowy brzmi: " << wlasny_tekst_wyjscie << endl;
    }
    else if (wybor_rodzaju_szyfrowania == 5)
    {
        wlasny_tekst_wyjscie = szyfrik.RSA(wlasny_tekst_wejscie);
    }
    else
    {
        cout << endl;
        cout << "Wybrany zly rodzaj szyfrowania, uruchom program ponownie" << endl;
    }
}