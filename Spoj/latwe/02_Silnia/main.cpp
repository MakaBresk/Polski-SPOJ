#include <iostream>

using namespace std;

int wprowadzonaSilnia = 0;

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

    if (liczbaTestow >= 1 && liczbaTestow <= 30)
    {
        while (liczbaTestow != 0)
        {
            cin >> wprowadzonaSilnia;
            if (wprowadzonaSilnia >= 0 && wprowadzonaSilnia <= 1000000000)
            {
                int cyfraDziesiatekWyniku;
                int cyfraJednosciWyniku;

                if (wprowadzonaSilnia <= 1)
                {
                    cyfraDziesiatekWyniku = 0;
                    cyfraJednosciWyniku = 1;
                }
                else
                {
                    if (wprowadzonaSilnia < 10)
                    {
                        int obliczonaSilnia = obliczSilnie(wprowadzonaSilnia);

                        cyfraDziesiatekWyniku = (obliczonaSilnia/10) % 10;
                        cyfraJednosciWyniku = obliczonaSilnia % 10;
                    }
                    else
                    {
                        cyfraDziesiatekWyniku = 0;
                        cyfraJednosciWyniku = 0;
                    }
                }

                cout << cyfraDziesiatekWyniku << " " << cyfraJednosciWyniku << endl;
            }
            liczbaTestow--;
        }
    }
    return 0;
}
