#include <iostream>

using namespace std;

void doBoard();
int selectCol();
int checkBusyRow(int, string);
void setCol(int, int, string, string);
bool isWinner(int,int, string);
int getColPC();
void cloneBoard();
int getBetterCol(string);
int selectColPC();


int col, row, turn = 1;
char gameArea[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char gameAreaIMG[6][7]= {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

const string PC="Machine";
const string PERSON="Person";
const string BOARD="Real";
const string IMGBOARD="Imaginary";


int main()
{   
    bool winner = false;
    int row;
    int mood;
    cout << "       Menu        " << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs PC" << endl;
    cout << "Select mood: ";
    cin >> mood;
    doBoard();
    do{
        if (mood ==1){
        col= selectCol();
        }else {
            if (turn %2 ==0){
                col= selectColPC();
            }else {
                col=selectCol();
            }
        }
        row=checkBusyRow(col, BOARD);
        if (row==-1){
            cout <<"Select other coulum: ";
        }
        setCol(row, col, BOARD, PERSON);
        system ("clear");
        doBoard();
        winner= isWinner(row, col, BOARD);
        turn++;
    }while(turn <=42 && winner == false);
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

int checkBusyRow(int col, string board)
{
    if (board == BOARD){
         for (int row = 5; row > 0; row--)
        {
        if (gameArea[row][col] == ' ')
        {
            return row;
        }
        }
    }else if (board==IMGBOARD){
         for (int row = 5; row > 0; row--)
        {
        if (gameArea[row][col] == ' ')
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
    if (board == BOARD){
        gameArea[row][col] = value;
    }else if (board == IMGBOARD){
        if (player == PERSON){
            value = 'O';
        }else if (player == PC) {
            value ='0';
        }
        gameArea[row][col] = value;
    }
}

bool isWinner(int row, int col, string board){
if (board == BOARD){
    bool isWinner = false;
    int acum = 1;
    int arow = 1;
    int nCol = col + 1;
    int n2Col = col - 1;
    int nRow = row + 1;
    int n2Row = row - 1;
    int NRow = row - 1;
    int NCol = col - 1;
    int N1Row = row + 1;
    int N1Col = col + 1;
    int n1Row = row - 1;
    int n1Col = col + 1;
    int N2Row = row + 1;
    int N2Col = col - 1;
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
    if (acum > 3)
        return true;
    acum = 1;
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
    if (acum > 3)
        return true;
    acum = 1;
    //diagonales
    while (gameArea[row][col] == gameArea[n1Row][n1Col])
    {

        acum++;
        n1Col++;
        n1Row--;
        
    }
    while (gameArea[row][col] == gameArea[N2Row][N2Col])
    {

        acum++;
        N2Col--;
        N2Row++;
    }
        if (acum > 3)
        return true;
    acum = 1;
    while (gameArea[row][col] == gameArea[NRow][NCol])
    {

        acum++;
        NCol--;
        NRow--;
    }
    while (gameArea[row][col] == gameArea[N1Row][N1Col])
    {

        acum++;
        N1Col++;
        N1Row++;
    }

    if (acum == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}else if (board==BOARD){
    bool isWinner = false;
    int acum = 1;
    int arow = 1;
    int nCol = col + 1;
    int n2Col = col - 1;
    int nRow = row + 1;
    int n2Row = row - 1;
    int NRow = row - 1;
    int NCol = col - 1;
    int N1Row = row + 1;
    int N1Col = col + 1;
    int n1Row = row - 1;
    int n1Col = col + 1;
    int N2Row = row + 1;
    int N2Col = col - 1;
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
    if (acum > 3)
        return true;
    acum = 1;
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
    if (acum > 3)
        return true;
    acum = 1;
    //diagonales
    while (gameArea[row][col] == gameArea[n1Row][n1Col])
    {

        acum++;
        n1Col++;
        n1Row--;
        
    }
    while (gameArea[row][col] == gameArea[N2Row][N2Col])
    {

        acum++;
        N2Col--;
        N2Row++;
    }
        if (acum > 3)
        return true;
    acum = 1;
    while (gameArea[row][col] == gameArea[NRow][NCol])
    {

        acum++;
        NCol--;
        NRow--;
    }
    while (gameArea[row][col] == gameArea[N1Row][N1Col])
    {

        acum++;
        N1Col++;
        N1Row++;
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

int selectColPC(){
    int row=-1;
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
    } while (row == true);
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
    int row=-1;
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
            if (row== -1){
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
