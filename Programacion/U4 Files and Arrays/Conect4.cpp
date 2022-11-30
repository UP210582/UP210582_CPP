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
char gameArea[6][7] = {{'p', 'r', 'u', 'e', 'b', 'a', '1'},
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
char number[1][7]={'1','2','3','4','5','6','7'};
int x=0;
int y=0;
int z=0;
int w=0;


for (int  row = 0; row < 22; row++)
    {
        for (int col = 0; col < 43; col++)
        {
            
            if (row%3==0 && col%6!=0 || row == 21)
            {
                cout << "¯";
            }
            else if (col%6==0)
            {
                cout << "|";
            }
            else if (row !=0)
            {
                if (row == 1 && col%3==0)
                {
                    cout << number[x][y];
                    y++;
                }
                else if ((row==4|| row==7 || row==10 || row== 13 || row==16 || row ==19) && col%3==0)
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
    w=0;
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