#include <iostream>

using namespace std;

void doBoard();
int selectCol();
int checkBusyRow(int);
void setCol(int, int);
bool isWinner(int,int);

int col, row, turn = 1;
char gameArea[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};


int main()
{   
    
    bool winner = false;
    int row;
    doBoard();
    do{
        selectCol();
        row=checkBusyRow(col);
        if (row==-1){
            cout <<"Select other coulum: ";
        }
        setCol(row, col);
        system ("clear");
        doBoard();
        winner= isWinner(row, col);
        turn++;
    }while (turn <=42&& winner ==false);
    if (winner == true)
    {
        if (turn % 2 == 0)
        {
            cout << "\x1B[38;2;255;151;203m" << "Congrats player 2, you won" << "\x1b[0m" << endl;
        }
        else
        {
            cout << "\x1B[38;2;255;151;203m" << "Congrats player 1, you won" << "\x1b[0m" << endl;
        }
    } else if (winner == false)
        {
            cout << "\x1B[38;2;255;151;203m" << "Tontes ninguno gano :/" << "\x1b[0m" << endl;
        }
 return 0;
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
    cout << "Player  " << turn % 2+1 << endl;
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


bool isWinner(int row, int col){
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
