#include <unistd.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void gotoxy(int, int);
void mainBanner(int,int);
void bannerS(int,int);
void mainBannerAnimate();
void menu(int, int);
void option1(int, int);
void option2(int, int);
int selectChoice(int, int);
void edge(int,int,int);
void board(int,int);

void mainBannerAnimate(){

     for (int i = 0; i < 30; i++)
    {
        mainBanner(35,3+i);
        usleep(100000);
        if (i<29)
        {
            system("clear");
        }
        
       
    }

}

void mainBanner(int x, int y){

    string banner[11][1] = {
        {"                                                                                    "},
        {"                                                                                    "},
        {"     *******   ********   ****    **** ****    **** **********   *******  **********"},
        {"   ********** **********  *****   **** *****   **** ********** ********** **********"},
        {"  ****       ****    **** ******  **** ******  **** ****      ****           **** "},
        {"  ***        ****    **** ****  ****** ****  ****** *******   ***            **** "},
        {"  ****       ****    **** ****   ***** ****   ***** ****      ****           **** "},
        {"   ********** **********  ****    **** ****    **** ********** **********    **** "},
        {"     *******   ********   ****    **** ****    **** **********   *******     **** "},
        {"                                                                                  "},
        {"                                                                                  "},
    };

    string bannerNumber[11][1] = {
        {"     ****"},
        {"   ******"},
        {"  *******"},
        {" ********"},
        {" ****   ***"},
        {"****    ***"},
        {"****    ***"},
        {"*************"},
        {"*************"},
        {"      ****"},
        {"      ****"},
    };

    for (int i = 0; i < 11; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            cout << banner[i][j] << "\x1b[31m" << bannerNumber [i][j]<< "\x1B[0m";
            cout.flush();
        }

    }
}

void bannerS(int x, int y){
    
    string bannerS[9][1]={
        {"                                                                     "},
        {"     ******   ******   ***   *** ***   *** *******   ******  ********"},
        {"   ********* ********  ****  *** ****  *** ******* ********* ********"},
        {"  ****      ***    *** ***** *** ***** *** ****   ****         **** "},
        {"  ****      ***    *** *** ***** ***  **** ****** ****         **** "},
        {"   ********* ********  ***  **** ***   *** ****    *********   **** "},
        {"     ******   ******   ***   *** ***   *** *******   ******    **** "},
        {"                                                                    "},
        {"                                                                    "}};

    string bannerNumberS[9][1]={
        {"    ******"},
        {"   *******"},
        {"  ********"},
        {" ****   ***"},
        {"****    ***"},
        {"************"},
        {"************"},
        {"      ****"},
        {"      ****"}};
    
    for (int i = 0; i < 9; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            cout << bannerS[i][j]<< "\x1b[31m" << bannerNumberS[i][j]<< "\x1B[0m";
            cout << endl;
        }

    }

}

void menu(int x, int y){

    int yellow = 43;
    int white = 37; 
    int color;
    
    string menu[13][1] = {
        {"     Menu    "},
        {"            "},
        {"            "},
        {"            "},
        {"1) Game mode"},
        {"            "},
        {"            "},
        {"2) Rules    "},
        {"            "},
        {"            "},
        {"3) Exit     "},
        {"            "},
        {"            "},
    };

    for (int i = 0; i < 13; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            color = (i==0)?yellow:white;

            cout<< "\x1B[" << color << "m" << menu[i][j]<< "\x1B[0m";
            cout << endl;
        }

    }

}
void option1(int x, int y){

    int yellow = 43;
    int white = 37; 
    int color;

    string option1[13][1] = {
        {"           Game mode         "},
        {"                  "},
        {"                  "},
        {"                  "},
        {"       1) Multi player   "},
        {"                  "},
        {"                  "},
        {"       2) Single player   "},
        {"                  "},
        {"                  "},
        {"To go back to the menu press 0 "},
        {"                  "},
        {"                  "},
    };

    for (int i = 0; i < 13; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            color = (i==0)?yellow:white;

            cout<< "\x1B[" << color << "m" << option1[i][j]<< "\x1B[0m";
            cout << endl;
        }

    }

}
void option2(int x, int y){

    int yellow = 43;
    int white = 37; 
    int color;
    string option2[20][1] = {
        {"OBJECTIVE: "},
        {"                                                                      "},
        {"To be the first player to connect 4 of the same colored discs in a row"},
        {"(either vertically, horizontally, or diagonally)                      "},
        {"                                                                      "},
        {"RULES: "},
        {"                                                                      "},
        {"1.Players must alternate turns,  and only one disc can be  dropped  in"},
        {"each turn.                                                            "},
        {"                                                                      "},
        {"2.On your turn,  drop one of your colored discs from the top  into any"},
        {"of the seven slots.                                                   "},
        {"                                                                      "},
        {"3.The game ends when there is a 4-in-a-row or a stalemate.            "},
        {"                                                                      "},
        {"4.Each player has 21 turns,  if all slots are busy and  none  of  the"},
        {"players has made a 4-in-a-row it is a draft.                          "},
        {"                                                                      "},
        {"                                                                      "},
        {"                   To go back to the menu press 0                     "}};

    for (int i = 0; i < 20; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            color = (i==0)?yellow:(i==5)?yellow:white;

            cout<< "\x1B[" << color << "m" << option2[i][j]<< "\x1B[0m";
            cout << endl;
        }

    }
    
}

int selectChoice(int x, int y){
    
    int choice;
    
    do{
        
        gotoxy(x,y);
        cout << "Please enter your choice:  ";
        cout << "\b";
        cin >> choice;
    }while(choice > 3 || choice < 0 );

    return choice;
}

void edge(int tam,int x, int y){

    gotoxy(x,y);
    for(int i=0;i<tam;i++)
    cout << "\x1B[34m" << "_" << "\x1b[0m";
    cout << "\n";
}

void board(int x, int y){
    char board[25][43];
    char number[1][7] = {'1', '2', '3', '4', '5', '6', '7'};

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
                    cout << "x";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}