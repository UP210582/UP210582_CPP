/*
Date: 28/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Realizar un programa para jugar al gato
*/

#include <iostream>

using namespace std;

void Tablero(int);
int turno = 1;
char areaJuego[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int seleccionJugada();
void remplazoCasilla(int Jugada);
bool comprobarJugadaOcupada(int Jugada);
void modoDeJuego(int);


int main(){
    int tablero,Player1,Player2,computer,jugada;
    bool casillaEnUso = true;
    Tablero(tablero);
    jugada = seleccionJugada();
    casillaEnUso = comprobarJugadaOcupada(jugada);
    if (casillaEnUso == true)
    {
        do
        {
            cout << "Select another box\n";
            jugada = seleccionJugada();
        } while (casillaEnUso == true);
    }
    else if (casillaEnUso == false)
    {
        remplazoCasilla(jugada);
        system ("clear");
        Tablero(tablero);
        turno++;
    }
    
    return 0;
}



int seleccionJugada(){
    int Jugada;
    do
    {
    cout << "Dame tu jugada: \n";
    cin >> Jugada;
    } while (Jugada < 0 && Jugada >= 9);
    
    return Jugada;
}



bool comprobarJugadaOcupada(int Jugada){
int row = Jugada%3, col = Jugada-1; 
        if (areaJuego[row][col]=='X' || areaJuego[row][col]=='O')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

void remplazoCasilla(int Jugada){
    if (turno%2==0){
    int row = Jugada%3, col = Jugada - 1;
    char areaJuego[row][col]={'X'};
    }
    else
    {
    int row = Jugada%3, col = Jugada - 1;
    char areaJuego[row][col]={'O'};
    }
    
}

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