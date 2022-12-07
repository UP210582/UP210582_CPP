/*
Date: 23/11/2022
Authors:    Paulina Jaqueline Alvarez Martinez
            Sofia Calderon Juarez
            Leonardo Ausencio Martinez Torres

Email:  up210374@alumnos.upa.edu.mx
        up210300@alumnos.upa.edu.mx
        up210582@alumnos.upa.edu.mx
Description: Game of Conect 4
Last Modification: 24/11/2022
*/

// used bookstores
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
//#include <PresentationComponents.h>

using namespace std;

void doBoard();
int selectCol();
int checkBusyRow(int, string);
bool checkHorizaontalMoves(int, int);
bool checkVerticalMoves(int, int);
bool checkPositiveDiagonallyMoves(int, int);
bool checkNegativeDiagonallyMoves(int, int);
void setCol(int, int, string, string);
bool isWinner(string);
int getColPC();
void coleBoard();
int getBetterCol(string);
int selectColPC();

int col, row, turn = 1;
char gameArea[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char gameAreaIMG[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
const string PC = "Machine";
const string PERSON = "Person";
const string BOARD = "Real";
const string IMGBOARD = "Imaginary";

int main()
{
    bool winner = false;
    char option;
    cout << "Press Y to play or X to exit the game:  ";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
        int gameType = 1;
        int busyRow = -1;
        cout << "\x1B[38;2;255;151;203m"
             << "Menu"
             << "\x1b[0m" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs PC" << endl;
        cout << "Plase select the game mood: ";
        cin >> gameType;
    doBoard();
        do
        {
            if (gameType == 1)
            {
                col = selectCol();
            }
            else
            {
                if (turn % 2 == 0)
                {
                    col = selectCol();
                }
                else
                {
                    col = selectColPC();
                }
            }
            busyRow = checkBusyRow(col, BOARD);
            if (busyRow == -1)
            {
        cout << "Please, select other coulum: ";
            }
            else
            {
                setCol(busyRow, col, BOARD, PERSON);
                system("clear");
        doBoard();
        cout << endl;
                winner = isWinner(BOARD);
        turn++;
    }
        } while (turn <= 42 && winner == false);
        if (winner == true)
        {
            if (turn % 2 == 0)
            {
                cout << "\x1B[38;2;255;151;203m"
                     << "Congrats player 2, you won"
                     << "\x1b[0m" << endl;
            }
            else
            {
                cout << "\x1B[38;2;255;151;203m"
                     << "Congrats player 1, you won"
                     << "\x1b[0m" << endl;
            }
        }
        else if (winner == false)
        {
            cout << "\x1B[38;2;255;151;203m"
                 << "Tontes ninguno gano :/"
                 << "\x1b[0m" << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "\x1B[38;2;255;151;203m"
             << "I didn't even want you to play :D"
             << "\x1b[0m" << endl;
    }
    return 0;
}

void doBoard()
{

    char board[25][43];
    char number[1][7] = { '1','2','3','4','5','6','7'};
    int z = 0;
    int w = 0;

    for (int i = 0; i < 1; i++)
    {
        //gotoxy(8, 8 + i);
        for (int j = 0; j < 7; j++)
        {
            cout << "   ";
            cout << number[i][j];
            cout << "  ";
        }
    }

    cout << "\n"
         << endl;

    for (int row = 0; row < 25; row++)
    {
        //gotoxy(10, 10 + row);
        for (int col = 0; col < 43; col++)
        {
            
            if (row % 4 == 0 && col % 6 != 0 || row == 24)
            {
                cout << "\x1B[44m"
                     << "\x1b[34m"
                     << "¯"
                     << "\x1b[0m"
                     << "\x1B[0m";
            }
            else if (col % 6 == 0)
            {
                cout << "\x1B[44m"
                     << "\x1b[34m"
                     << "¦"
                     << "\x1b[0m"
                     << "\x1B[0m";
            }
            else if (row != 0)
            {
                if (row % 2 == 0 && col % 3 == 0)
                {
                    cout << gameArea[z][w];
                    w++;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    z++;
    w = 0;
}

int selectCol()
{
    cout << "Player  " << turn % 2 << endl;
    cout << "Choose a column: ";
    cin >> col;
    col--;
    while (col < 0 || col > 6)
    {
        cout << "This is incorrect, choose another column: ";
        cin >> col;
    }
    return col;
}

int checkBusyRow(int col, string board)
{
    if (board == BOARD)
    {
        for (int row = 5; row > 0; row--)
    {
        if (gameArea[row][col] == ' ')
        {
            return row;
        }
    }
    }
    else if (board == IMGBOARD)
    {
        for (int row = 5; row > 0; row--)
        {
            if (gameAreaIMG[row][col] == ' ')
            {
                return row;
            }
        }
    }
    return -1;
}

void setCol(int row, int col, string board, string player)
{
    char value;
    if (turn % 2 == 0)
        value = '0';
    else
        value = 'O';
    if (board == BOARD)
    {
    gameArea[row][col] = value;
}
    else if (board == IMGBOARD)
    {
        if (player == PERSON)
        {
            value = 'O';
        }
        else if (player == PC)
        {
            value = '0';
        }
        gameAreaIMG[row][col] = value;
    }
}

bool checkHorizontalMoves(int row, int col)
{
    bool isWinner = false;
    int coulum = col, acum = 0;
    int nCol = col + 1;
    int n2Col = col - 1;
    while (gameArea[row][col] == gameArea[row][nCol])
    {
        acum++;
        nCol++;
    }
    coulum = col;
    while (gameArea[row][col] == gameArea[row][n2Col])
    {
        acum++;
        n2Col--;
    }
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkVerticalMoves(int row, int col)
{
    bool isWinner = false;
    int row1 = row, acum = 0;
    int nRow = row + 1;
    int n2Row = row - 1;
    while (gameArea[row][col] == gameArea[nRow][col])
    {
        acum++;
        nRow++;
    }
    row1 = row;
    while (gameArea[row][col] == gameArea[n2Row][col])
    {
        acum++;
        n2Row--;
    }
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkPositiveDiagonallyMoves(int row, int col)
{
    bool isWinner = false;
    int coulum = col, row1 = row, acum = 0;
    int nRow = row - 1;
    int nCol = col + 1;
    int n2Row = row + 1;
    int n2Col = col - 1;
    while (gameArea[row][col] == gameArea[nRow][nCol])
    {
        acum++;
        nCol++;
        nRow--;
    }
    coulum = col;
    row1 = row;
    while (gameArea[row][col] == gameArea[n2Row][n2Col])
    {
        acum++;
        n2Col--;
        n2Row++;
    }
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkNegativeDiagonallyMoves(int row, int col)
{
    bool isWinner = false;
    int coulum = col, row1 = row, acum = 0;
    int nRow = row - 1;
    int nCol = col - 1;
    int n2Row = row + 1;
    int n2Col = col + 1;
    while (gameArea[row][col] == gameArea[nRow][nCol])
    {
        acum++;
        nCol--;
        nRow--;
    }
    coulum = col;
    row1 = row;
    while (gameArea[row][col] == gameArea[n2Row][n2Col])
    {
        acum++;
        n2Col++;
        n2Row++;
    }
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//bool isWinner()
bool isWinner(string board)
{
    if (board == BOARD)
    {
        bool isWinnerHorizontal = false;
        bool isWinnerVertical = false;
        bool isWinnerPositiveDiagonally = false;
        bool isWinnerNegativeDiagonally = false;
        isWinnerHorizontal = checkHorizaontalMoves;
        isWinnerVertical = checkVerticalMoves;
        isWinnerPositiveDiagonally = checkPositiveDiagonallyMoves;
        isWinnerNegativeDiagonally = checkNegativeDiagonallyMoves;
        if (isWinnerHorizontal == true || isWinnerVertical == true || isWinnerPositiveDiagonally == true || isWinnerNegativeDiagonally == true)
        {
            return true;
        }
        return false;
    }
    else if (board == IMGBOARD)
    {
        bool isWinnerHorizontal = false;
        bool isWinnerVertical = false;
        bool isWinnerPositiveDiagonally = false;
        bool isWinnerNegativeDiagonally = false;
        isWinnerHorizontal = checkHorizaontalMoves;
        isWinnerVertical = checkVerticalMoves;
        isWinnerPositiveDiagonally = checkPositiveDiagonallyMoves;
        isWinnerNegativeDiagonally = checkNegativeDiagonallyMoves;
        if (isWinnerHorizontal == true || isWinnerVertical == true || isWinnerPositiveDiagonally == true || isWinnerNegativeDiagonally == true)
        {
            return true;
        }
    }
    else 
    return false;
}

int selectColPC()
{
    bool busyRow = false;
    int col;
    srand(time(NULL));
    col = getBetterCol(PC);
    if (col != -1)
    {
        return col;
    }
    col = getBetterCol(PERSON);
    if (col != -1)
    {
        return col;
    }
    do
    {
        col = 1 + rand() % 7;
        busyRow = checkBusyRow(col, BOARD);
    } while (busyRow == true);
    return col;
}

void cloneBoard()
{
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            gameAreaIMG[row][col] = gameArea[row][col];
        }
    }
}

int getBetterCol(string player){
    bool busyRow = false;
    bool winner = false;
    int col = 0;
    cloneBoard();
    if (player == PC)
    {
        do
        {
            col++;
            busyRow=checkBusyRow(col, IMGBOARD);
            if (busyRow== false){
                setCol(col, row, IMGBOARD, PC);
                winner = isWinner (IMGBOARD);
            }
            cloneBoard();
        } while (col <= 7 && winner == false );
    } 
    else if (player == PERSON)
    {
        do
        {
            col++;
            busyRow=checkBusyRow(col, IMGBOARD);
            if (busyRow== false){
                setCol(col, row, IMGBOARD, PERSON);
                winner = isWinner(IMGBOARD);
            }
            cloneBoard();
        } while (col <= 7 && winner == false);
    }
    if (col >= 8){
        col= -1;
    }
    return col;
}
