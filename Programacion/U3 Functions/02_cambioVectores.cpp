/*
Date: 27/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Tic Tac Toe
Last Modification: 27/10/2022
*/

//Library for handling screen inputs and outputs
#include <iostream>

// Use of the namespace to avoid the std::
using namespace std;


void Cambio(int num);
void ImprimirCambio(int);

int cantidaddinero[9] = {0};
int denominaciones[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
string billetes[9] = {"$500", "$200", "$100", "$50", "$20", "$10", "$5", "$2", "$1"};


int main()
{
   int money;
   cout << "Give me a money amount: \n";
   cin >> money;
   Cambio(money);
   ImprimirCambio(money);
   return 0;
}

void Cambio(int num)
{
   if (num > 20)
   {
      do
      {
         for (int i = 0; i < 9; i++)
         {
            (num >= denominaciones[i]) ? cantidaddinero[i]++, num -= denominaciones[i] : num;
         }
      } while (num > 0);
   }
   else
   {
      do 
      {
         for (int i = 5; i < 9; i++)
         {
            (num >= denominaciones[i]) ? cantidaddinero[i]++, num -= denominaciones[i] : num;
         }
      } while (num > 0);
   }
}
void ImprimirCambio(int num)
{
   if (num > 0)
   {
      cout << "\nYou've inputted the amount of $" << num << "\nYour exchange: \n";
      if (num > 20)
      {
         for (int i = 0; i < 9; i++)
         {
            cout << billetes[i] << "\t=\t" << cantidaddinero[i] << endl;
         }
      }
      else
      {
         for (int i = 5; i < 9; i++)
         {
            cout << billetes[i] << "\t=\t" << cantidaddinero[i] << endl;
         }
      }
   }
}