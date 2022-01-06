/* int plansza [8][8]
0 - pole biale
1- pole czarne
2 - pionek bialy
3 - pionek czarny
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>

void inicjalizacja_planszy(int plansza[8][8])
{
    // 1 cześć czy to jest liczba parzysta czyli jesli j bedzie parzyste to bedzie 0 jesli i bedzie parzyste to bedzie 2
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            if(j % 2 == 0)
            {
                if(i % 2 == 0)
                {
                    plansza[j][i] = 0;
                }
                else
                {
                    plansza[j][i] = 2;
                }
            }
            else 
            {
                if(i % 2)
                {
                    plansza[j][i] = 2;
                }
                else
                {
                    plansza[j][i] = 0;
                }
            }
        }
    }
}

int main()
{
    int plansza[8][8];

    inicjalizacja_planszy(plansza);
    std::cout << plansza[0][1];

    for(int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << plansza[j][i];
        }
    }
}
