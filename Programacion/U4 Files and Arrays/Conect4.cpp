/*
Date: 23/11/2022
Authors:    Paulina Jaqueline Alvarez Martinez
            Sofia Calderon Juarez
            Leonardo Ausencio Martinez Torres

Email:  up210374@alumnos.upa.edu.mx
        up210300@alumnos.upa.edu.mx
// used bookstores
#include <iostream>
#include <unistd.h>
Last Modification: 24/11/2022
Last Modification: 24/11/2022
*/

// used bookstores
#include <iostream>

// used bookstores
#include <iostream>

// used bookstores
#include <iostream>

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
void setCol(int, int, string, string);
bool isWinner(int, int, string);
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
    
    int gameType = 1;
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
                    col = selectColPC();
                }
                else
                {
                    col = selectCol();
                }
            }
            row = checkBusyRow(col, BOARD);
            if (row == -1)
            {
        cout << "Please, select other coulum: ";
            }
            else
            {
                setCol(busyRow, col, BOARD, PERSON);
                system("clear");
<<<<<<< HEAD
                doBoard();
                cout << endl;
                winner = isWinner(row, col, BOARD);
                turn++;
            }
=======
        doBoard();
        cout << endl;
                winner = isWinner(BOARD);
        turn++;
    }
>>>>>>> 48726d7dfe2e796af594f44b2b85438e9cf796ff
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

int checkBusyRow(int col, string board)
{
    if (board == BOARD)
    {
<<<<<<< HEAD
        for (int row = 5; row >= 0; row--)
=======
        for (int row = 5; row > 0; row--)
    {
        if (gameArea[row][col] == ' ')
>>>>>>> 48726d7dfe2e796af594f44b2b85438e9cf796ff
        {
            return row;
        }
    }
    }
    else if (board == IMGBOARD)
    {
        for (int row = 5; row >= 0; row--)
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

bool isWinner(int row, int col, string board){
   if (board==BOARD){
    bool isWinner = false;
    int acum = 1;
    int nCol = col + 1;
    int n2Col = col - 1;
    int nRow = row + 1;
    int n2Row = row - 1;
    int pRow=row-1;
    int pCol=col+1;
    int n1Row=row+1;
    int n1Col=col-1;
    int n3Row=row-1;
    int n3Col=col-1;
    int n4Row=row+1;
    int n4Col=col+1;
    
    //horizontal
    while (gameArea[row][col] == gameArea[row][nCol])
    {
        acum++;
        nCol++;
    }
    while (gameArea[row][col] == gameArea[row][n2Col])
    {
        acum++;
        n2Col--;
    }
    
    //vertical
    while (gameArea[row][col] == gameArea[nRow][col])
    {
        acum++;
        nRow++;
    }
    while (gameArea[row][col] == gameArea[n2Row][col])
    {
        acum++;
        n2Row--;
    }
    //diagonales
    while (gameArea[row][col] == gameArea[pRow][pCol])
    {
        acum++;
        pRow--;
        pCol++;
        
    }
    while (gameArea[row][col] == gameArea[n1Row][n1Col])
    {
        acum++;
        n1Row++;
        n1Col--;
    }
    while (gameArea[row][col] == gameArea[n3Row][n3Col])
    {
        acum++;
        n2Row--;
        n2Col--;
    }
    while (gameArea[row][col] == gameArea[n4Row][n4Col])
    {
        acum++;
        n3Row++;
        n3Col++;
    }
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
   }else if (board==IMGBOARD){
     bool isWinner = false;
    int acum = 1;
    int nCol = col + 1;
    int n2Col = col - 1;
    int nRow = row + 1;
    int n2Row = row - 1;
    int pRow=row-1;
    int pCol=col+1;
    int n1Row=row+1;
    int n1Col=col-1;
    int n3Row=row-1;
    int n3Col=col-1;
    int n4Row=row+1;
    int n4Col=col+1;
    
    //horizontal
    while (gameArea[row][col] == gameArea[row][nCol])
    {
        acum++;
        nCol++;
    }
    while (gameArea[row][col] == gameArea[row][n2Col])
    {
        acum++;
        n2Col--;
    }
    
    //vertical
    while (gameArea[row][col] == gameArea[nRow][col])
    {
        acum++;
        nRow++;
    }
    while (gameArea[row][col] == gameArea[n2Row][col])
    {
        acum++;
        n2Row--;
    }
    //diagonales
    while (gameArea[row][col] == gameArea[pRow][pCol])
    {
        acum++;
        pRow--;
        pCol++;
        
    }
    while (gameArea[row][col] == gameArea[n1Row][n1Col])
    {
        acum++;
        n1Row++;
        n1Col--;
    }
    while (gameArea[row][col] == gameArea[n3Row][n3Col])
    {
        acum++;
        n2Row--;
        n2Col--;
    }
    while (gameArea[row][col] == gameArea[n4Row][n4Col])
    {
        acum++;
        n3Row++;
        n3Col++;
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
   return false;
}


int selectColPC()
{
    int busyRow = -1;
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
        row = checkBusyRow(col, BOARD);
    } while (row !=-1);
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
            row=checkBusyRow(col, IMGBOARD);
            if (row== -1){
                setCol(col, row, IMGBOARD, PC);
                winner = isWinner (row, col, IMGBOARD);
            }
            cloneBoard();
        } while (col <= 7 && winner == false );
    } 
    else if (player == PERSON)
    {
        do
        {
            col++;
            row=checkBusyRow(col, IMGBOARD);
            if (row!=-1){
                setCol(col, row, IMGBOARD, PERSON);
                winner = isWinner(row, col, IMGBOARD);
            }
            cloneBoard();
        } while (col <= 7 && winner == false);
    }
    if (col >= 8){
        col= -1;
    }
    return col;
}
