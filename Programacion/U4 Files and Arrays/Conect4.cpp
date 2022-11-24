/*
Date: 23/11/2022
Authors:    Paulina Jaqueline Alvarez Martinez
            Sofia Calderon Juarez
            Leonardo Ausencio Martinez Torres

Email:  up210374@alumnos.upa.edu.mx
        up210300@alumnos.upa.edu.mx
        up210582@alumnos.upa.edu.mx
Description: Game of Conect 4
Last Modification: 23/10/2022
*/


//used bookstores
#include <iostream>
#include <stdalign.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void doBoard();
int selectedPlay();
bool checkPlay(int, string);
void putMove(int, string, string); 
bool win(string);
int obtainingPlayed();
void cloneMatrix();
int getBestPlay(string);


char structureGato[12][29];
char gameArea[6][7] = {{'1', '2', '3','4', '5', '6','7' }, {'8', '9', '10', '11', '12', '13','14' }, {'15', '16', '17','18', '19', '20','21' }, {'22', '23', '24','25', '26', '27','28' }, {'29', '30', '31','32', '33', '34','35' }, {'36', '37', '38', '39', '40', '41','42' }};
char gameAreaPc[6][7];
int turnsPlayer = 1;
int row, col;
const string PC = "Robot";
const string HUMAN = "HUMAN";
const string BOARD = "Real";
const string BOARDIMAG = "Imaginario";


int main()
{
    system("clear");
    bool gameover = false;
    int play;
    bool occupiedBox = true;
    int mode;
    
    cout <<"\x1b[0;31m" << "Welcome to the game of TicTacToe" <<"\x1b[0m"<< endl;
    cout <<"\x1b[0;36m"<<"Choose your game mode"<<"\x1b[0m"<< endl;
    cout <<"\x1B[38;2;17;245;120m"<<"1 Singleplayer"<<"\x1B[0m"<< endl;
    cout << "2 Multiplayer" << endl;
    cin >> mode;
    if (mode == 1)
    {
        do
        {
            system("clear");
            if (turnsPlayer % 2 == !0)
            {
                do
                {
                    cout <<"\x1b[0;31m"<< "=============TicTacToe Singleplayer Mode===========" <<"\x1b[0m"<<endl;
                    cout <<"\x1b[0;33m"<<"Player is O\t" << "\t" <<"\x1b[0;34m"<<"Pc is X" <<"\x1b[0m"<<endl;
                    cout << endl;
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
                cout <<"\x1b[0;31m"<< "=============TicTacToe Multiplayer Mode============" <<"\x1b[0m"<<endl;
                cout <<"\x1b[0;33m"<<"Player 1 is O\t" << "\t" <<"\x1b[0;34m"<<"Player 2 is X" <<"\x1b[0m"<<endl;
                cout << endl;
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
    else if (mode != 1 && mode != 2)
    {
        cout << "Please choose a valid mode of Game" << endl;
        return 0;
    }

    if (gameover == true)
    {
        if (turnsPlayer % 2 == 0)
        {
            cout <<"\x1b[0;33m"<<"Player 1 is the winner "<<"\x1b[0m"<< endl;
        }
        else
        {
            if (mode == 1)
            {
                cout <<"\x1b[0;33m"<<"Game Over"<<"\x1b[0m"<<endl;
                cout <<"\x1b[0;34m"<<"PC is the winner"<<"\x1b[0m"<<endl;
            }
            else
            {
                cout <<"\x1b[0;34m"<<"Player 2 is the winner"<<"\x1b[0m"<< endl;
            }
        }
    }
    if (gameover == false)
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
        cout <<"\x1b[0;35m"<<"Give me your move: "<<"\x1b[0m";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool checkPlay(int play, string board)
{
    bool occupiedBox = false;
    int fila = 0, columna = 0;
    if (play >9 || play <=0 and board == BOARD)
    {
        return true;
    }
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
    if (board == BOARD)
    {
        if (gameArea[row][col] == 'O' || gameArea[row][col] == 'X')
        {
            occupiedBox = true;
        }
    }
    else if (board == BOARDIMAG)
    {
        if (gameAreaPc[row][col] == 'O' || gameAreaPc[row][col] == 'X')
        {
            occupiedBox = true;
        }
    }
    return occupiedBox;
}

void putMove(int play, string board, string Jugador)
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
            if (board == BOARD)
            {
                gameArea[fila][columna] = valorJugada;
                break;
            }
            else if (board == BOARDIMAG)
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
    if (board == BOARD){
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