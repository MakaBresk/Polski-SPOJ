#include <iostream>
#include <sstream> // ostringstream

using namespace std;

int main()
{
    int liczbaTestow;
    cin >> liczbaTestow;

    while (liczbaTestow > 0)
	{
		string wyraz;
		string skroconyWyraz = ""; // Czyszczenie zawartości łańcucha

		cin >> wyraz;
		int dlugoscWyrazu = wyraz.length();

		// Sprawdzenie czy wyraz nie jest pusty
		if (dlugoscWyrazu != 0)
		{
		    string sprawdzoneZnaki;
		    int liczbaSprawdzonychZnakow;

            for (int i = 0; i < dlugoscWyrazu; i++)
            {
                int liczbaWystapienZnaku = 0; // Zerowanie liczby wystąpień danego znaku
                liczbaSprawdzonychZnakow = sprawdzoneZnaki.length();
                char sprawdzanyZnak = wyraz[i];
                bool czyLiczycZnaki = true;

                // Sprawdzenie czy znak był sprawdzony
                for (int j = 0; j < liczbaSprawdzonychZnakow; j++)
                {
                    if (sprawdzanyZnak == sprawdzoneZnaki[j])
                    {
                        czyLiczycZnaki = false;
                        break;
                    }
                }

                // Zliczanie znaków bez powtórzeń
                if (czyLiczycZnaki == true)
                {
                    sprawdzoneZnaki += sprawdzanyZnak;

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

            liczbaSprawdzonychZnakow = 0; // Zerowanie rozmiaru łańcucha
            sprawdzoneZnaki = ""; // Czyszczenie zawartości łańcucha

			cout << skroconyWyraz << endl;
		}
		liczbaTestow--;
	}
    return 0;
}
