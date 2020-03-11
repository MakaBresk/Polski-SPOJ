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
        int i = 0;

        while (true)
        {
            if (liczbaPrzedszkolakowGrupaA == liczbaPrzedszkolakowGrupaB)
            {
                liczbaCukierkow = liczbaPrzedszkolakowGrupaA;
                break;
            }
            else if ()
            {

            }
            else
        }

        cout << liczbaCukierkow << endl;

        liczbaTestow--;
    }

    return 0;
}
