#include <iostream>
#include <string> // length, to_string
#include <cstdlib> // atoi

using namespace std;

int ileDodawan = 0;

// Deklaracje funkcji
bool czyPalindrom(string x, int ileZnakow);
int szukajPalindromu(string x, int ileZnakow);

int main()
{
    // Pobranie liczby testów
    int liczbaTestow;
    cin >> liczbaTestow;

    while (liczbaTestow > 0)
    {
        string liczba;
        cin >> liczba;

        ileDodawan = 0;

        // Sprawdzenie początkowe, czy podana liczba jest palindromem
        if (czyPalindrom(liczba, liczba.length()) == true)
        {
            cout << liczba << ' ' << ileDodawan << endl;
        }
        else // Jeżeli nie, to wyznaczenie tej liczby
        {
            // Zapisanie wyniku zwróconej przez funkcję
            int result = szukajPalindromu(liczba, liczba.length());

            cout << result << ' ' << ileDodawan << endl;
        }
        liczbaTestow--;
    }
    return 0;
}

// Sprawdzenie czy liczba jest palindromem
bool czyPalindrom(string x, int ileZnakow)
{
    int i = 0;

    for (int j = (ileZnakow-1); j >= 0; j--)
    {
        if (x[i] != x[j])
            return false;
        i++;
    }
    return true;
}

// Wyznaczenie palindromu na podstawie otrzymanych wyników
int szukajPalindromu(string x, int ileZnakow)
{
    int sumaLiczb = atoi(x.c_str());
    string sumaLiczbStr;

    do
    {
        int liczbaPiotrusia = sumaLiczb;
        string liczbaPiotrusiaStr = to_string(sumaLiczb);
        string liczbaOdwrotna;

        // Wyznaczenie liczby odwrotnej
        for (int i = (liczbaPiotrusiaStr.length()-1); i >= 0; i--)
             liczbaOdwrotna += liczbaPiotrusiaStr[i];

        int odwrotnoscLiczbyPiotrusia = atoi(liczbaOdwrotna.c_str());

        // Wyznaczenie sumy
        sumaLiczb = liczbaPiotrusia + odwrotnoscLiczbyPiotrusia;
        sumaLiczbStr = to_string(sumaLiczb);

        ileDodawan++;
    }
    while (czyPalindrom(sumaLiczbStr, sumaLiczbStr.length()) == false);

    // Zwrócenie wyniku przez funkcję
    return sumaLiczb;
}
