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
//function to check the move these can be from 1 to 9 
//if the box is occupied it returns true and asks you to enter a 
//valid box but if it is free it returns false and you can continue the game.
void putMove(int, string, string);
//Function to place the move on the corresponding board the moves range from 1 to 9. 
bool win(string);
//Function to determine if the move is a winning move on the corresponding board.
int obtainingPlayed();
//function to obtain the pc move it returns a value from 
//1 to 9 indicating in which square the pc move is located.
void cloneMatrix();
//Function to clone the matrix to use it in single mode.
int getBestPlay(string);
//

//global variables
char structureGato[6][11];
char gameArea[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char gameAreaPc[3][3];
int turnsPlayer = 1;
int row, col;
const string PC = "Robot";
const string HUMAN = "HUMAN";
const string BOARD = "Real";
const string BOARDIMAG = "Imaginario";

//Principal Function
int main()
{
    //in principle it is indicated that the game is 
    //not finished and that there is no gameover for 
    //that we indicate that gameover is false 
    //and that the squares are in truth so that 
    //the game starts to take them. 
    bool gameover = false;
    int play;
    bool occupiedBox = true;
    int mode;
    //Game start message and ask which game mode the player wants, multiplayer or singleplayer.
    cout <<"\x1b[0;31m" << "Welcome to the game of TicTacToe" <<"\x1b[0m"<< endl;
    cout <<"\x1b[0;36m"<<"Choose your game mode"<<"\x1b[0m"<< endl;
    cout <<"\x1B[38;2;17;245;120m"<<"1 Singleplayer"<<"\x1B[0m"<< endl;
    cout << "2 Multiplayer" << endl;
    cin >> mode;
    //if you place 1 enter the singleplayer mode
    if (mode == 1)
    {
        do
        {
            //command to delete the above and for the terminal to come up clean and start the game
            system("clear");
            //to determine which player is next, divide by 2 and if 
            //the remainder is 0 then player 1 goes and 
            //if it is different from 0 then player 2 goes.
            if (turnsPlayer % 2 == !0)
            {
                do
                {
                    //print board in tiling to doBoard function
                    doBoard();
                    //see the play reflected on the board being matched to the function selectedPlay
                    play = selectedPlay();

                    occupiedBox = checkPlay(play, BOARD);
                    if (occupiedBox == true)
                    {
                        system("clear");
                        cout << "Trye again \n";
                    }
                } while (occupiedBox == true);
                putMove(play, BOARD, HUMAN);
                gameover = win(BOARD);
            }
            else
            {
                doBoard();
                play = obtainingPlayed();
                putMove(play, BOARD, PC);
                gameover = win(BOARD);
            }
        } while (gameover == false and turnsPlayer < 10);
        system("clear");
        doBoard();
    }
    //if you place 2 enter multiplayer mode
    else if (mode == 2)
    {
        do
        {
            system("clear");
            do
            {
                doBoard();
                play = selectedPlay();
                occupiedBox = checkPlay(play, BOARD);
                if (occupiedBox == true)
                {
                    system("clear");
                    cout << "Trye again \n";
                }
            } while (occupiedBox == true);
            putMove(play, BOARD, HUMAN);
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
            if (mode == 1)
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
    cout << "=============TicTacToe=============" << endl;
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

bool checkPlay(int play, string Tablero)
{
    bool occupiedBox = false;
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (play == numjuada)
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
            occupiedBox = true;
        }
    }
    else if (Tablero == BOARDIMAG)
    {
        if (gameAreaPc[row][col] == 'O' || gameAreaPc[row][col] == 'X')
        {
            occupiedBox = true;
        }
    }
    return occupiedBox;
}

void putMove(int play, string Tablero, string Jugador)
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
        if (play == numjuada)
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
    bool occupiedBox = true;
    int play;
    srand(time(NULL));
    play = getBestPlay(PC);
    if (play != -1)
    {
        return play;
    }
    play = getBestPlay(HUMAN);
    if (play != -1)
    {
        return play;
    }
    while (occupiedBox == true)
    {
        play= 1 + rand() % 9;
        occupiedBox= checkPlay (play,BOARD);
    }
    return play;
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
    bool occupiedBox = false;
    bool gameover = false;
    int play = 0;
    cloneMatrix();
    if (jugador == PC)
    {
        do
        {
            play++;
            occupiedBox=checkPlay(play, BOARDIMAG);
            if (occupiedBox == false){
                putMove(play, BOARDIMAG, PC);
                gameover = win(BOARDIMAG);
            }
            cloneMatrix();
        } while (play <= 9 && gameover == false);
    } 
    else if (jugador == HUMAN)
    {
        do
        {
            play++;
            occupiedBox=checkPlay(play, BOARDIMAG);
            if (occupiedBox== false){
                putMove(play, BOARDIMAG, HUMAN);
                gameover = win(BOARDIMAG);
            }
            cloneMatrix();
        } while (play <= 9 && gameover == false);
    }
    if (play >= 10){
        play= -1;
    }
    return play;
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