#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Deklaracja funkcji
int nwd(int a, int b);

int main()
{
    string line;
    getline(cin, line);

    int liczbaTestow = atoi(line.c_str());

    while (liczbaTestow > 0)
    {
        getline(cin, line);

        // Konwersje liczb
        size_t pozycjaSpacji = line.find(' ');
        string liczbaA = line.substr(0, pozycjaSpacji);
        string liczbaB = line.substr(pozycjaSpacji+1, line.length());

        int x = atoi(liczbaA.c_str());
        int y = atoi(liczbaB.c_str());

        int result;

        // Obliczenie NWD
        if (x == 0 && y == 0)
            result = 0;
        else if (x == 1 || y == 1)
            result = 1;
        else if (x == y)
            result = x;
        else
            result = nwd(x, y);

        // Wyświetlenie wyniku
        cout << result << endl;

        liczbaTestow--;
    }
    return 0;
}

int nwd(int a, int b)
{
    int i = a;
    int j = b;
    int reszta = 0;

    do
    {
        reszta = i % j;

        if (reszta != 0)
        {
            i = j;
            j = reszta;
        }
    }
    while (i % j != 0);

    int wynik = reszta;
    return wynik;
}
