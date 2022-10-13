/*
Date: 13/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Math method for getting roots
Last Modification: 13/10/2022
*/

//------------ PREPROCESSOR DIRECTIVES ----------------
#include <iostream>
#include <cmath>
using namespace std;

//---------------------ISSUE---------------------------

// Make a program that uses to biseccion method to get a root of a graph

//------------------ EXTRA FUNCTION ---------------------

double bisection(double num){
    //Equation y=x²+3x+8
    return pow(num,2)-num-12;
}

//------------------ MAIN FUNCTION ---------------------

int main(){
    double a,b,c,ya,yb,yc;
    cout << "Give me the value of (a)";
    cin >> a;
    cout << "Give me the value of (b)";
    cin >> b;
    do
    {
        ya = bisection(a);
        yb = bisection(b);
        if ((yb > 0 && ya < 0) || (ya > 0 && yb < 0))
        {
            c = (ya+yb)/2;
            yc = ya;
            cout << c;
        }
        else{
            cout << "There's no root between those two numbers";
            break;
        }
        
    } while (yc<=-0.01 || yc>=0.01);
    return 0;
}
