#include <iostream>
#include <string> // substr()
#include <cstdlib> // atoi()

using namespace std;

int main()
{
    // Wczytanie liczby testów
    string line;
    getline(cin, line);

    // Konwersja string na int
    int liczbaTestow = atoi(line.c_str());

    while (liczbaTestow > 0)
    {
        // Wczytanie zestawu danych
        getline(cin, line);

        // Zapisanie liczby przedszkolaków dla poszczególnych grup
        size_t pozycjaZnakuSpacji  = line.find(' ');

        string a = line.substr(0, pozycjaZnakuSpacji);
        string b = line.substr(pozycjaZnakuSpacji+1, line.length());
        int liczbaPrzedszkolakowGrupaB = atoi(b.c_str());
        int liczbaPrzedszkolakowGrupaA = atoi(a.c_str());

        int liczbaCukierkow = 0;
        int i = 2;

        // Obliczenie liczby cukierków
        if (liczbaPrzedszkolakowGrupaA == liczbaPrzedszkolakowGrupaB)
            liczbaCukierkow = liczbaPrzedszkolakowGrupaA;
        else
        {
            while (true)
            {
                liczbaCukierkow = liczbaPrzedszkolakowGrupaA * i;

                // Przerwanie pętli gdy reszta z dzielenia wyniesie 0
                if (liczbaCukierkow % liczbaPrzedszkolakowGrupaB == 0)
                    break;
                i++;
            }
        }

        cout << liczbaCukierkow << endl;
        liczbaTestow--;
    }
    return 0;
}
