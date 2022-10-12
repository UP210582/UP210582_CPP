/*
Date: 05/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Multiplication Table
Last Modification: 05/10/2022
*/

//Library for handling screen inputs and outputs
#include <iostream>

//Use of the namespace to avoid the std::
using namespace std;

//Integer type main function
int main (){

    
    int numero;
    int limite;
    int operacion;
    char follow;

    do
    {
        cout << "Give me the number to multiply" << endl;
        cin >> numero;

        cout << "Give me the times I'm going to multiply it" << endl;
        cin >> limite;

        cout << "The multiplication table of: " << numero << " multiplied up: " << limite <<endl;

        for (int i = 1; i <=limite; i++)
        {
            for (int j = 0; j <= 80; j++)
            {
                cout << "-";
            }
            cout<< "\n";
            cout << "|\t"<<i<<"\t|"<<"\tx\t"<<"|\t"<<numero<<"\t|"<<"\t=\t"<<"|\t"<<numero*i<<"\t|\n";
        }   
        for (int p = limite; p <=90; p++)
            {
                cout << "-";
            }
        
        cout << "\n";
        cout <<  "Do you want another multiplication table? Y/N" << endl;
        cin >> follow;

    } while (follow != 'n');
    return 0;
}