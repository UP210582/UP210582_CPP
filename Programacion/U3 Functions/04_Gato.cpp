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
char creaJuego[3][3]={{"1","2","3"},{"4","5","6"},{"7","8","9"}};
int seleccionarJugada({
    do
    {
        cout << "Dame tu jugada: ";
        cin >> jugada;
    
    } while (jugada <= 9 && jugada > 0);
    
    return jugada;
}

bool comprobarCasillaOcupada(int jugada){
   int row;
   int col;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
    {
        row = 2;
        col = 2;
    }
    
    
    if (areaJuego[row][col]== "x"|| areaJuego[row][col]== "o")
    {
        return true;
    }
    else
    {
        return false;
    }
        
}
int main (){
    int jugada; 
    bool casillaOcupada = true;
    do
    {
    jugada = seleccionarJugada();
    casillaOcupada = comprobarCasillaOcupada(jugada)
    if (casillaOcupada == false)
    {
        colocarJuagada(jugada);
        system ("clear");
        tablero();
    }    
    
        cout << "otra vez";
    } while (casillaOcupada == true);
    
}
int turnoJugador = 1;
    void colocarJuagada(int jugada){
        char valorJugada;
        if (turnoJugador % 2 == 0)
        {
            valorJugada = "x";
        }
        else
        {
            valorJugada = "O";
        }
        
        if (jugada == 1)
        {
            areaJuego[0][0] = valorJugada;
        }
    }