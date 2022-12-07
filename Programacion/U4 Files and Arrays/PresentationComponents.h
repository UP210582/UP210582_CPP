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

void mainBannerAnimate(){

     for (int i = 0; i < 30; i++)
    {
        mainBanner(35,3+i);
        usleep(200000);
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

    string menu[13][1] = {
        {"     Menu   "},
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
            cout << menu[i][j];
            cout << endl;
        }

    }

}
void option1(int x, int y){

    string option1[13][1] = {
        {"     Game mode    "},
        {"                  "},
        {"                  "},
        {"                  "},
        {"1) Single player  "},
        {"                  "},
        {"                  "},
        {"2) Multi player   "},
        {"                  "},
        {"                  "},
        {"3) Exit           "},
        {"                  "},
        {"                  "},
    };

    for (int i = 0; i < 13; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            cout << option1[i][j];
            cout << endl;
        }

    }

}
void option2(int x, int y){

    string option1[13][1] = {
        {"OBJECTIVE:                                                            "},
        {"                  "},
        {"To be the first player to connect 4 of the same colored discs in a row"},
        {"(either vertically, horizontally, or diagonally)                      "},
        {"                                                                      "},
        {"RULES:                                                                "},
        {"                                                                      "},
        {"1.Players must alternate turns, and only one disc can be dropped in each turn.                 "},
        {"2.On your turn, drop one of your colored discs from the top into any of the seven slots.  "},
        {"3.The game ends when there is a 4-in-a-row or a stalemate.                 "},
        {"4.Each player has 21 turns, if all slots are busy and none of the players has made a 4-in-a-row it is a draft                 "},
        {"3) Exit           "},
        {"                  "},
        {"                  "},
    };

    for (int i = 0; i < 13; i++)
    {  
        gotoxy(x,y+i);
        for (int j = 0; j < 1; j++)
        {   
            cout << option1[i][j];
            cout << endl;
        }

    }
    gotoxy(x,y);
    cout << "OBJECTIVE: \n\n";
    cout << "To be the first player to connect 4 of the same colored discs in a row \n (either vertically, horizontally, or diagonally)\n\n";
    cout << "HOW TO PLAY:\n\n";
    cout << " 1. First, decide who goes first and what color each player will have.\n 2. Players must alternate turns, and only one disc can be dropped in each turn.\n 3. On your turn, drop one of your colored discs from the top into any of the seven slots.\n 4. The game ends when there is a 4-in-a-row or a stalemate. 5. The starter of the previous game goes second on the next game.";
}

int selectChoice(int x, int y){
    
    int choice;
    gotoxy(x,y);
    cout << "Please enter your choice: ";
    cin >> choice;

    if (choice > 4 || choice <=0)
    {
        system("clear");
        cout << "Please enter your choice: ";
        cin >> choice;
    }
    return choice;
}

void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}