/* 
Date: 22/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: obtencion de  imposivos
Last Modification: 22/09/2022
*/

//Library for handling screen inputs and outputs
#include <iostream>

//Use of the namespace to avoid the std::
using namespace std;

//Integer type main function
int main(){
    float montoRenta;
    float improviso;
    float descuento = 0;

//The user is asked for his annual income

    cout << "How much is your annual rent payment? $";
    cin >> montoRenta;

//The improvisation that will be made according to your annual payment is calculated

    if (montoRenta < 10000)
        descuento = 5;  
    else if (montoRenta < 20000)
        descuento = 15;
    else if (montoRenta < 35000)
        descuento = 20;
    else if (montoRenta < 60000)
        descuento = 30;
    else 
        descuento = 45;

    improviso=montoRenta * descuento / 100;

//the total of if improvised and the percentage that it occupies is printed

    cout << "You have to pay: $" << improviso << endl;
    cout << "Your tax is: " << descuento << "%" << endl;

//Being a function it must return a value, in this case 0
    return 0;
}