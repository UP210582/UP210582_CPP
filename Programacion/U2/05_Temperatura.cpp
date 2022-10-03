/*
Date: 03/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Temperature
Last Modification: 03/10/2022
*/

// Library for handling screen inputs and outputs
#include <iostream>

// Use of the namespace to avoid the std::
using namespace std;

int main(){
    float temperatura;
    int contador = 1;
    float tempeAcum = 0;
    int temperatura_min = 9999, temperatura_max = -9999;

    //Requesting the user's temperature
    cout << "Welcome to Farmacias UPA´s \n";

    do
    {
        cout << "Give me a temperature" << endl;
        cin >> temperatura;
        tempeAcum +=temperatura;

        contador ++;
        if (temperatura <= temperatura_min)
        {
            temperatura_min=temperatura;
        }
        if (temperatura >= temperatura_max)
        {
            temperatura_max=temperatura;
        }
    } while (contador <=6);
    //printing the average, maximum temperature and minimum temperature
    cout << "Today's average temperature is: " << tempeAcum/6 <<endl;
    cout << "The minimum temperature is: " << temperatura_min<< endl;
    cout << "The maximum temperature is: " << temperatura_max << endl;
    
    //Being a function, it must return a value in this case 0
    return 0;
}