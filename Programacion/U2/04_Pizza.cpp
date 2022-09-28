/*
Date: 28/09/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Pizza Veg and not Veg
Last Modification: 28/09/2022
*/

// Library for handling screen inputs and outputs
#include <iostream>

// Use of the namespace to avoid the std::
using namespace std;

int main()
{

    int pizza;
    int typo;
    int ingredientes = 0;

    // asks the user about which pizza he wants

    cout << "What type of pizza do you want \n";
    cout << "Choose whit 1 and 2 \n";
    cout << "Vegetarian Pizza is 1 \n";
    cout << "Normal Pizza is 2 \n";
    cin >> typo;

    // vegetarian pizza

    if (typo == 1)
    {
        cout << "You select a Vegetarian Pizza \n";
        cout << "Choose a ingredient \n";
        cout << "You can chose pepper or tofu \n";
        cout << "Choose whit 1 and 2 \n";
        cout << "Pepper is 1 \n";
        cout << "Tofu is 2 \n";
        cin >> ingredientes;

        // vegetarian pizza ingredients

        if (ingredientes == 1)
        {
            cout << "You choose pepper \n";
            cout << "And your pizza include Pepper, Soya cheese and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 2)
        {
            cout << "You choose Tofu \n";
            cout << "And your pizza include Tofu, Soya cheese and Tomato sauce \n";
            cout << "\n";
        }
    }

    // regular Pizza

    if (typo == 2)
    {
        cout << "You select a Normal Pizza \n";
        cout << "Choose a ingredient \n";
        cout << "You can chose pepperoni, ham or salmon \n";
        cout << "Choose whit 1, 2, 3 \n";
        cout << "Pepperoni is 1 \n";
        cout << "Ham is 2 \n";
        cout << "Salmon is 3 \n";
        cout << "\n";
        cin >> ingredientes;

        // regular pizza ingredients

        if (ingredientes == 1)
        {
            cout << "You choose pepperoni \n";
            cout << "And your pizza include Pepperoni, mozarella and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 2)
        {
            cout << "You choose ham \n";
            cout << "And your pizza include ham, mozarella and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 3)
        {
            cout << "You choose salmon \n";
            cout << "And your pizza include salmon, mozarella and Tomato sauce \n";
            cout << "\n";
        }
    }

    // message after assembling your pizza
    cout << "your pizza will be ready in less than an eagle sings \n";
    cout << "THANK YOU FOR visiting Pizzas Upa";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    return 0;
}
