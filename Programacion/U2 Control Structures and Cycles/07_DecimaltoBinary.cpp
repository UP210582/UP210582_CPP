/*
Date: 05/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Conversion decimal to Binary
Last Modification: 05/10/2022
*/

#include <iostream>

using namespace std;

int main (){

    //Variable Definition
    int num;
    int decimal;
    string resultado;

    //Asking the user for the number in decimal
    cout << "Give me the number in decimal: \n";
    cin >> num, decimal;
    while (num != 0)
    {
        //Calculation of the number to convert it to binary
        resultado=(num%2==0)?"0"+resultado:"1"+resultado;
        num /= 2;
    }
    
    //printing the result in binary
    cout << "Result : " << resultado << endl;

    //Being a function, it must return a value in this case 0
    return 0;
}