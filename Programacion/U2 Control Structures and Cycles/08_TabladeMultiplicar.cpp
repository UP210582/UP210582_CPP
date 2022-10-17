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

    //A do to ask if you want another table
    do
    {
        //Asking the number to multiply
        cout << "Give me the number to multiply" << endl;
        cin >> numero;
        
        //Asking the times to multiply
        cout << "Give me the times I'm going to multiply it" << endl;
        cin >> limite;

        //printing the title of the table where the amount of times and the number are specified
        cout << "The multiplication table of: " << numero << " multiplied up: " << limite <<endl;

        //A for to be printing each row
        for (int i = 1; i <=limite; i++)
        {
            //A nested for to print the rows
            for (int j = 0; j <= 80; j++)
            {
                cout << "-";
            }
            //Information that will go inside each row and column
            cout<< "\n";
            cout << "|\t"<<i<<"\t|"<<"\tx\t"<<"|\t"<<numero<<"\t|"<<"\t=\t"<<"|\t"<<numero*i<<"\t|\n";
        }   
        //A for to be able to close the table
        for (int p = limite; p <=88; p++)
            {
                cout << "-";
            }
        //Ask to generate another table
        cout << "\n";
        cout <<  "Do you want another multiplication table? Y/N" << endl;
        cin >> follow;

    } while (follow != 'n');

    //Being a function, it must return a value in this case 0
    return 0;
}