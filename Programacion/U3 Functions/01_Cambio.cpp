/*
Date: 26/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Change of an amount of money into bills and coins
Last Modification: 26/10/2022
*/

//Library for handling screen inputs and outputs
#include <iostream>

//Use of the namespace to avoid the std::
using namespace std;

void obtenerCambio(int);

void imprimirCambio(int);

int quinientos = 0, docientos = 0, cien = 0, cincuenta = 0, veinte = 0, diez = 0, cinco = 0, dos = 0, uno = 0;

int main()
{
    int dinero;
    cout << "Give me the amount of money: ";
    cin >> dinero;
    obtenerCambio(dinero);
    imprimirCambio(dinero);
    return 0;
}
void obtenerCambio(int dinero)
{
    do
    {
        ((dinero - 500) >= 0) ? quinientos++, dinero -= 500 
            : ((dinero - 200) >= 0) ? docientos++, dinero -= 200 
                : ((dinero - 100) >= 0) ? cien++, dinero -= 100 
                    : ((dinero - 50) >= 0) ? cincuenta++, dinero -= 50 
                        : ((dinero - 20) >= 0) ? veinte++, dinero -= 20 
                            : ((dinero - 10) >= 0) ? diez++, dinero -= 10 
                                : ((dinero - 5) >= 0) ? cinco++, dinero -= 5 
                                    : ((dinero - 2) >= 0) ? dos++, dinero -= 2 
                                        : ((dinero - 1) >= 0) ? uno++, dinero -= 1 
                                            : uno;
    } while (dinero > 0);
}
void imprimirCambio(int dinero)
{
    cout << "The change of $" << dinero << " is: \n";
     cout << "$500 bill: " << quinientos << endl;
     cout << "$200 bill: " << docientos << endl;
     cout << "$100 bill: " << cien << endl;
     cout << "$50 bill: " << cincuenta << endl;
     cout << "$20 bill: " << veinte << endl;
     cout << "$10 coin: " << diez << endl;
     cout << "$5 coin: " << cinco << endl;
     cout << "$2 coin: " << dos << endl;
     cout << "$1 coin: " << uno << endl;
}