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
   
void Tablero(int){
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
}
}
int x=0, y=0;
    for (int fila = 0; fila < 5; fila++)
    {
            for (int columna = 0; columna < 9; columna++)
            {
                if (fila== 1 || fila == 3){
                    cout << "-";
                }else{
                    cout << " " << areaJuego[x][y] << " |";
                    y++;
                }
                if (columna==2 || columna == 5)
                {
                    cout<<"|";
                }
                
            }
        cout << "\n";
        x++;
        y = 0;
    }