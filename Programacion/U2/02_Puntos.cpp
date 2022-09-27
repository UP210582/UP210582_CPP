/* 
Date: 26/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: obtencion de  imposivos
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

    cout << "Cual es la puntuacion del empleado? ";
    cin >> punto;

    if(punto == 0.0){
        cout << "Tu nivel es inaceptable \n";
        beneficio = monto * punto;
            cout << "Tu beneficio  es de: " << beneficio << endl;

    }
    else if (punto == 0.4){
        cout << "Tu nivel es Aceptable \n";
        beneficio = monto * punto;
            cout << "Tu beneficio  es de: " << beneficio << endl;

    }
    else if (punto > 1){
        cout << "Favor de ingresar una puntuacion aceptable" << endl;
    }
    else if (punto >= 0.6){
        cout << "Tu nivel es Meritorio \n";
         beneficio = monto * punto;
             cout << "Tu beneficio  es de: " << beneficio << endl;
    }
    else {
        cout << "Favor de ingresar una puntuacion aceptable" << endl;
    }

return 0;
}