/* 
Date: 22/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Muestra del uso del if simple
Last Modification: 22/09/2022
*/

//Libreria para manejo de entradas y salidas de pantalla
#include <iostream>

//Uso del namespace para evitar el std::
using namespace std;

//Funcion principal de tipo entero
int main(){

    int numero;
    int dato;

    cout << "Dame un dato: ";
    cin >> dato;

    cout << "Ingresa un numero entero con el cual comparar el dato: ";
    cin >> numero;
    if (numero > dato){
        cout << "El numero es mayor a dato" << endl;
    }
    if (numero == dato){
        cout << "El numero es igual a dato" << endl;
    }
 if (numero != dato){
        cout << "El numero es diferente a dato" << endl;
    }
 if (numero < dato){
        cout << "El numero es menor a dato" << endl;
    }

    //Ejercicio: utilice las diferentes comparaciones ==, !=, <, >, <=, >=

    //Al ser una funcion debe retornar un valor, en este caso 0
    return 0;
}