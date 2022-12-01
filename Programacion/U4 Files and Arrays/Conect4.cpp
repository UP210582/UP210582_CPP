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
bool isWinner(int);
void setCol(int,int);



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
    int busyRow=-1;
    
    doBoard();
    selectCol();
    busyRow = checkBusyRow(col);
    if (busyRow == -1)
    {
        cout << "Please, select other coulum: ";
    }
    else
    {
        setCol(row, col);
        system("clear");
        doBoard();
        cout << endl;
        
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

bool checkHorizontalMoves(int row, int col)
{
    bool isWinner = false;
    int coulum = col, acum = 0;
     
    while (setCol != '0')
    {
        //right
        if (gameArea[row][col] == '0')
        {
            acum++;
            col++;
        }
        else
        {
            coulum = col;
        }
    }
    while (setCol != '0' && isWinner == false)
    {
        //left
        if (gameArea[row][col]=='O'){
            acum++;
            col--;
        }else {
            coulum=col;
        }
    }
    if (acum==4){
        return true;
    }else {
        return false;
    }
}

bool checkVerticalMoves(int row, int col){
    bool isWinner = false;
    int coulum = col, acum = 0;
    while (setCol != 'O')
    {
        //up
        if (gameArea[row][col] == '0')
        {
            acum++;
            row++;
        }
        else
        {
            coulum = col;
        }
    }
    while (selCol !='0' && isWinner == false)
    {
        //down
        if (gameArea[row][col]=='O'){
            acum++;
            row--;
        }else {
            coulum=col;
        }
    }
    if (acum==4){
        return true;
    }else {
        return false;
    }
}

bool checkPositiveDiagonallyMoves(int row, int col){
    bool isWinner = false;
    int coulum = col, acum = 0;
    while (setCol != 'O')
    {
        //up
        if (gameArea[row][col] == '0')
        {
            acum++;
            col++;
            row--;
        }
        else
        {
            coulum = col;
        }
    }
    while (setCol != '0' && isWinner == false)
    {
        //down
        if (gameArea[row][col]=='O'){
            acum++;
            col--;
            row++;
        }else {
            coulum=col;
        }
    }
    if (acum==4){
        return true;
    }else {
        return false;
    }
}

bool checkNegativeDiagonallyMoves(int row, int col){
    bool isWinner = false;
    int coulum = col, acum = 0;
    while (setCol != 'O')
    {
        //up
        if (gameArea[row][col] == '0')
        {
            acum++;
            col--;
            row++;
        }
        else
        {
            coulum = col;
        }
    }
    while (setCol != '0' && isWinner == false)
    {
        //down
        if (gameArea[row][col]=='O'){
            acum++;
            col++;
            row++;
        }else {
            coulum=col;
        }
    }
    if (acum==4){
        return true;
    }else {
        return false;
    }
}
