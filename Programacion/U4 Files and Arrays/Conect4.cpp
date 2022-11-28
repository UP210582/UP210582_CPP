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


//used bookstores
#include <iostream>

using namespace std;

void doBoard();
int selectMove();
bool checkBusyBox(int, string);
void setMove(int, string, string);
bool isWinnner(string);
int obtainingPlayed();
void cloneBoard();
int getBestPlay(string);

char board[35][35];
char structureConect[7][7]
int move, turn=1;
const string BOARD = "Real";
const string IMGBOARD = "Imaginary";
const string PC = "Machine";
const string PERSON = "Human";



int main (){
    system("clear");
    bool gameover = false;
    int play;
    bool occupiedBox = true;
    int mode;

    void doBoard();
    /*
    cout << "Welcome to Conect 4" << endl;
    cout << "Choose your game mode" << endl;
    cout << "1 SinglePlayer" << endl;
    cout << "2 Multiplayer" << endl;
    cin >> mode;
    
    if (mode == 1)
    {
        do
        {
            system("clear");
            if (turno)
            {
                doBoard()
                selectedPlay()

            }
        } while (/* condition */);
    // } */

}

void doBoard(){

    int row;
    int col;

    for (int  row = 0; row < 35; row++)
    {
        for (int col = 0; col < 35; col++)
        {
            if (col%4==0 )
            {
                cout << "|";
            }
            else if (row%4==0 )
            {
                cout << "_";
            }
            else
            {
                cout << "x";
            }   
            
        }
        
    }
}

int selectMove(){
    int move;
    cout << "Choose a column: ";
    cin >> move;
    while (move < 1 || move > 42){
        cout << "This is incorrect, choose another column: ";
        cin >> move;
    }
    return move;
}
bool checkBusyBox(int move, string board){
    int row, col;
    bool busyBox=false;
    if (move==1||move==2||move==3||move==4||move==5||move==6||move==7){
        row=1;
    }else if (move==8||move==9||move==10||move==11||move==12||move==13||move==14){
        row=4;
    }else if (move==15||move==16||move==17||move==18||move==19||move==20||move==21){
        row=7;
    }else if(move==22||move==23||move==24||move==25||move==26||move==27||move==28){
        row=10;
    }else if (move==29||move==30||move==31||move==32||move==33||move==34||move==35){
        row=13;
    }else if (move==36||move==37||move==38||move==39||move==40||move==41||move==42){
        row=16;
    }
    if (move==||move==||move==||move==||move==|move==||move==){
        col=
    }else if (move==||move==||move==||move==||move==||move==||move==){
        col=
    }else if (move==||move==||move==||move==||move==||move==||move==){
        col=
    }else if (move==||move==||move==||move==||move==||move==||move==){
        col=
    }else if (move==||move==||move==||move==||move==||move==||move==){
        col=
    }else if (move==||move==||move==||move==||move==||move==||move==){
        col=
    }
    if (board == BOARD)
    {
        if (position[row][col] == '0' || position[row][col] == 'O')
        {
            return true;
        }
    }
    else if (board == IMGBOARD)
    {
        if (positionIMG[row][col] == '0' || positionIMG[row][col] == 'O')
        {
            return true;
        }
    }
    return busyBox;    
}

void setMove(int move, string board, string player){

    char moveValue;
    int row=0, col=0;
    if (turn % 2 == 0)
        moveValue = '0';
    else
        moveValue = 'O';

    if (board == BOARD)
    {
        position[row][col] = moveValue;
    }
    else if (board == IMGBOARD)
    {
        if (player == PERSON)
        {
            moveValue = 'O';
        }
        else if (player == PC)
        {
            moveValue = '0';
        }
        positionIMG[row][col] = moveValue;
    }
}

bool isWinner(string board){
    if (board==BOARD){
        
    }
}
int selectMovePC()
{
    bool boxBusy = false;
    int play;
    srand(time(NULL));
    play = getBetterPlay(PC);
    if (play != -1)
    {
        return play;
    }
    play = getBetterPlay(PERSON);
    if (play != -1)
    {
        return play;
    }
    do
    {
        play = 1 + rand() % 9;
        boxBusy = checkBusyBox(play,BOARD);
    }while (boxBusy == true);
    return play;
}

void cloneBoard(){
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            positionIMG[row][col] = position[row][col];
        }
    }
}
