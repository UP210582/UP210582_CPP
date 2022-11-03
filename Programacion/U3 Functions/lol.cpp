/*
Date: 28/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Realizar un programa para jugar al gato
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;
void tablero();
int main()
{
    char forma[6][11];
    for (int row = 0; row < 6; row++)
    {
        for (int  col = 0; col < 11; col++)
        {
            (col == 3 || col == 7) ? forma[row][col]='|'
                :(row==1 || row == 3) ? forma[row][col]='_'
                    : forma[row][col]=' ';
        }
    }
    for (int row = 0; row < 6; row++)
    {
        for (int  col = 0; col < 11; col++)
        {
            cout << forma[row][col];
        }
        cout << endl;
    }
    return 0;
}
void tablero(){
}