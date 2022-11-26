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
int selectedPlay();
bool checkPlay(int, string);
void putMove(int, string, string);
bool win();
int obtainingPlayed();
void cloneBoard();
int getBestPlay(string);

char board[35][35];
char structureConect[7][7]
int turnPlayer = 1;



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