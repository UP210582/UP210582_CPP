/* 
Date: 28/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Pass for games
Last Modification: 28/09/2022
*/

//Library for handling screen inputs and outputs
#include <iostream>

//Use of the namespace to avoid the std::
using namespace std;

int main(){
    int edad;
    int precio;

//question to know the age and capture it in a variable

    cout << "How old are you ";
    cin >> edad;

//process to calculate the price of admission to the park

    if (edad < 4)
        precio = 0;  
    else if (edad >= 4 && edad <= 18)
        precio = 5;
    else if (edad > 18)
        precio = 10;

//exit message about price and welcoming users

    cout << "You have to pay: $" << precio << endl;
    cout << "Welcome to Los Pollos Hermanos Games" << endl;

//Being a function, it must return a value in this case 0

    return 0;
}