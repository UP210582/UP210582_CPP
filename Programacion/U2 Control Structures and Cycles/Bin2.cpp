#include <iostream>

using namespace std;

int main (){

    int binario, resultado, resto=0;
    int digito [99999];

    cout << "introduce el numero en binario" << endl;
    cin >> binario;

    for (int i = 0; i < 10; i++)
    {
       digito[i] = binario % 10;
       binario /= 10;

    }
    
    for (int i = 99998; i >= 0; i--)
    {
        resultado = (resto * 2) + digito[i];
        resto = resultado;
    }

    cout << endl << "El numero en decimal es: " << resultado << endl;

    return 0;
}