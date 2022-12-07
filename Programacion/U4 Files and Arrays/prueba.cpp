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
    int busyRow=-1;
    bool winner = false;
    doBoard();
    selectCol();
    busyRow= checkBusyRow(col);
    if (busyRow==-1){
        cout << "Select other coulum: ";
    }else {
        do{
            setCol(row, col);
            system("clear");
            doBoard();
            cout << endl;
            winner = isWinner(row, col);
            turn++;
        }while(turn <= 42 && winner == false);
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
}


bool isWinner(int row, int col){
    bool isWinner = false;
    int coulum = col, acum = 0;
    int nCol = col + 1;
    int n2Col = col - 1;
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
    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
