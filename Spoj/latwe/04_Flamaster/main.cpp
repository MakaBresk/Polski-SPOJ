#include <iostream>
#include <string> // to_string

using namespace std;

int main()
{
    int liczbaTestow;
    cin >> liczbaTestow;

    while (liczbaTestow > 0)
	{
		string wyraz;
		string skroconyWyraz;

		cin >> wyraz;

		int dlugoscWyrazu = wyraz.length();
		int i = 0, j = 1;
        int liczbaWystapienZnaku = 1;

        if (dlugoscWyrazu == 1)
            skroconyWyraz += wyraz[i];

        while (j < dlugoscWyrazu)
        {
            if (wyraz[i] == wyraz[j])
            {
                liczbaWystapienZnaku++;
                j++;
            }
            else
            {
                // Skrócenie wyrazu
                if (liczbaWystapienZnaku > 2)
                {
                    skroconyWyraz += wyraz[i];
                    skroconyWyraz += to_string(liczbaWystapienZnaku);
                }
                else
                {
                    int n = liczbaWystapienZnaku;

                    while (n != 0)
                    {
                        skroconyWyraz += wyraz[i];
                        n--;
                    }
                }

                i += liczbaWystapienZnaku;
                j++;
                liczbaWystapienZnaku = 1;
            }

            if (j == dlugoscWyrazu)
            {
                // Skrócenie wyrazu
                if (liczbaWystapienZnaku > 2)
                {
                    skroconyWyraz += wyraz[i];
                    skroconyWyraz += to_string(liczbaWystapienZnaku);
                }
                else
                {
                    int n = liczbaWystapienZnaku;

                    while (n != 0)
                    {
                        skroconyWyraz += wyraz[i];
                        n--;
                    }
                }
            }
        }
        cout << skroconyWyraz << endl;
		liczbaTestow--;
	}
    return 0;
}
