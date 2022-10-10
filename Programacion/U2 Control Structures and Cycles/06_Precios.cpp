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

    //Variable Definition
    int producto;
    float precio;
    float calculo=0;
    float total=0;
    int vuelta;

    //welcoming to the store
    cout << "Welcome to UxxA \n";

    do
    {
        //Asking for the quantity of products
        cout << "Give me the number of products \n";
        cin  >> producto;

        if (producto !=0 and producto >0){

            //Asking the price
            cout << "Tell me the price of the product \n";
            cin >> precio;

            //Making the calculation of the purchase by product
            total +=(precio*producto);
        }

    } while (producto != 0);

    //Printing the price of each of the products as well as the total of all products
    cout << "The total of your purchase is: \n" << total << endl;

    //Being a function, it must return a value in this case 0
    return 0;
}
