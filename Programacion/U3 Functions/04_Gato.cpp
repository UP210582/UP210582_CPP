/*
Date: 26/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Game of the TicTacToe
Last Modification: 10/10/2022
*/

#include <iostream>

using namespace std;

void imprimegato(int);
char gato[3][3];
void tabla(int);
int turnoJugador = 0;
char areaJuego[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int seleccionJugada();
void remplazoJugada(int Jugada);
bool comprobarJugadaOcupada(int Jugada);
void modeGame(int);
bool checkWinner(int Jugada);
void contraCpu(int);


int main()
{
    int tablero, P1, P2, PC, Game ,modeGame;
    bool casillaocupada = true, ganador = false;
    tabla(tablero);
    cout << "Do you want play whit CPU or Human?\n1. Human\n2. CPU\n";
    cin >> modeGame;
    if (modeGame=1)
    {
    do
    {
        Game  = seleccionJugada();
        casillaocupada = comprobarJugadaOcupada(Game );
        if (casillaocupada == true)
        {
            do
            {
                cout << "invalid box, choose another\n";
                break;
            } while (casillaocupada == true);
        }
        else if (casillaocupada == false)
        {
            system("clear");
            remplazoJugada(Game );
            tabla(tablero);
            turnoJugador++;
        }
    ganador = checkWinner(ganador);
    } while (ganador == false && turnoJugador<10);
    if (turnoJugador<10){
    if (turnoJugador % 2 == 0)
    {
        cout << "The Player 2 is the winner\n";
    }
    else
    {
        cout << "The Player 1 is the Winner\n";
    }
    } else{
        cout << "Empate\n";
    }
    } 
    else if (modeGame = 2)
    {
    do
    {
        Game  = seleccionJugada();
        casillaocupada = comprobarJugadaOcupada(Game );
        if (casillaocupada == true)
        {
            do
            {
                cout << "Choose antoher box\n";
                break;
            } while (casillaocupada == true);
        }
        else if (casillaocupada == false)
        {
            system("clear");
            remplazoJugada(Game );
            tabla(tablero);
            turnoJugador++;
            contraCpu(Game );
        }
    ganador = checkWinner(ganador);
    } while (ganador == false && turnoJugador<10);
    } else
    {
        cout << "Select a valid Game : ";
    }
    
    
    return 0;
}

int seleccionJugada()
{
    int Jugada;
    do
    {
        cout << "Jugador " << turnoJugador%2+1 << " Take me your game of 1 to 9 : \n";
        cin >> Jugada;
    } while (Jugada < 0 || Jugada > 9);

    return Jugada;
}

bool comprobarJugadaOcupada(int Jugada)
{
    int row = Jugada / 10, col = Jugada - 1;
    if (areaJuego[row][col] == 'X' || areaJuego[row][col] == 'O')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void remplazoJugada(int Jugada)
{
    if (turnoJugador % 2 == 0)
    {
        int row = Jugada / 10, col = Jugada - 1;
        areaJuego[row][col] = 'O';
    }
    else
    {
        int row = Jugada / 10, col = Jugada - 1;
        areaJuego[row][col] = 'X';
    }
}

void tabla(int)
{
    cout<<"\n     ######GATO#######\n\n";
    int x = 0, y = 0;
    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 9; columna++)
        {
            if (fila == 1 || fila == 3)
            {
                cout << "-";
            }
            else if (columna == 1 || columna == 4 || columna == 7)
            {
                cout << areaJuego[x][y];
                y++;
            }
            else
            {
                cout << " ";
            }
            if (columna == 2 || columna == 5)
            {
                cout << "|";
            }
        }
        cout << "\n";
        if (fila % 2 == 0)
        {
            x++;
        }

        y = 0;
    }
 
}

bool checkWinner(int Jugada)
{
    int punto = 0;
    bool checkWinner = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if ((areaJuego[0][posicion] == areaJuego[1][posicion]) && (areaJuego[0][posicion] == areaJuego[2][posicion]))
        {
            checkWinner = true;
            break;
        }
        else if ((areaJuego[posicion][0] == areaJuego[posicion][1]) && (areaJuego[posicion][0] == areaJuego[posicion][2]))
        {
            checkWinner = true;
            break;
        }
        else if ((areaJuego[posicion][posicion] == areaJuego[posicion+1][posicion+1]) && (areaJuego[posicion][posicion] == areaJuego[posicion+2][posicion+2]))
        {
            checkWinner = true;
            break;
        }
        else if ((areaJuego[2][0] == areaJuego[1][1]) && (areaJuego[2][0] == areaJuego[0][2]))
        {
            checkWinner = true;
            break;
        }
    }
    return checkWinner;
}

void contraCpu(int){
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (areaJuego[0][posicion] == areaJuego[1][posicion])
        {
            areaJuego[2][posicion] = 'O';
            break;
        }
        else if (areaJuego[0][posicion] == areaJuego[2][posicion])
        {
            areaJuego[1][posicion] = 'O';
            break;
        }
        else if (areaJuego[1][posicion] == areaJuego[2][posicion])
        {
            areaJuego[0][posicion] = 'O';
            break;
        }
        else if (areaJuego[posicion][0] == areaJuego[posicion][1])
        {
            areaJuego[posicion][2] = 'O';
            break;
        }
        else if (areaJuego[posicion][0] == areaJuego[posicion][2])
        {
            areaJuego[posicion][1] = 'O';
            break;
        }
        else if (areaJuego[posicion][1] == areaJuego[posicion][2])
        {
            areaJuego[posicion][0] = 'O';
            break;
        } else{
            areaJuego [posicion][posicion] = '0';
            break;
        }
    }
    
    turnoJugador++;
}