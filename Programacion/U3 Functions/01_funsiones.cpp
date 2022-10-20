/* Unidad 3. Funciones
   Autor: Luis Ernesto Anaya Tiscareño
   Fecha: 01/09/2022
   Descripción: Muestra la creación y manejo de funciones
*/

/* Funcion:
    tipo nombre(tipo var1, tipo var2,...tipo varn){
        instrucciones;
    }
*/

#include <iostream>

using namespace std;

//Prototipado de funciones
int getMaxVal(int num1, int num2);

//Función principal
int main(){
    int num1, num2;
    int valorMaximo;

    cout << "Dame un número: ";
    cin >> num1;
    cout << "Dame otro número: ";
    cin >> num2;

    cout << "\n ================ \n";
    valorMaximo =getMaxVal(num1, num2);

    cout << "El valor máximo es: " << valorMaximo << endl;
    return 0;
}

int getMaxVal(int num1, int num2){
    int valorMaximo;
    if (num1 > num2){
        valorMaximo = num1;
    }else{
        valorMaximo = num2;
    }
    return valorMaximo;
}