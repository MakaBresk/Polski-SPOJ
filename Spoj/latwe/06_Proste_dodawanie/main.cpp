#include <iostream>
#include <string> // substr
#include <cstdlib> // atoi

using namespace std;

int main()
{
    string line;

    // Pobranie liczby testów
    getline(cin, line);
    int liczbaTestow = atoi(line.c_str());

    while (liczbaTestow > 0)
    {
        // Ile liczb do zsumowania
        getline(cin, line);

        int ileLiczb = atoi(line.c_str());
        int tablica[ileLiczb] = {}; // Zadeklarowanie pustej tablicy

        // Pobranie liczb do zsumowania
        getline(cin, line);

        string liczba;
        int dlugoscLancucha = line.length();
        int ileZnakowDoSpacji = 0;
        int j = 0;

        for (int i = 0; i < dlugoscLancucha; i++)
        {
            // Zliczanie liczby znaków do wystąpienia znaku "spacji"
            if (line[i] != ' ')
                ileZnakowDoSpacji++;
            else
            {
                // Wycinanie poszczególnych liczb z łańcucha
                liczba = line.substr(i - ileZnakowDoSpacji, ileZnakowDoSpacji);
                tablica[j] = atoi(liczba.c_str()); // Konwersja string na int

                j++;
                ileZnakowDoSpacji = 0;
            }

            // Ostatni przebieg pętli
            if (i == dlugoscLancucha-1)
            {
                // Wycięcie ostatniej liczby z łańcucha
                liczba = line.substr(i - (ileZnakowDoSpacji-1), ileZnakowDoSpacji);
                tablica[j] = atoi(liczba.c_str()); // Konwersja string na int
                j++;
            }
        }

        // Sumowanie poszczególnych liczb
        int sumaLiczb = 0;
        for (int i = 0; i < ileLiczb; i++)
            sumaLiczb += tablica[i];

        liczbaTestow--;
    }
    return 0;
}
