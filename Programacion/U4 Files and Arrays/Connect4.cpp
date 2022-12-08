/*
Unit 4. Files and Arrays
Date: 23/11/2022
Last Modification: 07/12/2022
Authors:Paulina Jaqueline Alvarez Martinez
        Sofia Calderon Juarez
        Leonardo Ausencio Martinez Torres

Email:  up210374@alumnos.upa.edu.mx
        up210300@alumnos.upa.edu.mx
        up210582@alumnos.upa.edu.mx

Decription: Program to play connect 4.
*/


//Library for output and input of the screen
#include <iostream>
//LIbrary for the use of printf and scanf
#include <stdio.h>
//Library to generate random numbers
#include <time.h>
//
#include <unistd.h>
//Library created to print the components of front end
#include "PresentationComponents.h"
 
//Use of namespace to avoid the use of std::
using namespace std;
 
//Function prototype
void doBoard(int,int);
int selectCol(int,int);
int checkBusyRow(int, string);
void setCol(int, int, string, string);
bool isWinner(int,int, string);
int getColPC();
void cloneBoard();
int getBetterCol(string);
int selectColPC();
//void displayWinner();
void connect4(int);
char askKeepPlaying(int, int);
void message(int, int, int);


int col;
int row;
int turn = 2;
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


//Connect 4 game

//Main function integer type
int main(){
    
    int choice;

    do
    {
        mainBannerAnimate();
        system("clear");
        bannerS(45, 5);
        edge(79, 47, 14);
        menu(77, 17);
        edge(79, 47, 30);
        choice = selectChoice(70, 35);
        if (choice == 1)
        {
            system("clear");
            bannerS(45, 5);
            edge(79, 47, 14);
            option1(68, 17);
            edge(79, 47, 30);
            choice = selectChoice(70, 35);
            if (choice == 1 || choice == 2)
            {   
                
                system("clear");
                bannerS(45, 5);
                edge(79, 47, 14);
                connect4(choice);
                
            }
          
        }
        else if (choice == 2)
        {
            system("clear");
            bannerS(45, 5);
            edge(79, 47, 14);
            option2(51, 17);
            edge(79, 47, 39);
            choice = selectChoice(70, 44);
        }

    } while (choice == 0 && choice != 3);

    if (choice==3)
    {
       mainBannerAnimate();
       system("clear");
       gotoxy(60, 20);
       cout << "\x1b[35m"
            << "Thanks for playing this game, hope you enjoy it!"
            << "\x1b[0m";
       gotoxy(60, 25);
       cout << "\x1b[35m"
            << "             See you soon ;D                    "
            << "\x1b[0m";
       gotoxy(0, 40);
       cout << endl;
    }


    return 0;
}


void doBoard(int x, int y){
   
    char board[25][43];
    char number[1][7] = { '1','2','3','4','5','6','7'};
    int z = 0;
    int w = 0;
    int color = 37;

    for (int i = 0; i < 1; i++)
    {
        gotoxy(x-2, y-2+ i);
        for (int j = 0; j < 7; j++)
        {
            cout << "     ";
            cout << number[i][j];
            cout << "";
        }
    }

    cout << "\n"
         << endl;

    for (int row = 0; row < 25; row++)
    {
        gotoxy(x, y + row);
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
                    color = (gameArea[z][w] == '0')?31
                        :(gameArea[z][w]=='O')?33:37;
                
                    cout << "\x1B[1;" << color <<"m" << gameArea[z][w] << "\x1B[0m";
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


int selectCol(int x, int y)
{   
    gotoxy(x,y);
    cout << "                   Player " << turn % 2+1 << endl;
    gotoxy(x,y+1);
    cout << "              Choose a column: ";
    cin >> col;
    col--;
    while (col < 0 || col > 6)
    {   
        gotoxy(x,y+1);
        cout << "This is incorrect, choose another column: ";
        cin >> col;
    }
    return col;
}

int checkBusyRow(int col, string board)
{
    if (board == BOARD){
         for (int row = 5; row >= 0; row--)
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
    if (board==BOARD)
    {
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

void message(int x, int y){

    int num;
    srand(time(NULL));
    num = 1 + rand() % 7;

    if (num==1)
    {   
        gotoxy(x,y);
        cout << "\x1b[32m" <<"Keep going!" << "\x1b[0m";
    }
    else if (num==2)
    {   
        gotoxy(x,y);
        cout << "\x1b[32m" <<"Pro Tip: Stay in the middle"<< "\x1b[0m";
    }
    else if (num==3)
    {   
        gotoxy(x,y);
        cout << "\x1b[32m" << "Is that your best move?"<< "\x1b[0m";
    }
    else if (num==4)
    {   
        gotoxy(x,y);
        cout << "\x1b[32m" <<"Remember: Block your apponent"<< "\x1b[0m";
    }
    else if (num==5)
    {   
        gotoxy(x,y);
        cout << "\x1b[32m" << "Think twice before you place your move"<< "\x1b[0m";
    }
    else if (num==6)
    {
        gotoxy(x,y);
        cout << "\x1b[32m" << "Are you having fun?"<< "\x1b[0m";
    }
    else if (num==7)
    {
        gotoxy(x,y);
        cout << "\x1b[32m" << "Do not give up!"<< "\x1b[0m";
    }
   
}

void connect4(int choice){

    bool winner = false;
    int row;
    doBoard(50, 20);
    edge(79, 47, 47);
    do
    {
        if (choice == 1)
        {
            col = selectCol(63, 50);
        }
        else
        {
            if (turn % 2 == 0)
            {
                col = selectColPC();
            }
            else
            {
                col = selectCol(63, 50);
            }
        }
        row = checkBusyRow(col, BOARD);
        if (row == -1)
        {
            gotoxy(63, 51);
            cout << "Select another colum: ";
        }
        setCol(row, col, BOARD, PERSON);
        system("clear");
        bannerS(45, 5);
        edge(79, 47, 14);
        if(choice==1){

            gotoxy(75,17);
            cout << "\x1B[43m" << "Game mode: Multi player" << "\x1B[0m";
        }
        else
        {   
            gotoxy(75,17);
            cout << "\x1B[43m" << "Game mode: Single player" << "\x1B[0m";
        }
        doBoard(50, 22);
        message(100,30);
        edge(79, 47, 47);
        winner = isWinner(row, col, BOARD);
        turn++;
    } while (turn <= 42 && winner == false);
    if (choice == 1)
    {
        if (winner == true)
        {
            if (turn % 2 == 0)
            {
                gotoxy(70, 50);
                cout << "\x1B[33m"
                     << "Congrats player 2, you won!"
                     << "\x1b[0m" << endl;
            }
            else
            {
                gotoxy(70, 50);
                cout << "\x1B[31m"
                     << "Congrats player 1, you won!"
                     << "\x1b[0m" << endl;
            }
        }
        else if (winner == false)
        {
            gotoxy(70, 50);
            cout << "\x1B[35m"
                 << "             Draft :/"
                 << "\x1b[0m" << endl;
        }
    }
    else
    {
        if (winner == true)
        {
            if (turn % 2 == 0)
            {
                gotoxy(70, 50);
                cout << "\x1B[33m"
                     << "Congrats player 2, you won!"
                     << "\x1b[0m" << endl;
            }
            else
            {
                gotoxy(70, 50);
                cout << "\x1B[31m"
                     << "Ups:(, The machine beat you."
                     << "\x1b[0m" << endl;
            }
        }
        else if (winner == false)
        {
            gotoxy(70, 50);
            cout << "\x1B[35m"
                 << "            Draft :/"
                 << "\x1b[0m" << endl;
        }
    }
}