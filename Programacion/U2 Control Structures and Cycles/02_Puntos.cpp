/* 
Date: 26/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Puntuacion de usuario y bono
Last Modification: 26/09/2022
*/

/*
level: Puntuation
Inaceptable : 0.0
Aceptable: 0.4
Meritorio: 0.6 o más
Escribir un programa que lea la puntuacion del usuario e indique su nivel de rendimiento asi como la cantida de dinero que recibira el usuario
*/

#include <iostream>
#include <ctype.h>

using namespace std;

int main (){
    double punto;
    double monto = 2400;
    double beneficio = 0;

    cout << "What is the user score? ";
    cin >> punto;

//If the score is 0.0

    if(punto == 0.0){
        cout << "Your level is Unacceptable \n";
        beneficio = monto * punto;
            cout << "Your benefit is: $" << beneficio << endl;

//If the score is 0.4

    }
    else if (punto == 0.4){
        cout << "Your level is Acceptable \n";
        beneficio = monto * punto;
            cout << "Your benefit is: $" << beneficio << endl;

//If the score becomes greater than 1, it cancels and asks the user to enter a valid score.

    }
    else if (punto > 1){
        cout << "Please enter a valid score" << endl;
    }

//If the score is greater than or equal to 0.6 but not greater than 1

    else if (punto >= 0.6){
        cout << "Your level is Merit \n";
         beneficio = monto * punto;
             cout << "Your benefit is: $" << beneficio << endl;
    }

//If none of the conditions are met, it will proceed to ask for a valid score

    else {
        cout << "Please enter a valid score" << endl;
    }

//Being a function, it must return a value in this case 0

return 0;
}