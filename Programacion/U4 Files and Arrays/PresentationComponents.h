#include <unistd.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void gotoxy(int, int);
void mainBanner(int,int);
void mainBannerAnimate();

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

void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}