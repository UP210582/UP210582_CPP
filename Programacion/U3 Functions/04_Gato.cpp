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

void doBoard();
int selectedPlay();
bool checkPlay(int, string);
void putMove(int, string, string);
bool win(string);
int obtainingPlayed();
void cloneMatrix();
int getBestPlay(string);
char structureGato[6][11];
char gameArea[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char gameAreaPc[3][3];
int turnsPlayer = 1;
int row, col;
const string PC = "Robot";
const string HUMAN = "HUMAN";
const string BOARD = "Real";
const string BOARDIMAG = "Imaginario";

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
            if (turnsPlayer % 2 == !0)
            {
                do
                {
                    doBoard();
                    jugada = selectedPlay();
                    casillaOcupada = checkPlay(jugada, BOARD);
                    if (casillaOcupada == true)
                    {
                        system("clear");
                        cout << "Trye again \n";
                    }
                } while (casillaOcupada == true);
                putMove(jugada, BOARD, HUMAN);
                gameover = win(BOARD);
            }
            else
            {
                doBoard();
                jugada = obtainingPlayed();
                putMove(jugada, BOARD, PC);
                gameover = win(BOARD);
            }
        } while (gameover == false and turnsPlayer < 10);
        system("clear");
        doBoard();
    }
    else if (modo == 2)
    {
        do
        {
            system("clear");
            do
            {
                doBoard();
                jugada = selectedPlay();
                casillaOcupada = checkPlay(jugada, BOARD);
                if (casillaOcupada == true)
                {
                    system("clear");
                    cout << "Trye again \n";
                }
            } while (casillaOcupada == true);
            putMove(jugada, BOARD, HUMAN);
            gameover = win(BOARD);
        } while (gameover == false and turnsPlayer < 10);
        system("clear");
        doBoard();
    }

    if (gameover == true)
    {
        if (turnsPlayer % 2 == 0)
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

void doBoard()
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
                structureGato[row1][col1] = gameArea[row][col];
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

int selectedPlay()
{
    int jugada1;
    do
    {
        cout <<"\x1b[0;35m"<<"Give  me your move: "<<"\x1b[0m";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool checkPlay(int jugada, string Tablero)
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
    if (Tablero == BOARD)
    {
        if (gameArea[row][col] == 'O' || gameArea[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    else if (Tablero == BOARDIMAG)
    {
        if (gameAreaPc[row][col] == 'O' || gameAreaPc[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    return casillaOcupada;
}

void putMove(int jugada, string Tablero, string Jugador)
{
    char valorJugada;
    if (turnsPlayer % 2 == 0)
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
            if (Tablero == BOARD)
            {
                gameArea[fila][columna] = valorJugada;
                break;
            }
            else if (Tablero == BOARDIMAG)
            {
                if (Jugador == HUMAN)
                {
                    valorJugada = 'O';
                }
                else if (Jugador == PC)
                {
                    valorJugada = 'X';
                }
                gameAreaPc[fila][columna] = valorJugada;
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
    if (Tablero == BOARD){
        turnsPlayer++;
    }
}

bool win(string tablero)
{
    bool win = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (tablero == BOARD)
        {
            if (gameArea[posicion][0] == gameArea[posicion][1] && gameArea[posicion][posicion] == gameArea[posicion][2] && gameArea[posicion][1] == gameArea[posicion][2])
            {
                win = true;
                break;
            }
            if (gameArea[0][posicion] == gameArea[1][posicion] && gameArea[0][posicion] == gameArea[2][posicion] && gameArea[1][posicion] == gameArea[2][posicion])
            {
                win = true;
                break;
            }
        }
        else if (tablero == BOARDIMAG)
        {
            if (gameAreaPc[posicion][0] == gameAreaPc[posicion][1] && gameAreaPc[posicion][posicion] == gameAreaPc[posicion][2] && gameAreaPc[posicion][1] == gameAreaPc[posicion][2])
            {
                win = true;
                break;
            }
            if (gameAreaPc[0][posicion] == gameAreaPc[1][posicion] && gameAreaPc[0][posicion] == gameAreaPc[2][posicion] && gameAreaPc[1][posicion] == gameAreaPc[2][posicion])
            {
                win = true;
                break;
            }
        }
    }
    if (tablero == BOARD)
    {
        if (gameArea[0][0] == gameArea[1][1] && gameArea[0][0] == gameArea[2][2] && gameArea[1][1] == gameArea[2][2]) 
        {
            win = true;
        }
        else if (gameArea[2][0] == gameArea[1][1] && gameArea[2][0] == gameArea[0][2] && gameArea[0][2] == gameArea[1][1])
        {
            win = true;
        }
    } 
    else if (tablero == BOARDIMAG)
    {
        if (gameAreaPc[0][0] == gameAreaPc[1][1] && gameAreaPc[0][0] == gameAreaPc[2][2] && gameAreaPc[1][1] == gameAreaPc[2][2])
        {
            win = true;
        }
        else if (gameAreaPc[2][0] == gameAreaPc[1][1] && gameAreaPc[2][0] == gameAreaPc[0][2] && gameAreaPc[0][2] == gameAreaPc[1][1])
        {
            win = true;
        }
    }
    return win;
}

int obtainingPlayed()
{
    bool casillaOcupada = true;
    int jugada;
    srand(time(NULL));
    jugada = getBestPlay(PC);
    if (jugada != -1)
    {
        return jugada;
    }
    jugada = getBestPlay(HUMAN);
    if (jugada != -1)
    {
        return jugada;
    }
    while (casillaOcupada == true)
    {
        jugada= 1 + rand() % 9;
        casillaOcupada= checkPlay (jugada,BOARD);
    }
    return jugada;
}

void cloneMatrix(){
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            gameAreaPc[fila][columna] = gameArea[fila][columna];
        }
    }
}

int getBestPlay(string jugador)
{
    bool casillaOcupada = false;
    bool gameover = false;
    int jugada = 0;
    cloneMatrix();
    if (jugador == PC)
    {
        do
        {
            jugada++;
            casillaOcupada=checkPlay(jugada, BOARDIMAG);
            if (casillaOcupada == false){
                putMove(jugada, BOARDIMAG, PC);
                gameover = win(BOARDIMAG);
            }
            cloneMatrix();
        } while (jugada <= 9 && gameover == false);
    } 
    else if (jugador == HUMAN)
    {
        do
        {
            jugada++;
            casillaOcupada=checkPlay(jugada, BOARDIMAG);
            if (casillaOcupada== false){
                putMove(jugada, BOARDIMAG, HUMAN);
                gameover = win(BOARDIMAG);
            }
            cloneMatrix();
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