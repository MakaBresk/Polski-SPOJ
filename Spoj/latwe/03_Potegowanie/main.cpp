#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int podstawaPotegi = 0;
int wykladnikPotegi = 0;

int obliczPotege(int podstawa, int wykladnik)
{
    switch(wykladnik)
    {
        case 1:
            return podstawa;
        break;
    }

    if (podstawa == 10)
        return 0;

    int wynikKoncowy = podstawa;
    for (int i = 1; i < wykladnik; i++)
    {
        wynikKoncowy *= podstawa;
    }
    return wynikKoncowy;
}

int main()
{
    string line;
    getline(cin, line); // Wczytywanie tekstu wierszami

    int liczbaTestow = atoi(line.c_str()); // Konwersja string na int
    if (liczbaTestow >= 1 && liczbaTestow <= 10)
    {
        while (liczbaTestow != 0)
        {
            int cyfraJednosciWyniku = 0;
            int ileZnakow = 0;

            getline(cin, line); // Wczytywanie tekstu wierszami

            // Zliczenie liczby znaków do spacji
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                    ileZnakow++;
                else
                    break;
            }

            // Przekopiowanie liczb znajdujących się w łańcuchu do osobnych zmiennych, a następnie konwersja string na int
            string podstawaPotegi_str = line.substr(0, ileZnakow);
            podstawaPotegi = atoi(podstawaPotegi_str.c_str());

            string wykladnikPotegi_str = line.substr(ileZnakow+1,line.length());
            wykladnikPotegi = atoi(wykladnikPotegi_str.c_str());

            // Sprawdzenie przedziału w jakim znajdują się podane liczby, a następnie wywołanie funkcji
            if ((podstawaPotegi >= 1 && podstawaPotegi <= 1000000000) && (wykladnikPotegi >= 1 && wykladnikPotegi <= 1000000000))
                cyfraJednosciWyniku = obliczPotege(podstawaPotegi, wykladnikPotegi) % 10;

            cout << cyfraJednosciWyniku << endl;
            liczbaTestow--;
        }
    }
    return 0;
}
