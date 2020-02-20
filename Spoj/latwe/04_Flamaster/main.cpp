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

    while (liczbaTestow > 0)
	{
		string wyraz;
		string skroconyWyraz = ""; // Czyszczenie łańcucha znaków

		cin >> wyraz;
		int dlugoscWyrazu = wyraz.length();

		// Sprawdzenie czy wyraz nie jest pusty
		if (dlugoscWyrazu != 0)
		{
		    char sprawdzoneZnaki[dlugoscWyrazu-1];
		    memset(sprawdzoneZnaki,'-',dlugoscWyrazu);

            for (int i = 0; i < dlugoscWyrazu; i++)
            {
                int liczbaWystapienZnaku = 0; // Zerowanie liczby wystąpień danego znaku
                char sprawdzanyZnak = wyraz[i];
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
		liczbaTestow--;
	}
    return 0;
}
