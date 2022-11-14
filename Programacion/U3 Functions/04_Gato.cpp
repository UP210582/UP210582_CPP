/*
Date: 28/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Tic Tac toe
Last Modification: 14/10/2022
*/

//used bookstores
#include <iostream>
#include <stdalign.h>
#include <time.h>

// Use of namespace to avoid std::
using namespace std;

void hacerTablero();
int seleccionJugada();
bool compruebaJugada(int, string);
void ponerJugada(int, string, string);
bool ganar(string);
int obtencionJugada();
void clonMatriz();
int obtenerMejorJugada(string);
char structureGato[6][11];
char areaDeJuego[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char areaDeJuegoDePc[3][3];
int turnosJugador = 1;
int row, col;
const string PC = "Robot";
const string HUMANO = "Humano";
const string TABLERO = "Real";
const string TABLEROIMAG = "Imaginario";

int main()
{
    bool gameover = false;
    int jugada;
    bool casillaOcupada = true;
    int modo;
    cout <<"\x1b[0;31m" << "Welcome to the game of TicTacToe" <<"\x1b[0m"<< endl;
    cout <<"\x1b[0;36m"<<"Choose your game mode"<<"\x1b[0m"<< endl;
    cout <<"\x1B[38;2;17;245;120m"<<"1 Singleplayer"<<"\x1B[0m"<< endl;
    cout << "2 Multiplayer" << endl;
    cin >> modo;
    if (modo == 1)
    {
        do
        {
            system("clear");
            if (turnosJugador % 2 == !0)
            {
                do
                {
                    hacerTablero();
                    jugada = seleccionJugada();
                    casillaOcupada = compruebaJugada(jugada, TABLERO);
                    if (casillaOcupada == true)
                    {
                        system("clear");
                        cout << "Trye again \n";
                    }
                } while (casillaOcupada == true);
                ponerJugada(jugada, TABLERO, HUMANO);
                gameover = ganar(TABLERO);
            }
            else
            {
                hacerTablero();
                jugada = obtencionJugada();
                ponerJugada(jugada, TABLERO, PC);
                gameover = ganar(TABLERO);
            }
        } while (gameover == false and turnosJugador < 10);
        system("clear");
        hacerTablero();
    }
    else if (modo == 2)
    {
        do
        {
            system("clear");
            do
            {
                hacerTablero();
                jugada = seleccionJugada();
                casillaOcupada = compruebaJugada(jugada, TABLERO);
                if (casillaOcupada == true)
                {
                    system("clear");
                    cout << "Trye again \n";
                }
            } while (casillaOcupada == true);
            ponerJugada(jugada, TABLERO, HUMANO);
            gameover = ganar(TABLERO);
        } while (gameover == false and turnosJugador < 10);
        system("clear");
        hacerTablero();
    }

    if (gameover == true)
    {
        if (turnosJugador % 2 == 0)
        {
            cout <<"\x1b[0;33m"<<"Player 1 won"<<"\x1b[0m"<< endl;
        }
        else
        {
            if (modo == 1)
            {
                cout <<"\x1b[0;31m"<<"PC won"<<"\x1b[0m"<<endl;
            }
            else
            {
                cout <<"\x1b[0;34m"<<"Player 2 won"<<"\x1b[0m"<< endl;
            }
        }
    }
    else
    {
        cout <<"\x1b[0;31m"<<"Anyone's won"<<"\x1b[0m"<<endl;
    }
    return 0;
}

void hacerTablero()
{
    row = 0;
    col = 0;
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (col1 == 3 || col1 == 7)
            {
                structureGato[row1][col1] = '|';
            }
            else if (row1 == 1 || row1 == 3)
            {
                structureGato[row1][col1] = '_';
            }
            else if (row1 != 5 && (col1 == 1 || col1 == 5 || col1 == 9))
            {
                structureGato[row1][col1] = areaDeJuego[row][col];
                col++;
                if (col == 3)
                {
                    col = 0;
                    row++;
                }
            }
            else
            {
                structureGato[row1][col1] = ' ';
            }
        }
    }
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (structureGato[row1][col1] == 'X')
            {
                cout << "\x1b[0;34m" << structureGato[row1][col1] << "\x1b[0m";
            }
            else if (structureGato[row1][col1] == 'O')
            {
                cout << "\x1b[0;33m" << structureGato[row1][col1] << "\x1b[0m";
            }
            else
            {
                cout << structureGato[row1][col1];
            }
        }
        cout << endl;
    }
}

int seleccionJugada()
{
    int jugada1;
    do
    {
        cout <<"\x1b[0;35m"<<"Give  me your move: "<<"\x1b[0m";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool compruebaJugada(int jugada, string Tablero)
{
    bool casillaOcupada = false;
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (jugada == numjuada)
        {
            row = fila;
            col = columna;
            break;
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (Tablero == TABLERO)
    {
        if (areaDeJuego[row][col] == 'O' || areaDeJuego[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    else if (Tablero == TABLEROIMAG)
    {
        if (areaDeJuegoDePc[row][col] == 'O' || areaDeJuegoDePc[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    return casillaOcupada;
}

void ponerJugada(int jugada, string Tablero, string Jugador)
{
    char valorJugada;
    if (turnosJugador % 2 == 0)
    {
        valorJugada = 'X';
    }
    else
    {
        valorJugada = 'O';
    }
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (jugada == numjuada)
        {
            if (Tablero == TABLERO)
            {
                areaDeJuego[fila][columna] = valorJugada;
                break;
            }
            else if (Tablero == TABLEROIMAG)
            {
                if (Jugador == HUMANO)
                {
                    valorJugada = 'O';
                }
                else if (Jugador == PC)
                {
                    valorJugada = 'X';
                }
                areaDeJuegoDePc[fila][columna] = valorJugada;
                break;
            }
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (Tablero == TABLERO){
        turnosJugador++;
    }
}

bool ganar(string tablero)
{
    bool ganar = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (tablero == TABLERO)
        {
            if (areaDeJuego[posicion][0] == areaDeJuego[posicion][1] && areaDeJuego[posicion][posicion] == areaDeJuego[posicion][2] && areaDeJuego[posicion][1] == areaDeJuego[posicion][2])
            {
                ganar = true;
                break;
            }
            if (areaDeJuego[0][posicion] == areaDeJuego[1][posicion] && areaDeJuego[0][posicion] == areaDeJuego[2][posicion] && areaDeJuego[1][posicion] == areaDeJuego[2][posicion])
            {
                ganar = true;
                break;
            }
        }
        else if (tablero == TABLEROIMAG)
        {
            if (areaDeJuegoDePc[posicion][0] == areaDeJuegoDePc[posicion][1] && areaDeJuegoDePc[posicion][posicion] == areaDeJuegoDePc[posicion][2] && areaDeJuegoDePc[posicion][1] == areaDeJuegoDePc[posicion][2])
            {
                ganar = true;
                break;
            }
            if (areaDeJuegoDePc[0][posicion] == areaDeJuegoDePc[1][posicion] && areaDeJuegoDePc[0][posicion] == areaDeJuegoDePc[2][posicion] && areaDeJuegoDePc[1][posicion] == areaDeJuegoDePc[2][posicion])
            {
                ganar = true;
                break;
            }
        }
    }
    if (tablero == TABLERO)
    {
        if (areaDeJuego[0][0] == areaDeJuego[1][1] && areaDeJuego[0][0] == areaDeJuego[2][2] && areaDeJuego[1][1] == areaDeJuego[2][2]) 
        {
            ganar = true;
        }
        else if (areaDeJuego[2][0] == areaDeJuego[1][1] && areaDeJuego[2][0] == areaDeJuego[0][2] && areaDeJuego[0][2] == areaDeJuego[1][1])
        {
            ganar = true;
        }
    } 
    else if (tablero == TABLEROIMAG)
    {
        if (areaDeJuegoDePc[0][0] == areaDeJuegoDePc[1][1] && areaDeJuegoDePc[0][0] == areaDeJuegoDePc[2][2] && areaDeJuegoDePc[1][1] == areaDeJuegoDePc[2][2])
        {
            ganar = true;
        }
        else if (areaDeJuegoDePc[2][0] == areaDeJuegoDePc[1][1] && areaDeJuegoDePc[2][0] == areaDeJuegoDePc[0][2] && areaDeJuegoDePc[0][2] == areaDeJuegoDePc[1][1])
        {
            ganar = true;
        }
    }
    return ganar;
}

int obtencionJugada()
{
    bool casillaOcupada = true;
    int jugada;
    srand(time(NULL));
    jugada = obtenerMejorJugada(PC);
    if (jugada != -1)
    {
        return jugada;
    }
    jugada = obtenerMejorJugada(HUMANO);
    if (jugada != -1)
    {
        return jugada;
    }
    while (casillaOcupada == true)
    {
        jugada= 1 + rand() % 9;
        casillaOcupada= compruebaJugada (jugada,TABLERO);
    }
    return jugada;
}

void clonMatriz(){
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            areaDeJuegoDePc[fila][columna] = areaDeJuego[fila][columna];
        }
    }
}

int obtenerMejorJugada(string jugador)
{
    bool casillaOcupada = false;
    bool gameover = false;
    int jugada = 0;
    clonMatriz();
    if (jugador == PC)
    {
        do
        {
            jugada++;
            casillaOcupada=compruebaJugada(jugada, TABLEROIMAG);
            if (casillaOcupada == false){
                ponerJugada(jugada, TABLEROIMAG, PC);
                gameover = ganar(TABLEROIMAG);
            }
            clonMatriz();
        } while (jugada <= 9 && gameover == false);
    } 
    else if (jugador == HUMANO)
    {
        do
        {
            jugada++;
            casillaOcupada=compruebaJugada(jugada, TABLEROIMAG);
            if (casillaOcupada== false){
                ponerJugada(jugada, TABLEROIMAG, HUMANO);
                gameover = ganar(TABLEROIMAG);
            }
            clonMatriz();
        } while (jugada <= 9 && gameover == false);
    }
    if (jugada >= 10){
        jugada= -1;
    }
    return jugada;
}

//Rule of colors

//===Color font code===/
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"
//===Color background code===/
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"