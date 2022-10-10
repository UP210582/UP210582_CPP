/*
Date: 05/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Conversion Binary to Decimal
Last Modification: 05/10/2022
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    //Defining the variables to use
    int exp,digito;
    double binario, decimal;
    
    //Asking user for number in binary
   cout << "Introduce numero: ";
   cin >> binario;
   exp=0;
   decimal=0;

    //at the moment of giving 0 in the division it goes directly to print the result
   while(((int)(binario/10))!=0)
   {
           digito = (int)binario % 10;
           decimal = decimal + digito * pow(2.0,exp);
           exp++;
           binario=(int)(binario/10);
   }

    //This part prints the result and shows it to you in decimal
   decimal=decimal + binario * pow(2.0,exp);
   cout << endl << "Decimal: " << decimal << endl;
    
    //Being a function, it must return a value in this case 0
    return 0;
}