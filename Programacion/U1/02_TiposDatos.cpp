/* 
Date: 15/09/2022
Author: Leonardo Asuencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Type of Data
Last Modification: 15/09/2022
*/

//Library for manage of input and ouput of screen
#include <iostream>
//Library for the use of printf and scanf
#include <stdio.h>

//Use of namespace for avoid el std::
using namespace std;

//Principal Function of type entire
int main (){

    int entero = 4;
    float flotante = 2.565465654654;
    double grande = 2.565465654654;
    char caracter = 64;

    cout << "This program showed the types of data. \n";
    cout << "The number entero is: " << entero << endl;
    cout << "The size of entire is: " << sizeof(entero) << "bytes" << endl;
    cout << "The float number is: " << flotante << endl;
    cout << "The size of the float is: " << sizeof(flotante) << "bytes" << endl;
    cout << "The number double is: " << grande << endl;
    cout << "The size of the double is: " << sizeof(grande) << "bytes" << endl;
    cout << "The character char is: " << caracter << endl;
    cout << "The size of the char is: " << sizeof(caracter) << "byte" << endl;

    cout << "=====================" << endl;

    printf("Using the function printf\n");
    printf("The entire number is": %i \n", entero);
    printf("The float number is": %3.1f \n", flotante);

    //Al ser una funcion debe retornar un valor, en este caso es 0
    return 0;
}
