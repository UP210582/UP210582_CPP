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

using namespace std;

void doBoard();
int selectCol();
int checkBusyRow(int);
bool isWinner(int);

int col, row, turn = 1;
char gameArea[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

int main()
{
    doBoard();
    selectCol();
}

void doBoard()
{

    char board[22][43];

    for (int row = 0; row < 22; row++)
    {
        for (int col = 0; col < 43; col++)
        {
            if (row == 21)
            {
                cout << "¯";
            }
            else if (row % 3 == 0 && col != 0 && col != 6 && col != 12 && col != 18 && col != 24 && col != 30 && col != 36 && col != 42)
            {
                cout << "¯";
            }
            else if (col % 6 == 0)
            {
                cout << "|";
            }
            else if (row != 0)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int selectCol()
{
    cout << "Choose a column: ";
    cin >> col;
    while (col < 1 || col > 7)
    {
        cout << "This is incorrect, choose another column: ";
        cin >> col;
    }
    return col;
}

int checkBusyRow(int col)
{
    for (int row = 6; row > 0; row--)
    {
        if (gameArea[row][col] == ' ')
        {
            return row;
        }
    }
    return -1;
}

void setCol(int row, int col)
{
    char value;
    if (turn % 2 == 0)
        value = '0';
    else
        value = 'O';
    gameArea[row][col] = value;
}

bool isWinner(int col)
{
    for (row = 6; row > 0; row--)
    {
        for (int col2 = col; col2 <= 7; col2++)
        {
            if (gameArea[row][col] == gameArea[row][col] && gameArea[row][col] == gameArea[row][col])
            {
                return true;
            }else {
                return false;
            }
        }
    }

    for (row = 6; row > 0; row--)
    {
        for (int col2 = col; col2 <= 7; col2--)
        {
            if (gameArea[row][col] == gameArea[row][col] && gameArea[row][col] == gameArea[row][col])
            {
                return true;
            }else {
                return false;
            }
        }
    }
}