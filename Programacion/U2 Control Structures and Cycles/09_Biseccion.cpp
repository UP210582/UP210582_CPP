/*
Date: 13/10/2022
Author: Leonardo Ausencio Martinez Torres.
Email: up210582@alumnos.upa.edu.mx
Description: Metodo de bisección.

Problem (Spanish)
Hacer el metodo de la bisección de y=x^2 - x - 12 en un margen de 0.01 al -0.01
*/

// Library for input and output management.
#include <iostream>
#include <cmath>

// Library to be able to print only selected digits
#include <iomanip>

// Use of namespace to avoid std::
using namespace std;
// Function to solve the equation
float resolverEcuacion(float numero)
{
    return (pow(numero, 2) - numero - 12);
}

// Function to print the line of -
int imprimirlinea()
{
    for (int i = 0; i < 161; i++)
    {
        cout << "-";
    }
    cout << "\n";
    return 0;
}

int main()
{
    // Declare the variables.
    int interador = 1;
    int solucion = 1;
    float margen_error = 0.00001;
    float a, b, c, ya, yb, yc;

    // Ask the user for the range
    cout << "Enter the value A: ";
    cin >> a;
    cout << "Enter the value B: ";
    cin >> b;

    // Print table header
    imprimirlinea();
    cout << "| Interdor \t| a \t\t\t| b \t\t\t| c \t\t\t| y(a)\t\t\t| y(b)\t\t\t| y(c)\t\t\t| \n";
    imprimirlinea();

    do
    {
        // Obtain point c and Y(a), Y(b), Y(c)
        c = (a + b) / 2;
        ya = resolverEcuacion(a);
        yb = resolverEcuacion(b);
        yc = resolverEcuacion(c);
        // Print the results in a table
        cout << "| " << interador << "\t\t| " << fixed << setprecision(8) << a << "\t\t| " << b << "\t\t| " << c << "\t\t| " << ya << "\t\t| " << yb << "\t\t| " << yc << "\t\t| \n";
        imprimirlinea();

        // If you select which half to grab to return to get the point c and Y(a), Y(b), Y(c)
        if ((ya * yc) < 0)
        {
            b = c;
        }
        else {
            a=c;
        }
        if (a==b){
            solucion = 0;
            break;
        }
        /*  Metodo de clase
        else if ((yc * yb) < 0)
        {
            a = c;
        }
        else // If to prevent infinite cycling
        {
            solucion = 0;
            break;
        }
        */
        interador++;
    } while ( abs(yc)>= margen_error);

    // Print the root if there is
    if (solucion != 0)
    {
        cout << "The root is :" << c;
        cout << "\n";
    }
    else
    {
        cout << "There is no root in that range. \n";
    }
    return 0;
}