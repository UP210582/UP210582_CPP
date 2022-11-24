/*
Date: 23/11/2022
Authors:    Paulina Jaqueline Alvarez Martinez
            Sofia Calderon Juarez
            Leonardo Ausencio Martinez Torres

Email:  up210374@alumnos.upa.edu.mx
        up210300@alumnos.upa.edu.mx
        up210582@alumnos.upa.edu.mx
Description: Game of Conect 4
Last Modification: 23/11/2022
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

char structureConect[7][7]
int turnsPlayer = 1;



int main (){
    system("clear");
    bool gameover = false;
    int play;
    bool occupiedBox = true;
    int mode;

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
    }
}