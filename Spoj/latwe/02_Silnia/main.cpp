#include <iostream>

using namespace std;

int liczba = 0;
int obliczSilnie(int value)
{
    int wynikSilni = 1;

    for (int i = 2; i <= value; i++)
        wynikSilni *= i;

    return wynikSilni;
}

int main()
{
    int liczbaTestow;
    cin >> liczbaTestow;

    while (liczbaTestow != 0)
    {
        cin >> liczba;

        int cyfraDziesiatekWyniku;
        int cyfraJednosciWyniku;

        if (liczba == 1)
        {
            cyfraDziesiatekWyniku = 0;
            cyfraJednosciWyniku = 1;
        }
        else
        {
            if (liczba < 10)
            {
                int wynikSilni = obliczSilnie(liczba);

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
