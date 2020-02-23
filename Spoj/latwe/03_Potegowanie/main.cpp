#include <iostream>
#include <string> // substr()
#include <cstdlib> // atoi()

using namespace std;

int podstawaPotegi = 0;
int wykladnikPotegi = 0;

int obliczPotege(int podstawa, int wykladnik);

int main()
{
    string line;

    getline(cin, line); // Wczytywanie tekstu wierszami
    int liczbaTestow = atoi(line.c_str()); // Konwersja string na int

    while (liczbaTestow != 0)
    {
        getline(cin, line); // Wczytywanie tekstu wierszami
        size_t pozycjaZnakuSpacji = line.find(' ');

        // Przekopiowanie liczb znajdujących się w łańcuchu do osobnych zmiennych, a następnie konwersja string na int
        string podstawaPotegi_str = line.substr(0, pozycjaZnakuSpacji);
        podstawaPotegi = atoi(podstawaPotegi_str.c_str());

        string wykladnikPotegi_str = line.substr(pozycjaZnakuSpacji+1,line.length());
        wykladnikPotegi = atoi(wykladnikPotegi_str.c_str());

        // % - reszta z dzielenia
        int cyfraJednosciWyniku = obliczPotege(podstawaPotegi, wykladnikPotegi) % 10; // Wywołanie funkcji
        cout << cyfraJednosciWyniku << endl;

        liczbaTestow--;
    }
    return 0;
}

int obliczPotege(int podstawa, int wykladnik)
{
    if (wykladnik == 1)
        return podstawa;

    int wynik = 0;
    switch (podstawa % 10)
    {
        case 1: // 1, 11, 21, ...
            wynik = 1;
        break;

        case 2: // 2, 12, 22, ...
        {
            switch (wykladnik % 4)
            {
                case 1:
                    wynik = 2;
                break;

                case 2:
                    wynik = 4;
                break;

                case 3:
                    wynik = 8;
                break;

                case 0:
                    wynik = 6;
                break;
            }
        }
        break;

        case 3: // 3, 13, 23, ...
        {
            switch (wykladnik % 4)
            {
                case 1:
                    wynik = 3;
                break;

                case 2:
                    wynik = 9;
                break;

                case 3:
                    wynik = 7;
                break;

                case 0:
                    wynik = 1;
                break;
            }
        }
        break;

        case 4: // 4, 14, 24, ...
        {
            if (wykladnik % 4 == 1 || wykladnik % 4 == 3)
                wynik = 4;
            else
                wynik = 6;
        }
        break;

        case 5: // 5, 15, 25, ...
            wynik = 5;
        break;

        case 6: // 6, 16, 26, ...
            wynik = 6;
        break;

        case 7: // 7, 17, 27, ...
        {
            switch (wykladnik % 4)
            {
                case 1:
                    wynik = 7;
                break;

                case 2:
                    wynik = 9;
                break;

                case 3:
                    wynik = 3;
                break;

                case 0:
                    wynik = 1;
                break;
            }
        }
        break;

        case 8: // 8, 18, 28, ...
        {
            switch (wykladnik % 4)
            {
                case 1:
                    wynik = 8;
                break;

                case 2:
                    wynik = 4;
                break;

                case 3:
                    wynik = 2;
                break;

                case 0:
                    wynik = 6;
                break;
            }
        }
        break;

        case 9: // 9, 19, 29, ...
        {
            if (wykladnik % 4 == 1 || wykladnik % 4 == 3)
                wynik = 9;
            else
                wynik = 1;
        }
        break;

        case 0: // 10, 20, 30, ...
            wynik = 0;
        break;
    }
    return wynik;
}
