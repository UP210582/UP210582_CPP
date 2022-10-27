/*
Date: 27/10/2022
Author: Leonardo Ausencio Martinez Torres
Email: up210582@alumnos.upa.edu.mx
Description: Tic Tac Toe
Last Modification: 27/10/2022
*/

#include <iostream>
#include<stdio.h>

using namespace std;
 
void obtenerCambio(int);

void imprimirCambio(int);

int denominacions[9]={500,200,100,50,20,10,5,2,1};

int cantidadBilletes[9]
int residuo=0;

for (int deno = 0; deno < 9; deno++)
{
    residuo=(deno==0)?monto:residuo;
    cantidadBilletes[deno]=residuo/denominacions[deno];
    residuo=residuo%denominacions[deno];
}

    tipo=(posicion<5)?"Billetes":"Monedas";
    cout<<tipo<<"de $" << denominacions[0]<<":"<<cantidadBilletes[0];

