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
void setCol(int, int);
bool checkHorizaontalMoves(int, int);
bool checkVerticalMoves(int, int);
bool isWinner();
void setCol(int, int);

int col, row, turn = 1;
char gameArea[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

int main()
{
    int busyRow = -1;
    bool winner = false;
    doBoard();
    selectCol();
    busyRow = checkBusyRow(col);
    if (busyRow == -1)
    {
        cout << "Please, select other coulum: ";
    }
    else
    {
        setCol(busyRow, col);
        system("clear");
        doBoard();
        cout << endl;
        /*
        winner = isWinner();
        */
        turn++;
    }
}

void doBoard()
{

    char board[22][43];
    char number[1][7] = {'1', '2', '3', '4', '5', '6', '7'};
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;

    for (int row = 0; row < 22; row++)
    {
        for (int col = 0; col < 43; col++)
        {

            if (row % 3 == 0 && col % 6 != 0 || row == 21)
            {
                cout << "¯";
            }
            else if (col % 6 == 0)
            {
                cout << "|";
            }
            else if (row != 0)
            {
                if (row == 1 && col % 3 == 0)
                {
                    cout << number[x][y];
                    y++;
                }
                else if ((row == 4 || row == 7 || row == 10 || row == 13 || row == 16 || row == 19) && col % 3 == 0)
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
    cout << "Player  " << turn % 2 + 1 << endl;
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

int checkBusyRow(int col)
{
    for (int row = 5; row > 0; row--)
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
/*
bool isWinner()
{
    bool isWinnerHorizontal = false;
    bool isWinnerVertical = false;
    bool isWinnerPositiveDiagonally = false;
    bool isWinnerNegativeDiagonally = false;
    isWinnerHorizontal = checkHorizaontalMoves(row, col);
    isWinnerVertical = checkVerticalMoves(row, col);
    isWinnerPositiveDiagonally = checkPositiveDiagonallyMoves(row, col);
    isWinnerNegativeDiagonally = checkNegativeDiagonallyMoves(row, col);
    if (isWinnerHorizontal == true || isWinnerVertical == true || isWinnerPositiveDiagonally == true || isWinnerNegativeDiagonally == true)
    {
        return true;
    }
    return false;
}
*/