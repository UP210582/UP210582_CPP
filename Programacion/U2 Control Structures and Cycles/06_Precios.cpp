/*
Date: 05/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Calculate the price of a purchase
Last Modification: 05/10/2022
*/

// Library for handling screen inputs and outputs
#include <iostream>

// Use of the namespace to avoid the std::
using namespace std;

int main (){

    int producto;
    float precio;
    float calculo=0;
    float total=0;
    int vuelta;

    cout << "Welcome to UxxA \n";

    do
    {
        cout << "Give me the number of products \n";
        cin  >> producto;

        if (producto !=0 and producto >0){

            cout << "Tell me the price of the product \n";
            cin >> precio;

            total +=(precio*producto);
        }

    } while (producto != 0);

    cout << "The total of your purchase is: \n" << total << endl;

    //Being a function, it must return a value in this case 0
    return 0;
}
