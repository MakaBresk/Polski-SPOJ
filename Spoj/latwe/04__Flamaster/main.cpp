#include <iostream>
#include <sstream> // ostringstream
#include <string.h> // memset

using namespace std;

/* TODO:
    1. Tablica sprawdzonych znaków (bez powtórzeń)
*/

int main()
{
    int liczbaTestow = 0;
    cin >> liczbaTestow;

    if (liczbaTestow >= 1 && liczbaTestow <= 50)
    {
        string wyraz;
        string skroconyWyraz;

        while (liczbaTestow != 0)
        {
            skroconyWyraz = ""; // Czyszczenie łańcucha znaków

            cin >> wyraz;
            int dlugoscWyrazu = wyraz.length();

            // Sprawdzenie czy wyraz nie przekracza 200 znaków
            if (dlugoscWyrazu > 0 && dlugoscWyrazu <= 200)
            {
                int liczbaWystapienZnaku;
                char sprawdzanyZnak;
                char sprawdzoneZnaki[dlugoscWyrazu-1];

                // Wypełnienie tablicy znakami -
                memset(sprawdzoneZnaki, '-', dlugoscWyrazu-1);

                cout << "Zawartosc tablicy przed: " << endl;
                for (int i = 0; i < dlugoscWyrazu; i++)
                cout << sprawdzoneZnaki[i] << ", ";

                for (int i = 0; i < dlugoscWyrazu; i++)
                {
                    liczbaWystapienZnaku = 0; // Zerowanie liczby wystąpień danego znaku
                    sprawdzanyZnak = wyraz[i];
                    bool czyLiczycZnaki = true;

                    // Sprawdzenie czy znak był sprawdzony
                    for (int j = 0; j < dlugoscWyrazu; j++)
                    {
                        if (sprawdzanyZnak == sprawdzoneZnaki[j])
                        {
                            czyLiczycZnaki = false;
                            break;
                        }
                    }

                    if (czyLiczycZnaki == true)
                    {
                        sprawdzoneZnaki[i] = sprawdzanyZnak;

                        // Zliczenie liczby wystąpień sprawdzanego znaku
                        for (int k = 0; k < dlugoscWyrazu; k++)
                        {
                            if (wyraz[k] == sprawdzanyZnak)
                                liczbaWystapienZnaku++;
                        }

                        // Skrócenie wyrazu
                        if (liczbaWystapienZnaku > 2)
                        {
                            ostringstream ss;
                            ss << sprawdzanyZnak << liczbaWystapienZnaku;

                            skroconyWyraz += ss.str();

                        }
                        else
                        {
                            while (liczbaWystapienZnaku != 0)
                            {
                                skroconyWyraz += sprawdzanyZnak;
                                liczbaWystapienZnaku--;
                            }
                        }
                    }
                }

                cout << endl << "Zawartosc tablicy po: " << endl;
                for (int i = 0; i < dlugoscWyrazu; i++)
                cout << sprawdzoneZnaki[i] << ", ";
            }
            cout << skroconyWyraz << endl;
            liczbaTestow--;
        }
    }
    return 0;
}
