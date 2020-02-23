#include <iostream>

using namespace std;

int wprowadzonaLiczba = 0;
int obliczSilnie(int value)
{
    int wynikSilni = 1;

    for (int i = 2; i <= value; i++)
        wynikSilni *= i;

    return wynikSilni;
}

int main()
{
    int liczbaTestow = 0;
    cin >> liczbaTestow;

    while (liczbaTestow != 0)
    {
        cin >> wprowadzonaLiczba;

        int cyfraDziesiatekWyniku;
        int cyfraJednosciWyniku;

        if (wprowadzonaLiczba == 1)
        {
            cyfraDziesiatekWyniku = 0;
            cyfraJednosciWyniku = 1;
        }
        else
        {
            if (wprowadzonaLiczba < 10)
            {
                int wynikSilni = obliczSilnie(wprowadzonaLiczba);

                // % - reszta z dzielenia
                cyfraDziesiatekWyniku = (wynikSilni/10) % 10;
                cyfraJednosciWyniku = wynikSilni % 10;
            }
            else
            {
                cyfraDziesiatekWyniku = 0;
                cyfraJednosciWyniku = 0;
            }
        }

        cout << cyfraDziesiatekWyniku << " " << cyfraJednosciWyniku << endl;

        liczbaTestow--;
    }
    return 0;
}
