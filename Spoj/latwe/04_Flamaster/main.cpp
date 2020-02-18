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
        while (liczbaTestow != 0)
        {
            string wyraz;
            string skroconyWyraz = ""; // Czyszczenie łańcucha znaków

            cin >> wyraz;
            int dlugoscWyrazu = wyraz.length();

            // Sprawdzenie czy wyraz nie przekracza 200 znaków
            if (dlugoscWyrazu > 0 && dlugoscWyrazu <= 200)
            {
                bool czyAlfabetAmerykanski = false;
                char sprawdzoneZnaki[dlugoscWyrazu-1];

                // Wypełnienie tablicy znakami -, w przeciwnym wypadku tablica może mieć losową zawartość
                memset(sprawdzoneZnaki, '-', dlugoscWyrazu-1);

                // Sprawdzenie czy wyraz składa się z samych dużych liter alfabetu amerykańskiego (A-Z)
                for (int i = 0; i < dlugoscWyrazu; i++)
                {
                    if ((int)wyraz[i] >= 65 && (int)wyraz[i] <= 90) // Tabela znaków ASCII
                        czyAlfabetAmerykanski = true;
                    else
                        czyAlfabetAmerykanski = false;
                }

                if (czyAlfabetAmerykanski == true)
                {
                    int liczbaWystapienZnaku;
                    char sprawdzanyZnak;

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
                cout << skroconyWyraz << endl;
                }
            }
            liczbaTestow--;
        }
    }
    return 0;
}
