#include <iostream>

using namespace std;

int liczba = 0;
bool czyPierwsza(int value)
{
    if (value == 1)
        return false;

    for (int i = 2; i < value; i++)
    {
        // Sprawdzenie czy reszta z dzielenia jest równa 0
        if (value % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int liczbaTestow;
    cin >> liczbaTestow;

    while (liczbaTestow != 0)
    {
        cin >> liczba;

        if (czyPierwsza(liczba) == true) // Wywołanie funkcji
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;

        liczbaTestow--;
    }
    return 0;
}
